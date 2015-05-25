
#ifndef BOOST_CONTRACT_OVERRIDE_HPP_
#define BOOST_CONTRACT_OVERRIDE_HPP_

/** @file */

#include <boost/contract/core/virtual.hpp>
#include <boost/contract/aux_/type_traits/introspection.hpp>
#include <boost/contract/aux_/name.hpp>
/** @cond */
#include <boost/preprocessor/cat.hpp>
/** @endcond */

/* PUBLIC */

#define BOOST_CONTRACT_OVERRIDE(f) \
    BOOST_CONTRACT_OVERRIDE_TRAIT(BOOST_PP_CAT(override_, f), f)

#define BOOST_CONTRACT_OVERRIDE_TRAIT(trait, f) \
    struct trait { \
        BOOST_CONTRACT_AUX_INTROSPECTION_HAS_MEMBER_FUNCTION( \
                BOOST_CONTRACT_AUX_NAME1(has_member_function), f) \
    \
        template< \
            class BOOST_CONTRACT_AUX_NAME1(B), \
            class BOOST_CONTRACT_AUX_NAME1(C), \
            typename BOOST_CONTRACT_AUX_NAME1(A0) \
        > \
        static void BOOST_CONTRACT_AUX_NAME1(base_call)( \
            BOOST_CONTRACT_AUX_NAME1(C)* BOOST_CONTRACT_AUX_NAME1(obj), \
            BOOST_CONTRACT_AUX_NAME1(A0)& BOOST_CONTRACT_AUX_NAME1(a0), \
            boost::contract::virtual_* BOOST_CONTRACT_AUX_NAME1(v) \
        ) { \
            BOOST_CONTRACT_AUX_NAME1(obj)->BOOST_CONTRACT_AUX_NAME1(B)::f( \
                BOOST_CONTRACT_AUX_NAME1(a0), \
                BOOST_CONTRACT_AUX_NAME1(v) \
            ); \
        } \
    };

#endif // #include guard

