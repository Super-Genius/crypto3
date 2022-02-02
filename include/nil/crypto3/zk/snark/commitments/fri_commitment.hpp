//---------------------------------------------------------------------------//
// Copyright (c) 2021 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2021 Nikita Kaskov <nbering@nil.foundation>
//
// MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//---------------------------------------------------------------------------//

#ifndef CRYPTO3_ZK_FRI_COMMITMENT_SCHEME_HPP
#define CRYPTO3_ZK_FRI_COMMITMENT_SCHEME_HPP

#include <nil/crypto3/math/polynomial/polynomial.hpp>
#include <nil/crypto3/math/polynomial/lagrange_interpolation.hpp>

#include <nil/crypto3/merkle/tree.hpp>
#include <nil/crypto3/merkle/proof.hpp>

#include <nil/crypto3/zk/snark/transcript/fiat_shamir.hpp>

namespace nil {
    namespace crypto3 {
        namespace zk {
            namespace snark {

                /**
                 * @brief Based on the FRI Commitment description from \[ResShift].
                 * @tparam d ...
                 * @tparam Rounds Denoted by r in \[RedShift].
                 *
                 * References:
                 * \[RedShift]:
                 * "REDSHIFT: Transparent SNARKs from List
                 * Polynomial Commitment IOPs",
                 * Assimakis Kattis, Konstantin Panarin, Alexander Vlasov,
                 * Matter Labs,
                 * <https://eprint.iacr.org/2019/1400.pdf>
                 */
                template<typename FieldType,
                         typename Hash,
                         std::size_t _m = 2>
                struct fri_commitment_scheme {
                    static constexpr std::size_t m = _m;

                    typedef FieldType field_type;
                    typedef Hash transcript_hash_type;

                    typedef typename containers::merkle_tree<Hash, 2> merkle_tree_type;
                    typedef typename containers::merkle_proof<Hash, 2> merkle_proof_type;

                    struct params_type {
                        std::size_t r;
                        std::vector<std::vector<typename FieldType::value_type>> D;

                        math::polynomial::polynomial<typename FieldType::value_type> q;
                    };

                    struct round_proof_type {
                        std::array<typename FieldType::value_type, m> y;
                        std::array<std::vector<typename merkle_tree_type::value_type>, m> p;

                        typename merkle_tree_type::value_type T_root;

                        typename FieldType::value_type colinear_value;
                        std::vector<typename merkle_tree_type::value_type> colinear_path;
                    };

                    struct proof_type {
                        std::vector<round_proof_type> round_proofs; // 0..r-2

                        math::polynomial::polynomial<typename FieldType::value_type> final_polynomial;
                    };

                    // The result of this function is not commitment_type (as it would expected),
                    // but the built Merkle tree. This is done so, because we often need to reuse
                    // the built Merkle tree
                    // After this function
                    // result.root();
                    // should be called
                    static merkle_tree_type
                        commit(const math::polynomial::polynomial<typename FieldType::value_type> &f,
                               const std::vector<typename FieldType::value_type> &D) {
                    }

                    static proof_type proof_eval(const math::polynomial::polynomial<typename FieldType::value_type> &Q,
                                                 const math::polynomial::polynomial<typename FieldType::value_type> &g,
                                                 merkle_tree_type &T,
                                                 fiat_shamir_heuristic_updated<transcript_hash_type> &transcript,
                                                 params_type &fri_params) {

                        proof_type proof;

                        math::polynomial::polynomial<typename FieldType::value_type> f = Q;

                        typename FieldType::value_type x =
                            transcript.template challenge<FieldType>();

                        std::size_t r = fri_params.r;

                        std::vector<round_proof_type> round_proofs;
                        math::polynomial::polynomial<typename FieldType::value_type> final_polynomial;

                        for (std::size_t i = 0; i <= r - 1; i++) {

                            typename FieldType::value_type alpha =
                                fri_params.D[i+1][0].pow(
                                    transcript.template int_challenge<std::size_t>());

                            typename FieldType::value_type x_next = fri_params.q.evaluate(x);

                            std::size_t d = f.degree();

                            math::polynomial::polynomial<typename FieldType::value_type> f_next((d + 1)/2 - 1);

                            for (std::size_t index = 0; index < f_next.size(); index++){
                                f_next[index] = f[2*index] + alpha * f[2*index + 1];
                            }

                            // m = 2, so:
                            std::array<typename FieldType::value_type, m> s;
                            if constexpr (m == 2) {
                                s[0] = x;
                                s[1] = -x;
                            } else {
                                return {};
                            }

                            std::array<typename FieldType::value_type, m> y;

                            for (std::size_t j = 0; j < m; j++) {
                                y[j] = f.evaluate(s[j]);
                            }

                            std::array<std::vector<typename merkle_tree_type::value_type>, m> p;

                            for (std::size_t j = 0; j < m; j++) {
                                if (i == 0) {

                                        typename FieldType::value_type leaf = g.evaluate(s[j]);
                                        std::size_t leaf_index = std::find(
                                            fri_params.D[i].begin(), fri_params.D[i].end(), leaf) - fri_params.D[i].begin();
                                        p[j] = T.hash_path(leaf_index);
                                } else {
                                    for (std::size_t j = 0; j < m; j++) {

                                        std::size_t leaf_index = std::find(
                                            fri_params.D[i].begin(), fri_params.D[i].end(), y[j]) - fri_params.D[i].begin();
                                        p[j] = T.hash_path(leaf_index);
                                    }
                                }
                            }

                            if (i < r - 1) {
                                merkle_tree_type T_next = commit(f_next, fri_params.D[i+1]);
                                transcript(T_next.root());

                                typename FieldType::value_type colinear_value = f_next.evaluate(x_next);

                                std::size_t leaf_index = std::find(
                                    fri_params.D[i+1].begin(), fri_params.D[i+1].end(), colinear_value) - 
                                    fri_params.D[i+1].begin();
                                std::vector<typename merkle_tree_type::value_type> colinear_path = 
                                    T_next.hash_path(leaf_index);

                                round_proofs.push_back(round_proof_type({y, p, T.root(), colinear_value, colinear_path}));

                                T = T_next;
                            } else {
                                final_polynomial = f_next;
                            }

                            x = x_next;
                            f = f_next;
                        }
                        return proof_type ({round_proofs, final_polynomial});
                    }

                    static bool verify_eval() {
                        return true;
                    }
                };
            }    // namespace snark
        }        // namespace zk
    }            // namespace crypto3
}    // namespace nil

#endif    // CRYPTO3_ZK_FRI_COMMITMENT_SCHEME_HPP
