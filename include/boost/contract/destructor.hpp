
#ifndef BOOST_CONTRACT_DESTRUCTOR_HPP_
#define BOOST_CONTRACT_DESTRUCTOR_HPP_

// Copyright (C) 2008-2016 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0 (see accompanying
// file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt).
// See: http://www.boost.org/doc/libs/release/libs/contract/doc/html/index.html

// TODO: Document that if destructor contract throws (set_post_failure and/or set_old_failure configured to throw) for a derived class, the base class object it still constructed so it will base's check inv (not just static) and also base's .except() (see destructor-throwing_old and destructor-throwing_post tests).

/** @file
Program contracts for destructors.
*/

#include <boost/contract/core/config.hpp>
#include <boost/contract/core/specify.hpp>
#include <boost/contract/core/access.hpp>
#if     defined(BOOST_CONTRACT_STATIC_LINK) || \
        !defined(BOOST_CONTRACT_NO_DESTRUCTORS) || \
        !defined(BOOST_CONTRACT_NO_PRECONDITIONS)
    #include <boost/contract/detail/operation/destructor.hpp>
#endif

namespace boost { namespace contract {

/**
Program contracts for destructors.
This is used to specify postconditions, old value assignments at body, and check
class invariants for destructors (destructors cannot not have preconditions, see
@RefSect{contract_programming_overview, Contract Programming Overview}).

For optimization, this can be omitted for destructors that do not have
postconditions when the enclosing class has no invariants.
@see @RefSect{tutorial, Tutorial}
@param obj The object @c this from the scope of the contracted destructor.
@return The result of this function must be assigned to a variable of type
        @RefClass{boost::contract::guard} declared locally just before the body
        of the contracted destructor (otherwise this library will generate a
        run-time error, see @RefMacro{BOOST_CONTRACT_ON_MISSING_GUARD}).
*/
template<class Class>
specify_old_postcondition_except<> destructor(Class* obj) {
    // Must #if also on ..._PRECONDITIONS here because specify_... is generic.
    #if     defined(BOOST_CONTRACT_STATIC_LINK) || \
            !defined(BOOST_CONTRACT_NO_DESTRUCTORS) || \
            !defined(BOOST_CONTRACT_NO_PRECONDITIONS)
        return specify_old_postcondition_except<>(
                new boost::contract::detail::destructor<Class>(obj));
    #else
        return specify_old_postcondition_except<>();
    #endif
}

} } // namespace

#endif // #include guard

