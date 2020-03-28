//---------------------------------------------------------------------------//
// Copyright (c) 2018-2020 Mikhail Komarov <nemo@nil.foundation>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//---------------------------------------------------------------------------//

#ifndef CRYPTO3_PUBKEY_DL_GROUP_INFO_HPP
#define CRYPTO3_PUBKEY_DL_GROUP_INFO_HPP

#include <boost/multiprecision/number.hpp>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_int/cpp_int_config.hpp>

namespace nil {
    namespace crypto3 {
        namespace pubkey {

            using namespace boost::multiprecision;

            BOOST_MP_DEFINE_SIZED_CPP_INT_LITERAL(1024)

            BOOST_MP_DEFINE_SIZED_CPP_INT_LITERAL(1536)

            BOOST_MP_DEFINE_SIZED_CPP_INT_LITERAL(2048)

            BOOST_MP_DEFINE_SIZED_CPP_INT_LITERAL(3072)

            BOOST_MP_DEFINE_SIZED_CPP_INT_LITERAL(4096)

            BOOST_MP_DEFINE_SIZED_CPP_INT_LITERAL(6144)

            BOOST_MP_DEFINE_SIZED_CPP_INT_LITERAL(8192)

            template<std::size_t PBits>
            struct dl_group_info {
                constexpr static const std::size_t p_bits = PBits;

                typedef number<backends::cpp_int_backend<p_bits, p_bits, unsigned_magnitude, unchecked, void>> p_type;
            };

            /*!
             * @brief TLS FFDHE groups
             * @tparam PBits
             */
            template<std::size_t PBits>
            struct ffdhe_ietf : public dl_group_info<PBits> {};

            template<>
            struct ffdhe_ietf<2048> : public dl_group_info<2048> {
                typedef typename dl_group_info<2048>::p_type p_type;
                typedef p_type q_type;

                constexpr static const p_type p =
                    0xFFFFFFFFFFFFFFFFADF85458A2BB4A9AAFDC5620273D3CF1D8B9C583CE2D3695A9E13641146433FBCC939DCE249B3EF97D2FE363630C75D8F681B202AEC4617AD3DF1ED5D5FD65612433F51F5F066ED0856365553DED1AF3B557135E7F57C935984F0C70E0E68B77E2A689DAF3EFE8721DF158A136ADE73530ACCA4F483A797ABC0AB182B324FB61D108A94BB2C8E3FBB96ADAB760D7F4681D4F42A3DE394DF4AE56EDE76372BB190B07A7C8EE0A6D709E02FCE1CDF7E2ECC03404CD28342F619172FE9CE98583FF8E4F1232EEF28183C3FE3B1B4C6FAD733BB5FCBC2EC22005C58EF1837D1683B2C6F34A26C1B2EFFA886B423861285C97FFFFFFFFFFFFFFFF_cppui2048;
                constexpr static const q_type q = (p - 1) / 2;
                constexpr static const std::size_t g = 0x2;
            };

            template<>
            struct ffdhe_ietf<3072> : public dl_group_info<3072> {
                typedef typename dl_group_info<3072>::p_type p_type;
                typedef p_type q_type;

                constexpr static const p_type p =
                    0xFFFFFFFFFFFFFFFFADF85458A2BB4A9AAFDC5620273D3CF1D8B9C583CE2D3695A9E13641146433FBCC939DCE249B3EF97D2FE363630C75D8F681B202AEC4617AD3DF1ED5D5FD65612433F51F5F066ED0856365553DED1AF3B557135E7F57C935984F0C70E0E68B77E2A689DAF3EFE8721DF158A136ADE73530ACCA4F483A797ABC0AB182B324FB61D108A94BB2C8E3FBB96ADAB760D7F4681D4F42A3DE394DF4AE56EDE76372BB190B07A7C8EE0A6D709E02FCE1CDF7E2ECC03404CD28342F619172FE9CE98583FF8E4F1232EEF28183C3FE3B1B4C6FAD733BB5FCBC2EC22005C58EF1837D1683B2C6F34A26C1B2EFFA886B4238611FCFDCDE355B3B6519035BBC34F4DEF99C023861B46FC9D6E6C9077AD91D2691F7F7EE598CB0FAC186D91CAEFE130985139270B4130C93BC437944F4FD4452E2D74DD364F2E21E71F54BFF5CAE82AB9C9DF69EE86D2BC522363A0DABC521979B0DEADA1DBF9A42D5C4484E0ABCD06BFA53DDEF3C1B20EE3FD59D7C25E41D2B66C62E37FFFFFFFFFFFFFFFF_cppui3072;
                constexpr static const q_type q = (p - 1) / 2;
                constexpr static const std::size_t g = 0x2;
            };

            template<>
            struct ffdhe_ietf<4096> : public dl_group_info<4096> {
                typedef typename dl_group_info<4096>::p_type p_type;
                typedef p_type q_type;

                constexpr static const p_type p =
                    0xFFFFFFFFFFFFFFFFADF85458A2BB4A9AAFDC5620273D3CF1D8B9C583CE2D3695A9E13641146433FBCC939DCE249B3EF97D2FE363630C75D8F681B202AEC4617AD3DF1ED5D5FD65612433F51F5F066ED0856365553DED1AF3B557135E7F57C935984F0C70E0E68B77E2A689DAF3EFE8721DF158A136ADE73530ACCA4F483A797ABC0AB182B324FB61D108A94BB2C8E3FBB96ADAB760D7F4681D4F42A3DE394DF4AE56EDE76372BB190B07A7C8EE0A6D709E02FCE1CDF7E2ECC03404CD28342F619172FE9CE98583FF8E4F1232EEF28183C3FE3B1B4C6FAD733BB5FCBC2EC22005C58EF1837D1683B2C6F34A26C1B2EFFA886B4238611FCFDCDE355B3B6519035BBC34F4DEF99C023861B46FC9D6E6C9077AD91D2691F7F7EE598CB0FAC186D91CAEFE130985139270B4130C93BC437944F4FD4452E2D74DD364F2E21E71F54BFF5CAE82AB9C9DF69EE86D2BC522363A0DABC521979B0DEADA1DBF9A42D5C4484E0ABCD06BFA53DDEF3C1B20EE3FD59D7C25E41D2B669E1EF16E6F52C3164DF4FB7930E9E4E58857B6AC7D5F42D69F6D187763CF1D5503400487F55BA57E31CC7A7135C886EFB4318AED6A1E012D9E6832A907600A918130C46DC778F971AD0038092999A333CB8B7A1A1DB93D7140003C2A4ECEA9F98D0ACC0A8291CDCEC97DCF8EC9B55A7F88A46B4DB5A851F44182E1C68A007E5E655F6AFFFFFFFFFFFFFFFF_cppui4096;
                constexpr static const q_type q = (p - 1) / 2;
                constexpr static const std::size_t g = 0x2;
            };

            template<>
            struct ffdhe_ietf<6144> : public dl_group_info<6144> {
                typedef typename dl_group_info<6144>::p_type p_type;
                typedef p_type q_type;

                constexpr static const p_type p =
                    0xFFFFFFFFFFFFFFFFADF85458A2BB4A9AAFDC5620273D3CF1D8B9C583CE2D3695A9E13641146433FBCC939DCE249B3EF97D2FE363630C75D8F681B202AEC4617AD3DF1ED5D5FD65612433F51F5F066ED0856365553DED1AF3B557135E7F57C935984F0C70E0E68B77E2A689DAF3EFE8721DF158A136ADE73530ACCA4F483A797ABC0AB182B324FB61D108A94BB2C8E3FBB96ADAB760D7F4681D4F42A3DE394DF4AE56EDE76372BB190B07A7C8EE0A6D709E02FCE1CDF7E2ECC03404CD28342F619172FE9CE98583FF8E4F1232EEF28183C3FE3B1B4C6FAD733BB5FCBC2EC22005C58EF1837D1683B2C6F34A26C1B2EFFA886B4238611FCFDCDE355B3B6519035BBC34F4DEF99C023861B46FC9D6E6C9077AD91D2691F7F7EE598CB0FAC186D91CAEFE130985139270B4130C93BC437944F4FD4452E2D74DD364F2E21E71F54BFF5CAE82AB9C9DF69EE86D2BC522363A0DABC521979B0DEADA1DBF9A42D5C4484E0ABCD06BFA53DDEF3C1B20EE3FD59D7C25E41D2B669E1EF16E6F52C3164DF4FB7930E9E4E58857B6AC7D5F42D69F6D187763CF1D5503400487F55BA57E31CC7A7135C886EFB4318AED6A1E012D9E6832A907600A918130C46DC778F971AD0038092999A333CB8B7A1A1DB93D7140003C2A4ECEA9F98D0ACC0A8291CDCEC97DCF8EC9B55A7F88A46B4DB5A851F44182E1C68A007E5E0DD9020BFD64B645036C7A4E677D2C38532A3A23BA4442CAF53EA63BB454329B7624C8917BDD64B1C0FD4CB38E8C334C701C3ACDAD0657FCCFEC719B1F5C3E4E46041F388147FB4CFDB477A52471F7A9A96910B855322EDB6340D8A00EF092350511E30ABEC1FFF9E3A26E7FB29F8C183023C3587E38DA0077D9B4763E4E4B94B2BBC194C6651E77CAF992EEAAC0232A281BF6B3A739C1226116820AE8DB5847A67CBEF9C9091B462D538CD72B03746AE77F5E62292C311562A846505DC82DB854338AE49F5235C95B91178CCF2DD5CACEF403EC9D1810C6272B045B3B71F9DC6B80D63FDD4A8E9ADB1E6962A69526D43161C1A41D570D7938DAD4A40E329CD0E40E65FFFFFFFFFFFFFFFF_cppui6144;
                constexpr static const q_type q = (p - 1) / 2;
                constexpr static const std::size_t g = 0x2;
            };

            template<>
            struct ffdhe_ietf<8192> : public dl_group_info<8192> {
                typedef typename dl_group_info<8192>::p_type p_type;
                typedef p_type q_type;

                constexpr static const p_type p =
                    0xFFFFFFFFFFFFFFFFADF85458A2BB4A9AAFDC5620273D3CF1D8B9C583CE2D3695A9E13641146433FBCC939DCE249B3EF97D2FE363630C75D8F681B202AEC4617AD3DF1ED5D5FD65612433F51F5F066ED0856365553DED1AF3B557135E7F57C935984F0C70E0E68B77E2A689DAF3EFE8721DF158A136ADE73530ACCA4F483A797ABC0AB182B324FB61D108A94BB2C8E3FBB96ADAB760D7F4681D4F42A3DE394DF4AE56EDE76372BB190B07A7C8EE0A6D709E02FCE1CDF7E2ECC03404CD28342F619172FE9CE98583FF8E4F1232EEF28183C3FE3B1B4C6FAD733BB5FCBC2EC22005C58EF1837D1683B2C6F34A26C1B2EFFA886B4238611FCFDCDE355B3B6519035BBC34F4DEF99C023861B46FC9D6E6C9077AD91D2691F7F7EE598CB0FAC186D91CAEFE130985139270B4130C93BC437944F4FD4452E2D74DD364F2E21E71F54BFF5CAE82AB9C9DF69EE86D2BC522363A0DABC521979B0DEADA1DBF9A42D5C4484E0ABCD06BFA53DDEF3C1B20EE3FD59D7C25E41D2B669E1EF16E6F52C3164DF4FB7930E9E4E58857B6AC7D5F42D69F6D187763CF1D5503400487F55BA57E31CC7A7135C886EFB4318AED6A1E012D9E6832A907600A918130C46DC778F971AD0038092999A333CB8B7A1A1DB93D7140003C2A4ECEA9F98D0ACC0A8291CDCEC97DCF8EC9B55A7F88A46B4DB5A851F44182E1C68A007E5E0DD9020BFD64B645036C7A4E677D2C38532A3A23BA4442CAF53EA63BB454329B7624C8917BDD64B1C0FD4CB38E8C334C701C3ACDAD0657FCCFEC719B1F5C3E4E46041F388147FB4CFDB477A52471F7A9A96910B855322EDB6340D8A00EF092350511E30ABEC1FFF9E3A26E7FB29F8C183023C3587E38DA0077D9B4763E4E4B94B2BBC194C6651E77CAF992EEAAC0232A281BF6B3A739C1226116820AE8DB5847A67CBEF9C9091B462D538CD72B03746AE77F5E62292C311562A846505DC82DB854338AE49F5235C95B91178CCF2DD5CACEF403EC9D1810C6272B045B3B71F9DC6B80D63FDD4A8E9ADB1E6962A69526D43161C1A41D570D7938DAD4A40E329CCFF46AAA36AD004CF600C8381E425A31D951AE64FDB23FCEC9509D43687FEB69EDD1CC5E0B8CC3BDF64B10EF86B63142A3AB8829555B2F747C932665CB2C0F1CC01BD70229388839D2AF05E454504AC78B7582822846C0BA35C35F5C59160CC046FD8251541FC68C9C86B022BB7099876A460E7451A8A93109703FEE1C217E6C3826E52C51AA691E0E423CFC99E9E31650C1217B624816CDAD9A95F9D5B8019488D9C0A0A1FE3075A577E23183F81D4A3F2FA4571EFC8CE0BA8A4FE8B6855DFE72B0A66EDED2FBABFBE58A30FAFABE1C5D71A87E2F741EF8C1FE86FEA6BBFDE530677F0D97D11D49F7A8443D0822E506A9F4614E011E2A94838FF88CD68C8BB7C5C6424CFFFFFFFFFFFFFFFF_cppui8192;
                constexpr static const q_type q = (p - 1) / 2;
                constexpr static const std::size_t g = 0x2;
            };

            /*!
             * @brief IETF IPsec groups
             * @tparam PBits
             */
            template<std::size_t PBits>
            struct modp_ietf : public dl_group_info<PBits> {};

            template<>
            struct modp_ietf<1024> : public dl_group_info<1024> {
                typedef typename dl_group_info<1024>::p_type p_type;
                typedef p_type q_type;

                constexpr static const p_type p =
                    0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE65381FFFFFFFFFFFFFFFF_cppui1024;
                constexpr static const q_type q = (p - 1) / 2;
                constexpr static const std::size_t g = 0x2;
            };

            template<>
            struct modp_ietf<1536> : public dl_group_info<1536> {
                typedef typename dl_group_info<1536>::p_type p_type;
                typedef p_type q_type;

                constexpr static const p_type p =
                    0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA237327FFFFFFFFFFFFFFFF_cppui1536;
                constexpr static const q_type q = (p - 1) / 2;
                constexpr static const std::size_t g = 0x2;
            };

            template<>
            struct modp_ietf<2048> : public dl_group_info<2048> {
                typedef typename dl_group_info<2048>::p_type p_type;
                typedef p_type q_type;

                constexpr static const p_type p =
                    0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA18217C32905E462E36CE3BE39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9DE2BCBF6955817183995497CEA956AE515D2261898FA051015728E5A8AACAA68FFFFFFFFFFFFFFFF_cppui2048;
                constexpr static const q_type q = (p - 1) / 2;
                constexpr static const std::size_t g = 0x2;
            };

            template<>
            struct modp_ietf<3072> : public dl_group_info<3072> {
                typedef typename dl_group_info<3072>::p_type p_type;
                typedef p_type q_type;

                constexpr static const p_type p =
                    0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA18217C32905E462E36CE3BE39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9DE2BCBF6955817183995497CEA956AE515D2261898FA051015728E5A8AAAC42DAD33170D04507A33A85521ABDF1CBA64ECFB850458DBEF0A8AEA71575D060C7DB3970F85A6E1E4C7ABF5AE8CDB0933D71E8C94E04A25619DCEE3D2261AD2EE6BF12FFA06D98A0864D87602733EC86A64521F2B18177B200CBBE117577A615D6C770988C0BAD946E208E24FA074E5AB3143DB5BFCE0FD108E4B82D120A93AD2CAFFFFFFFFFFFFFFFF_cppui3072;
                constexpr static const q_type q = (p - 1) / 2;
                constexpr static const std::size_t g = 0x2;
            };

            template<>
            struct modp_ietf<4096> : public dl_group_info<4096> {
                typedef typename dl_group_info<4096>::p_type p_type;
                typedef p_type q_type;

                constexpr static const p_type p =
                    0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA18217C32905E462E36CE3BE39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9DE2BCBF6955817183995497CEA956AE515D2261898FA051015728E5A8AAAC42DAD33170D04507A33A85521ABDF1CBA64ECFB850458DBEF0A8AEA71575D060C7DB3970F85A6E1E4C7ABF5AE8CDB0933D71E8C94E04A25619DCEE3D2261AD2EE6BF12FFA06D98A0864D87602733EC86A64521F2B18177B200CBBE117577A615D6C770988C0BAD946E208E24FA074E5AB3143DB5BFCE0FD108E4B82D120A92108011A723C12A787E6D788719A10BDBA5B2699C327186AF4E23C1A946834B6150BDA2583E9CA2AD44CE8DBBBC2DB04DE8EF92E8EFC141FBECAA6287C59474E6BC05D99B2964FA090C3A2233BA186515BE7ED1F612970CEE2D7AFB81BDD762170481CD0069127D5B05AA993B4EA988D8FDDC186FFB7DC90A6C08F4DF435C934063199FFFFFFFFFFFFFFFF_cppui4096;
                constexpr static const q_type q = (p - 1) / 2;
                constexpr static const std::size_t g = 0x2;
            };

            template<>
            struct modp_ietf<6144> : public dl_group_info<6144> {
                typedef typename dl_group_info<6144>::p_type p_type;
                typedef p_type q_type;

                constexpr static const p_type p = 0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA18217C32905E462E36CE3BE39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9DE2BCBF6955817183995497CEA956AE515D2261898FA051015728E5A8AAAC42DAD33170D04507A33A85521ABDF1CBA64ECFB850458DBEF0A8AEA71575D060C7DB3970F85A6E1E4C7ABF5AE8CDB0933D71E8C94E04A25619DCEE3D2261AD2EE6BF12FFA06D98A0864D87602733EC86A64521F2B18177B200CBBE117577A615D6C770988C0BAD946E208E24FA074E5AB3143DB5BFCE0FD108E4B82D120A92108011A723C12A787E6D788719A10BDBA5B2699C327186AF4E23C1A946834B6150BDA2583E9CA2AD44CE8DBBBC2DB04DE8EF92E8EFC141FBECAA6287C59474E6BC05D99B2964FA090C3A2233BA186515BE7ED1F612970CEE2D7AFB81BDD762170481CD0069127D5B05AA993B4EA988D8FDDC186FFB7DC90A6C08F4DF435C93402849236C3FAB4D27C7026C1D4DCB2602646DEC9751E763DBA37BDF8FF9406AD9E530EE5DB382F413001AEB06A53ED9027D831179727B0865A8918DA3EDBEBCF9B14ED44CE6CBACED4BB1BDB7F1447E6CC254B332051512BD7AF426FB8F401378CD2BF5983CA01C64B92ECF032EA15D1721D03F482D7CE6E74FEF6D55E702F46980C82B5A84031900B1C9E59E7C97FBEC7E8F323A97A7E36CC88BE0F1D45B7FF585AC54BD407B22B4154AACC8F6D7EBF48E1D814CC5ED20F8037E0A79715EEF29BE32806A1D58BB7C5DA76F550AA3D8A1FBFF0EB19CCB1A313D55CDA56C9EC2EF29632387FE8D76E3C0468043E8F663F4860EE12BF2D5B0B7474D6E694F91E6DCC4024FFFFFFFFFFFFFFFF_cppui6144;
                constexpr static const q_type q = (p - 1) / 2;
                constexpr static const std::size_t g = 0x2;
            };

            template<>
            struct modp_ietf<8192> : public dl_group_info<8192> {
                typedef typename dl_group_info<8192>::p_type p_type;
                typedef p_type q_type;

                constexpr static const p_type p = 0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA18217C32905E462E36CE3BE39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9DE2BCBF6955817183995497CEA956AE515D2261898FA051015728E5A8AAAC42DAD33170D04507A33A85521ABDF1CBA64ECFB850458DBEF0A8AEA71575D060C7DB3970F85A6E1E4C7ABF5AE8CDB0933D71E8C94E04A25619DCEE3D2261AD2EE6BF12FFA06D98A0864D87602733EC86A64521F2B18177B200CBBE117577A615D6C770988C0BAD946E208E24FA074E5AB3143DB5BFCE0FD108E4B82D120A92108011A723C12A787E6D788719A10BDBA5B2699C327186AF4E23C1A946834B6150BDA2583E9CA2AD44CE8DBBBC2DB04DE8EF92E8EFC141FBECAA6287C59474E6BC05D99B2964FA090C3A2233BA186515BE7ED1F612970CEE2D7AFB81BDD762170481CD0069127D5B05AA993B4EA988D8FDDC186FFB7DC90A6C08F4DF435C93402849236C3FAB4D27C7026C1D4DCB2602646DEC9751E763DBA37BDF8FF9406AD9E530EE5DB382F413001AEB06A53ED9027D831179727B0865A8918DA3EDBEBCF9B14ED44CE6CBACED4BB1BDB7F1447E6CC254B332051512BD7AF426FB8F401378CD2BF5983CA01C64B92ECF032EA15D1721D03F482D7CE6E74FEF6D55E702F46980C82B5A84031900B1C9E59E7C97FBEC7E8F323A97A7E36CC88BE0F1D45B7FF585AC54BD407B22B4154AACC8F6D7EBF48E1D814CC5ED20F8037E0A79715EEF29BE32806A1D58BB7C5DA76F550AA3D8A1FBFF0EB19CCB1A313D55CDA56C9EC2EF29632387FE8D76E3C0468043E8F663F4860EE12BF2D5B0B7474D6E694F91E6DBE115974A3926F12FEE5E438777CB6A932DF8CD8BEC4D073B931BA3BC832B68D9DD300741FA7BF8AFC47ED2576F6936BA424663AAB639C5AE4F5683423B4742BF1C978238F16CBE39D652DE3FDB8BEFC848AD922222E04A4037C0713EB57A81A23F0C73473FC646CEA306B4BCBC8862F8385DDFA9D4B7FA2C087E879683303ED5BDD3A062B3CF5B3A278A66D2A13F83F44F82DDF310EE074AB6A364597E899A0255DC164F31CC50846851DF9AB48195DED7EA1B1D510BD7EE74D73FAF36BC31ECFA268359046F4EB879F924009438B481C6CD7889A002ED5EE382BC9190DA6FC026E479558E4475677E9AA9E3050E2765694DFC81F56E880B96E7160C980DD98EDD3DFFFFFFFFFFFFFFFFF_cppui8192;
                constexpr static const q_type q = (p - 1) / 2;
                constexpr static const std::size_t g = 0x2;
            };

            /*!
             * @brief SRP groups

             * SRP groups have a p st (p-1)/2 is prime, but g is not a generator
             * of subgroup of size q, so set q == 0 to bypass generator check

             * Missing q doesn't matter for SRP, and nothing but SRP should be
             * using these parameters.
             *
             * @tparam PBits
             */
            template<std::size_t PBits>
            struct modp_srp : public dl_group_info<PBits> {};

            template<>
            struct modp_srp<1024> : public dl_group_info<1024> {
                typedef typename dl_group_info<1024>::p_type p_type;
                typedef std::size_t q_type;
                typedef std::size_t g_type;

                constexpr static const p_type p =
                    0xEEAF0AB9ADB38DD69C33F80AFA8FC5E86072618775FF3C0B9EA2314C9C256576D674DF7496EA81D3383B4813D692C6E0E0D5D8E250B98BE48E495C1D6089DAD15DC7D7B46154D6B6CE8EF4AD69B15D4982559B297BCF1885C529F566660E57EC68EDBC3C05726CC02FD4CBF4976EAA9AFD5138FE8376435B9FC61D2FC0EB06E3_cppui1024;
                constexpr static const q_type q = 0;
                constexpr static const g_type g = 0x2;
            };

            template<>
            struct modp_srp<1536> : public dl_group_info<1536> {
                typedef typename dl_group_info<1536>::p_type p_type;
                typedef std::size_t q_type;
                typedef std::size_t g_type;

                constexpr static const p_type p =
                    0x9DEF3CAFB939277AB1F12A8617A47BBBDBA51DF499AC4C80BEEEA9614B19CC4D5F4F5F556E27CBDE51C6A94BE4607A291558903BA0D0F84380B655BB9A22E8DCDF028A7CEC67F0D08134B1C8B97989149B609E0BE3BAB63D47548381DBC5B1FC764E3F4B53DD9DA1158BFD3E2B9C8CF56EDF019539349627DB2FD53D24B7C48665772E437D6C7F8CE442734AF7CCB7AE837C264AE3A9BEB87F8A2FE9B8B5292E5A021FFF5E91479E8CE7A28C2442C6F315180F93499A234DCF76E3FED135F9BB_cppui1536;
                constexpr static const q_type q = 0;
                constexpr static const g_type g = 0x2;
            };

            template<>
            struct modp_srp<2048> : public dl_group_info<2048> {
                typedef typename dl_group_info<2048>::p_type p_type;
                typedef std::size_t q_type;
                typedef std::size_t g_type;

                constexpr static const p_type p =
                    0xAC6BDB41324A9A9BF166DE5E1389582FAF72B6651987EE07FC3192943DB56050A37329CBB4A099ED8193E0757767A13DD52312AB4B03310DCD7F48A9DA04FD50E8083969EDB767B0CF6095179A163AB3661A05FBD5FAAAE82918A9962F0B93B855F97993EC975EEAA80D740ADBF4FF747359D041D5C33EA71D281E446B14773BCA97B43A23FB801676BD207A436C6481F1D2B9078717461A5B9D32E688F87748544523B524B0D57D5EA77A2775D2ECFA032CFBDBF52FB3786160279004E57AE6AF874E7303CE53299CCC041C7BC308D82A5698F3A8D0C38271AE35F8E9DBFBB694B5C803D89F7AE435DE236D525F54759B65E372FCD68EF20FA7111F9E4AFF73_cppui2048;
                constexpr static const q_type q = 0;
                constexpr static const g_type g = 0x2;
            };

            template<>
            struct modp_srp<3072> : public dl_group_info<3072> {
                typedef typename dl_group_info<3072>::p_type p_type;
                typedef std::size_t q_type;
                typedef std::size_t g_type;

                constexpr static const p_type p =
                    0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA18217C32905E462E36CE3BE39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9DE2BCBF6955817183995497CEA956AE515D2261898FA051015728E5A8AAAC42DAD33170D04507A33A85521ABDF1CBA64ECFB850458DBEF0A8AEA71575D060C7DB3970F85A6E1E4C7ABF5AE8CDB0933D71E8C94E04A25619DCEE3D2261AD2EE6BF12FFA06D98A0864D87602733EC86A64521F2B18177B200CBBE117577A615D6C770988C0BAD946E208E24FA074E5AB3143DB5BFCE0FD108E4B82D120A93AD2CAFFFFFFFFFFFFFFFF_cppui3072;
                constexpr static const q_type q = 0;
                constexpr static const g_type g = 0x5;
            };

            template<>
            struct modp_srp<4096> : public dl_group_info<4096> {
                typedef typename dl_group_info<4096>::p_type p_type;
                typedef std::size_t q_type;
                typedef std::size_t g_type;

                constexpr static const p_type p =
                    0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA18217C32905E462E36CE3BE39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9DE2BCBF6955817183995497CEA956AE515D2261898FA051015728E5A8AAAC42DAD33170D04507A33A85521ABDF1CBA64ECFB850458DBEF0A8AEA71575D060C7DB3970F85A6E1E4C7ABF5AE8CDB0933D71E8C94E04A25619DCEE3D2261AD2EE6BF12FFA06D98A0864D87602733EC86A64521F2B18177B200CBBE117577A615D6C770988C0BAD946E208E24FA074E5AB3143DB5BFCE0FD108E4B82D120A92108011A723C12A787E6D788719A10BDBA5B2699C327186AF4E23C1A946834B6150BDA2583E9CA2AD44CE8DBBBC2DB04DE8EF92E8EFC141FBECAA6287C59474E6BC05D99B2964FA090C3A2233BA186515BE7ED1F612970CEE2D7AFB81BDD762170481CD0069127D5B05AA993B4EA988D8FDDC186FFB7DC90A6C08F4DF435C934063199FFFFFFFFFFFFFFFF_cppui4096;
                constexpr static const q_type q = 0;
                constexpr static const g_type g = 0x5;
            };

            template<>
            struct modp_srp<6144> : public dl_group_info<6144> {
                typedef typename dl_group_info<6144>::p_type p_type;
                typedef std::size_t q_type;
                typedef std::size_t g_type;

                constexpr static const p_type p = 0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA18217C32905E462E36CE3BE39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9DE2BCBF6955817183995497CEA956AE515D2261898FA051015728E5A8AAAC42DAD33170D04507A33A85521ABDF1CBA64ECFB850458DBEF0A8AEA71575D060C7DB3970F85A6E1E4C7ABF5AE8CDB0933D71E8C94E04A25619DCEE3D2261AD2EE6BF12FFA06D98A0864D87602733EC86A64521F2B18177B200CBBE117577A615D6C770988C0BAD946E208E24FA074E5AB3143DB5BFCE0FD108E4B82D120A92108011A723C12A787E6D788719A10BDBA5B2699C327186AF4E23C1A946834B6150BDA2583E9CA2AD44CE8DBBBC2DB04DE8EF92E8EFC141FBECAA6287C59474E6BC05D99B2964FA090C3A2233BA186515BE7ED1F612970CEE2D7AFB81BDD762170481CD0069127D5B05AA993B4EA988D8FDDC186FFB7DC90A6C08F4DF435C93402849236C3FAB4D27C7026C1D4DCB2602646DEC9751E763DBA37BDF8FF9406AD9E530EE5DB382F413001AEB06A53ED9027D831179727B0865A8918DA3EDBEBCF9B14ED44CE6CBACED4BB1BDB7F1447E6CC254B332051512BD7AF426FB8F401378CD2BF5983CA01C64B92ECF032EA15D1721D03F482D7CE6E74FEF6D55E702F46980C82B5A84031900B1C9E59E7C97FBEC7E8F323A97A7E36CC88BE0F1D45B7FF585AC54BD407B22B4154AACC8F6D7EBF48E1D814CC5ED20F8037E0A79715EEF29BE32806A1D58BB7C5DA76F550AA3D8A1FBFF0EB19CCB1A313D55CDA56C9EC2EF29632387FE8D76E3C0468043E8F663F4860EE12BF2D5B0B7474D6E694F91E6DCC4024FFFFFFFFFFFFFFFF_cppui6144;
                constexpr static const q_type q = 0;
                constexpr static const g_type g = 0x5;
            };

            template<>
            struct modp_srp<8192> : public dl_group_info<8192> {
                typedef typename dl_group_info<8192>::p_type p_type;
                typedef std::size_t q_type;
                typedef std::size_t g_type;

                constexpr static const p_type p = 0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA18217C32905E462E36CE3BE39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9DE2BCBF6955817183995497CEA956AE515D2261898FA051015728E5A8AAAC42DAD33170D04507A33A85521ABDF1CBA64ECFB850458DBEF0A8AEA71575D060C7DB3970F85A6E1E4C7ABF5AE8CDB0933D71E8C94E04A25619DCEE3D2261AD2EE6BF12FFA06D98A0864D87602733EC86A64521F2B18177B200CBBE117577A615D6C770988C0BAD946E208E24FA074E5AB3143DB5BFCE0FD108E4B82D120A92108011A723C12A787E6D788719A10BDBA5B2699C327186AF4E23C1A946834B6150BDA2583E9CA2AD44CE8DBBBC2DB04DE8EF92E8EFC141FBECAA6287C59474E6BC05D99B2964FA090C3A2233BA186515BE7ED1F612970CEE2D7AFB81BDD762170481CD0069127D5B05AA993B4EA988D8FDDC186FFB7DC90A6C08F4DF435C93402849236C3FAB4D27C7026C1D4DCB2602646DEC9751E763DBA37BDF8FF9406AD9E530EE5DB382F413001AEB06A53ED9027D831179727B0865A8918DA3EDBEBCF9B14ED44CE6CBACED4BB1BDB7F1447E6CC254B332051512BD7AF426FB8F401378CD2BF5983CA01C64B92ECF032EA15D1721D03F482D7CE6E74FEF6D55E702F46980C82B5A84031900B1C9E59E7C97FBEC7E8F323A97A7E36CC88BE0F1D45B7FF585AC54BD407B22B4154AACC8F6D7EBF48E1D814CC5ED20F8037E0A79715EEF29BE32806A1D58BB7C5DA76F550AA3D8A1FBFF0EB19CCB1A313D55CDA56C9EC2EF29632387FE8D76E3C0468043E8F663F4860EE12BF2D5B0B7474D6E694F91E6DBE115974A3926F12FEE5E438777CB6A932DF8CD8BEC4D073B931BA3BC832B68D9DD300741FA7BF8AFC47ED2576F6936BA424663AAB639C5AE4F5683423B4742BF1C978238F16CBE39D652DE3FDB8BEFC848AD922222E04A4037C0713EB57A81A23F0C73473FC646CEA306B4BCBC8862F8385DDFA9D4B7FA2C087E879683303ED5BDD3A062B3CF5B3A278A66D2A13F83F44F82DDF310EE074AB6A364597E899A0255DC164F31CC50846851DF9AB48195DED7EA1B1D510BD7EE74D73FAF36BC31ECFA268359046F4EB879F924009438B481C6CD7889A002ED5EE382BC9190DA6FC026E479558E4475677E9AA9E3050E2765694DFC81F56E880B96E7160C980DD98EDD3DFFFFFFFFFFFFFFFFF_cppui8192;
                constexpr static const q_type q = 0;
                constexpr static const g_type g = 0x13;
            };

            /*!
             * @brief DSA group
             * @tparam PSize
             */
            template<std::size_t PSize>
            struct dsa_jce : public dl_group_info<PSize> {};

            template<>
            struct dsa_jce<1024> : public dl_group_info<1024> {
                typedef typename dl_group_info<1024>::p_type p_type;
                typedef number<backends::cpp_int_backend<160, 160, unsigned_magnitude, unchecked, void>> q_type;
                typedef p_type g_type;

                constexpr static const p_type p =
                    0xFD7F53811D75122952DF4A9C2EECE4E7F611B7523CEF4400C31E3F80B6512669455D402251FB593D8D58FABFC5F5BA30F6CB9B556CD7813B801D346FF26660B76B9950A5A49F9FE8047B1022C24FBBA9D7FEB7C61BF83B57E7C6A8A6150F04FB83F6D3C51EC3023554135A169132F675F3AE2B61D72AEFF22203199DD14801C7_cppui1024;
                constexpr static const q_type q = 0x9760508F15230BCCB292B982A2EB840BF0581CF5_cppui160;
                constexpr static const g_type g =
                    0x469603512E30278CD3947595DB22EEC9826A6322ADC97344F41D740C325724C8F9EFBAA7D4D803FF8C609DCD100EBC5BDFCFAD7C6A425FAEA786EA2050EBE98351EA1FDA1FDF24D6947AA6B9AA23766953802F4D7D4A8ECBA06D19768A2491FFB16D0EF9C43A99B5F71672FF6F0A24B444D0736D04D38A1A1322DAF6CDD88C9D_cppui1024;
            };

            template<std::size_t PSize>
            struct dsa_botan : public dl_group_info<PSize> {};

            template<>
            struct dsa_botan<2048> : public dl_group_info<2048> {
                typedef typename dl_group_info<2048>::p_type p_type;
                typedef number<backends::cpp_int_backend<256, 256, unsigned_magnitude, unchecked, void>> q_type;
                typedef p_type g_type;

                constexpr static const p_type p =
                    0x91C48A4FDFBCF7C02AE95E7DA126122B5DD2864F559B87E8E74A286D52F59BD1DE68DFD645D0E00C60C080031891980374EEB594A532BFD67B9A09EAC4B8663A07910E68F39465FB7040D25DF13932EBAC4347A530ECBA61C854F9B880D3C0C3660080587C45566DADE26BD5A394BE093B4C0F24B5AFFEF8EC6C5B3E57FB89025A9BC16769932131E16D3C94EFCAB18D0DF061203CC53E6103BC72D5594BFD40CA65380F44A9A851DCB075495FC033A8A58071A1BD78FE052F66555648EB4B719D2AFE8B4880F8DAD6F15818BA178F89274C870BE9B96EB08C46C40040CC2EFE1DFB1B1868DD319DE3C34A32A63AB6EB1224209A419680CC7902D1728D4DF9E1_cppui2048;
                constexpr static const q_type q =
                    0x8CD7D450F86F0AD94EEE4CE469A8756D1EBD1058241943EAFFB0B354585E924D_cppui256;
                constexpr static const g_type g =
                    0xD9F5E0761B4DBD1833D6AB1A961A0996C5F22303F72D84C140F67C431D94AB5715BEA81A0C98D39CE4BCF78D6B9EBC895D34FE89D94091D5848615EF15F5E86F11D96F6C969E203DDFA58356420A49CB444B595B901A933CFE0767B594F18A07B7F91DECDBA446B88990F78F2FF91F2FE7CD43FD2E46D18EADA1F7BB6602C617F6EF3A4B284F2FD9BA10A36042DE8FA87A2CA36597FEC81157A1485E44041DF02830111CB880BBE6ED494814886F965CDC3135F5CCF1383728BF65B806F9692C0B10D6C4C09C75A6CA3B4013CB16AB2C105F6BE23AEA9000EAB2178985F972C98057E1C86E44E7218688EA4AE0F3636DCCA745C9DCD4E6AFFB67CCBC13D6131_cppui2048;
            };

            template<>
            struct dsa_botan<3072> : public dl_group_info<3072> {
                typedef typename dl_group_info<3072>::p_type p_type;
                typedef number<backends::cpp_int_backend<256, 256, unsigned_magnitude, unchecked, void>> q_type;
                typedef p_type g_type;

                constexpr static const p_type p =
                    0xE4B50880759663585E142460CA2D9DFF132F8AE4C840DDA3A2666889124FE5638B84E8A29B7AF3FA1209BE6BFC4B5072ED3B2B7387BAF3F857F478A80228EF3600B76B3DCFB61D20D34465B2506D2CAF87DF6E7DC0CE91BD2D167A46F6ADCC31C531E4F9C7ABBDB92ADDF35B0A806C66292A5F5E17E964DD099903733AC428AB35D80EA6F685BFBA8BE4068E5418AE5ECAD9E8FF073DE2B63E4E7EAD35C8A9B70B5BD47CFB88D373B66F37931939B0AB71BD5595809086DA0155337D185A0E4FB36A519B1B6202B8591E6002449CF1CD3A66384F6D2073B1CD73BECA93BAF1E1A6117D0238F222AE1ED7FED185A890E7F67FAB8FEB9753CC134A5183DFE87AE2595F7B5C2D9FBB42249FDD59513E1D3396B3EB2FD86684F285A8448FE757A029881C40760B94EF919BDF9740C38389599EC51A6E9BB519A8E068491E9CE0A2FCFE3CB60D66CF0DFAD20A8EC684048684A61444575BD1724D7352B44A760077B3BD6BD385CE5B0A7250CC0BF768DA82923806EB9CFBB138843731B618208C759B_cppui3072;
                constexpr static const q_type q =
                    0xB3EBD364EC69EF8CF3BAF643B75734B16339B2E49E5CDE1B59C1E9FB40EE0C5B_cppui256;
                constexpr static const g_type g =
                    0x2BED21EEF83964A230AE89BBA71D9F7C39C52FC8229B4E3BC7E5944D329DA10F010EAC9E7BAF6C009FC4EB2960723E2B56DF4663E4C3AC800E9258DE2F7649D206782893F865EFCA498D2EEF30074EA5E8A7AB262712A4D94A2F3B0B9A92EE400FB38A3CC59A5DC7E436D5C004B22E35028381B51C93407EB32D4AE0FD42CB45E12D0ECEE8A26238EDE2082A7B1522113C66CEF8D745C6CF3CB945F84D2F4DE16D44A71DE198270E13F03553C88B8D323AD0B948A1BF2103A949979B6ED16FB5F3C953D95B7C8E88CA67DCF5A636FB9CA39D924215F7A884ED6C7EE3C96D8D9715427974B7C4351282E13D3773F7D28B452F10892A13C7587328DEA4827B6B369B2A8DC172ADC583F51F2A6598C5483E5BC467B02F91D059C402D18E2C2680F776AA06F49280A2C72C17CC42D5B6E740C5C4B1AB3C51C2ED092BE2A2D8B053AE5773D1425ED2B08F06E2DD50592DF1A478C15591CDFD11564FF88FF38B721D42392FDA473212DCFD8D2D88A976A00AFFE6FFFB430A359E64CA2B351CA2412394_cppui3072;
            };
        }    // namespace pubkey
    }        // namespace crypto3
}    // namespace nil

#endif    // CRYPTO3_DL_GROUP_INFO_HPP
