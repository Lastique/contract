
#ifndef BOOST_CONTRACT_EXT_PP_KEYWROD_REMOVE_HPP_
#define BOOST_CONTRACT_EXT_PP_KEYWROD_REMOVE_HPP_

#include <boost/preprocessor/cat.hpp>

/* PRIVATE */

// Extra level of indirection needed for proper macro expansion (on MSVC).
#define BOOST_CONTRACT_EXT_PP_KEYWORD_UTILITY_REMOVE_EXPAND_(x) x

// Extra level of indirection needed for proper macro expansion (on MSVC).
#define BOOST_CONTRACT_EXT_PP_KEYWORD_UTILITY_REMOVE_CAT_(a, b) \
    BOOST_CONTRACT_EXT_PP_KEYWORD_UTILITY_REMOVE_EXPAND_( \
            BOOST_PP_CAT(a, b))

/* PUBLIC */

// Precondition: A macro named `cat_to_empty_prefix ## token-to-remove` must be
//               #defined to expand to empty ``.
// Precondition: tokens must start with the token to be removed (this can be
//               checked with `..._IS_..._FRONT` macros).
#define BOOST_CONTRACT_EXT_PP_KEYWORD_UTILITY_REMOVE_FRONT( \
        cat_to_empty_prefix, tokens) \
    BOOST_CONTRACT_EXT_PP_KEYWORD_UTILITY_REMOVE_CAT_( \
            cat_to_empty_prefix, tokens)

// Precondition: A macro named `token-to-remove ## cat_to_empty_postfix` must be
//               #defined to expand to empty ``.
// Precondition: tokens must end with the token to be removed (this can be
//               checked with `..._IS_..._BACK` macros).
#define BOOST_CONTRACT_EXT_PP_KEYWORD_UTILITY_REMOVE_BACK( \
        cat_to_empty_postfix, tokens) \
    BOOST_CONTRACT_EXT_PP_KEYWORD_UTILITY_REMOVE_CAT_( \
            tokens, cat_to_empty_postfix)

#endif // #include guard

