//---------------------------------------------------------------------------//
// Copyright (c) 2020 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020 Nikita Kaskov <nbering@nil.foundation>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//---------------------------------------------------------------------------//

#define BOOST_TEST_MODULE curves_algebra_test

#include <iostream>
#include <type_traits>

#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

// #include <nil/algebra/curves/alt_bn128.hpp>
// #include <nil/algebra/curves/bls12.hpp>
#include <nil/algebra/curves/bn128.hpp>
// #include <nil/algebra/curves/brainpool_r1.hpp>
#include <nil/algebra/curves/edwards.hpp>
// #include <nil/algebra/curves/frp_v1.hpp>
// #include <nil/algebra/curves/gost_A.hpp>
#include <nil/algebra/curves/mnt4.hpp>
#include <nil/algebra/curves/mnt6.hpp>
// #include <nil/algebra/curves/p192.hpp>
// #include <nil/algebra/curves/p224.hpp>
// #include <nil/algebra/curves/p256.hpp>
// #include <nil/algebra/curves/p384.hpp>
// #include <nil/algebra/curves/p521.hpp>
// #include <nil/algebra/curves/secp.hpp>
// #include <nil/algebra/curves/sm2p_v1.hpp>
// #include <nil/algebra/curves/x962_p.hpp>

using namespace nil::algebra;

namespace boost {
    namespace test_tools {
        namespace tt_detail {
            template<typename FpCurveGroup>
            void print_fp_curve_group_element(std::ostream &os, FpCurveGroup e) {
                os << "( " << e.p[0].data << " : " << e.p[1].data << " : " << e.p[2].data << " )";
            }

            template<typename Fp2CurveGroup>
            void print_fp2_curve_group_element(std::ostream &os, Fp2CurveGroup e) {
                os << "(" << e.p[0].data[0].data << " , " << e.p[0].data[1].data << ") : (" << e.p[1].data[0].data << " , "
                    << e.p[1].data[1].data << ") : (" << e.p[2].data[0].data << " , " << e.p[2].data[1].data << ")" << std::endl;
            }


            template<>
            struct print_log_value<typename curves::bn128<254>::g1_type> {
                void operator()(std::ostream &os, typename curves::bn128<254>::g1_type const &e) {
                    print_fp_curve_group_element(os, e);
                }
            };

            template<>
            struct print_log_value<typename curves::edwards<183>::g1_type> {
                void operator()(std::ostream &os, typename curves::edwards<183>::g1_type const &e) {
                    print_fp_curve_group_element(os, e);
                }
            };

            template<>
            struct print_log_value<typename curves::mnt4<298>::g1_type> {
                void operator()(std::ostream &os, typename curves::mnt4<298>::g1_type const &e) {
                    print_fp_curve_group_element(os, e);
                }
            };

            template<>
            struct print_log_value<typename curves::mnt6<298>::g1_type> {
                void operator()(std::ostream &os, typename curves::mnt6<298>::g1_type const &e) {
                    print_fp_curve_group_element(os, e);
                }
            };

            template<>
            struct print_log_value<typename curves::mnt4<298>::g2_type> {
                void operator()(std::ostream &os, typename curves::mnt4<298>::g2_type const &e) {
                    print_fp2_curve_group_element(os, e);
                }
            };

            template<>
            struct print_log_value<typename curves::bn128<254>::g2_type> {
                void operator()(std::ostream &os, typename curves::bn128<254>::g2_type const &e) {
                    print_fp2_curve_group_element(os, e);
                }
            };

            template<template<typename, typename> class P, typename K, typename V>
            struct print_log_value<P<K, V>> {
                void operator()(std::ostream &, P<K, V> const &) {
                }
            };

        }    // namespace tt_detail
    }        // namespace test_tools
}    // namespace boost

// if target == check-algebra just data/curves.json
const char *test_data = "libs/algebra/test/data/curves.json";

boost::property_tree::ptree string_data(std::string test_name) {
    boost::property_tree::ptree string_data;
    boost::property_tree::read_json(test_data, string_data);

    return string_data.get_child(test_name);
}

enum binary_operator_test_constants : std::size_t {
    C1,
    C2
};

enum binary_operator_test_points : std::size_t {
    p1,
    p2,
    p1_plus_p2,
    p1_minus_p2,
    p1_mul_C1,
    p2_mul_C1_plus_p2_mul_C2,
    p1_dbl
};

template<typename CurveGroup>
void do_binary_operators_checks(const std::vector<CurveGroup> &points, const std::vector<std::size_t> &constants) {
    BOOST_CHECK_EQUAL(points[p1] + points[p2], points[p1_plus_p2]);
    BOOST_CHECK_EQUAL(points[p1] - points[p2], points[p1_minus_p2]);
    BOOST_CHECK_EQUAL(points[p1].doubled(), points[p1_dbl]);
}


template<typename FpCurveGroup, typename PointsSetType>
void binary_operators_test_fp_init(const PointsSetType &data_set) {
    using field_value_type = typename FpCurveGroup::underlying_field_type_value;

    std::array<field_value_type, 3> coordinates;
    std::vector<FpCurveGroup> points;
    std::vector<std::size_t> constants;

    for (auto &point : data_set.second.get_child("point_coordinates")) {
        auto i = 0;
        for (auto &coordinate : point.second) {
            coordinates[i++] = field_value_type(typename field_value_type::modulus_type(coordinate.second.data()));
        }
        points.emplace_back(FpCurveGroup(coordinates[0], coordinates[1], coordinates[2]));
    }

    for (auto &constant : data_set.second.get_child("constants")) {
        constants.emplace_back(std::stoul(constant.second.data()));
    }

    do_binary_operators_checks(points, constants);
}

template<typename Fp2CurveGroup, typename PointsSetType>
void binary_operators_test_fp2_init(const PointsSetType &data_set) {
    using fp2_value_type = typename Fp2CurveGroup::underlying_field_type_value;
    using modulus_type = typename fp2_value_type::underlying_type::modulus_type;

    std::array<modulus_type, 6> coordinates;
    std::vector<Fp2CurveGroup> points;
    std::vector<std::size_t> constants;

    for (auto &point : data_set.second.get_child("point_coordinates")) {
        auto i = 0;
        for (auto &coordinate_pairs : point.second) {
            for (auto &coordinate : coordinate_pairs.second) {
                coordinates[i++] = modulus_type(
                    coordinate.second.data());
            }
        }
        points.emplace_back(Fp2CurveGroup(fp2_value_type(coordinates[0], coordinates[1]),
                                          fp2_value_type(coordinates[2], coordinates[3]),
                                          fp2_value_type(coordinates[4], coordinates[5])));
    }

    for (auto &constant : data_set.second.get_child("constants")) {
        constants.emplace_back(std::stoul(constant.second.data()));
    }

    do_binary_operators_checks(points, constants);
}

BOOST_AUTO_TEST_SUITE(curves_manual_tests)

BOOST_DATA_TEST_CASE(binary_operators_test_bn128_g1, string_data("binary_operators_test_bn128_g1"), data_set) {
    using policy_type = curves::bn128<254>::g1_type;

    binary_operators_test_fp_init<policy_type>(data_set);
}

BOOST_DATA_TEST_CASE(binary_operators_test_edwards_g1, string_data("binary_operators_test_edwards_g1"), data_set) {
    using policy_type = curves::edwards<183>::g1_type;

    binary_operators_test_fp_init<policy_type>(data_set);
}

BOOST_DATA_TEST_CASE(binary_operators_test_mnt4_g1, string_data("binary_operators_test_mnt4_g1"), data_set) {
    using policy_type = curves::mnt4<298>::g1_type;

    binary_operators_test_fp_init<policy_type>(data_set);
}

BOOST_DATA_TEST_CASE(binary_operators_test_mnt6_g1, string_data("binary_operators_test_mnt6_g1"), data_set) {
    using policy_type = curves::mnt6<298>::g1_type;

    binary_operators_test_fp_init<policy_type>(data_set);
}

BOOST_DATA_TEST_CASE(binary_operators_test_mnt4_g2, string_data("binary_operators_test_mnt4_g2"), data_set) {
    using policy_type = curves::mnt4<298>::g2_type;
    // using field_value_type = typename policy_type::underlying_field_type_value;

    // field_value_type c1(typename field_value_type::underlying_type::modulus_type("1"),
    //                     typename field_value_type::underlying_type::modulus_type("0"));
    // field_value_type c2(typename field_value_type::underlying_type::modulus_type("1"),
    //                     typename field_value_type::underlying_type::modulus_type("0"));
    // field_value_type c3(typename field_value_type::underlying_type::modulus_type("1"),
    //                     typename field_value_type::underlying_type::modulus_type("0"));
    // policy_type e1(c1, c2, c3);

    binary_operators_test_fp2_init<policy_type>(data_set);
}

BOOST_DATA_TEST_CASE(binary_operators_test_bn128_g2, string_data("binary_operators_test_bn128_g2"), data_set) {
    using policy_type = curves::bn128<254>::g2_type;

    binary_operators_test_fp2_init<policy_type>(data_set);
}

// BOOST_AUTO_TEST_CASE(manual_binary_operators_test_bn128_g1) {
//     using policy_type = curves::bn128<254>::g1_type;
//     using field_value_type = typename policy_type::underlying_field_type_value;

//     field_value_type e1 = field_value_type(typename field_value_type::modulus_type("8718910420120953292626758946268359211266512519998390977200503634661656764291")), 
//         e2(typename field_value_type::modulus_type("16902211324647849978392628005394375725507063489818401482037640269305116971446")), 
//         e3(typename field_value_type::modulus_type("10458796362569620485581750516607707450359052571458665689150225146886369382697")), 
//         e4(typename field_value_type::modulus_type("17603818051918249661201874048217664572634559577244390238763458565355344197897")), 
//         e5(typename field_value_type::modulus_type("19138067926120938747425757443066130627215996404548778913181247609772592726999")),
//         e6(typename field_value_type::modulus_type("18852042599170319442214645472536024081319018389195908748227068956156858062273"));
//     policy_type c1(e1, e2, e3), c2(e4, e5, e6);

//     boost::test_tools::tt_detail::print_fp_curve_group_element(std::cout, c1+c2);
//     boost::test_tools::tt_detail::print_fp_curve_group_element(std::cout, c1-c2);
//     boost::test_tools::tt_detail::print_fp_curve_group_element(std::cout, c1 * 1234);
//     boost::test_tools::tt_detail::print_fp_curve_group_element(std::cout, c2 * 2345);
//     boost::test_tools::tt_detail::print_fp_curve_group_element(std::cout, c1.doubled());
// }


BOOST_AUTO_TEST_SUITE_END()
