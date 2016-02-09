
#ifndef BOOST_CONTRACT_SET_PRECONDITION_OLD_POSTCONDITION_HPP_
#define BOOST_CONTRACT_SET_PRECONDITION_OLD_POSTCONDITION_HPP_

// Copyright (C) 2008-2016 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0 (see accompanying
// file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt).
// See: http://www.boost.org/doc/libs/release/libs/contract/doc/html/index.html

/** @file */

#include <boost/contract/core/set_old_postcondition.hpp>
#include <boost/contract/core/set_postcondition_only.hpp>
#include <boost/contract/core/set_nothing.hpp>
#include <boost/contract/core/config.hpp>
#include <boost/contract/aux_/decl.hpp>
#if BOOST_CONTRACT_PRECONDITIONS || BOOST_CONTRACT_POSTCONDITIONS || \
        BOOST_CONTRACT_INVARIANTS
    #include <boost/contract/aux_/condition/check_pre_post.hpp>
    #include <boost/contract/aux_/auto_ptr.hpp>
    #include <boost/contract/aux_/none.hpp>
#endif
#if BOOST_CONTRACT_PRECONDITIONS || BOOST_CONTRACT_POSTCONDITIONS
    #include <boost/contract/aux_/debug.hpp>
#endif
#include <boost/config.hpp>

namespace boost {
    namespace contract {
        class virtual_;
    }
}

namespace boost { namespace contract {
    
template<typename R = void>
class set_precondition_old_postcondition { // Copyable (as *).
public:
    ~set_precondition_old_postcondition() BOOST_NOEXCEPT_IF(false) {}
    
    template<typename F>
    set_old_postcondition<R> precondition(F const& f) {
        #if BOOST_CONTRACT_PRECONDITIONS
            BOOST_CONTRACT_AUX_DEBUG(check_);
            check_->set_pre(f);
        #endif
        #if BOOST_CONTRACT_PRECONDITIONS || BOOST_CONTRACT_POSTCONDITIONS || \
                BOOST_CONTRACT_INVARIANTS
            return set_old_postcondition<R>(check_.release());
        #else
            return set_old_postcondition<R>();
        #endif
    }

    template<typename F>
    set_postcondition_only<R> old(F const& f) {
        #if BOOST_CONTRACT_POSTCONDITIONS
            BOOST_CONTRACT_AUX_DEBUG(check_);
            check_->set_old(f);
        #endif
        #if BOOST_CONTRACT_PRECONDITIONS || BOOST_CONTRACT_POSTCONDITIONS || \
                BOOST_CONTRACT_INVARIANTS
            return set_postcondition_only<R>(check_.release());
        #else
            return set_postcondition_only<R>();
        #endif
    }

    template<typename F>
    set_nothing postcondition(F const& f) {
        #if BOOST_CONTRACT_POSTCONDITIONS
            BOOST_CONTRACT_AUX_DEBUG(check_);
            check_->set_post(f);
        #endif
        #if BOOST_CONTRACT_PRECONDITIONS || BOOST_CONTRACT_POSTCONDITIONS || \
                BOOST_CONTRACT_INVARIANTS
            return set_nothing(check_.release());
        #else
            return set_nothing();
        #endif
    }

private:
    #if BOOST_CONTRACT_PRECONDITIONS || BOOST_CONTRACT_POSTCONDITIONS || \
            BOOST_CONTRACT_INVARIANTS
        typedef boost::contract::aux::check_pre_post<typename
                boost::contract::aux::none_if_void<R>::type> check_type;

        explicit set_precondition_old_postcondition(check_type* check) :
                check_(check) {}

        boost::contract::aux::auto_ptr<check_type> check_;
    #endif

    // Friends (used to limit library's public API).

    friend class guard;

    friend set_precondition_old_postcondition<> function();

    template<class CC>
    friend set_precondition_old_postcondition<> public_function();

    template<class CC>
    friend set_precondition_old_postcondition<> public_function(CC* oobj);
    
    template<class CC>
    friend set_precondition_old_postcondition<> public_function(
            virtual_* vv, CC* oobj);

    template<typename RR, class CC>
    friend set_precondition_old_postcondition<RR> public_function(
            virtual_* vv, RR& rr, CC* oobj);

    BOOST_CONTRACT_AUX_DECL_FRIEND_OVERRIDING_PUBLIC_FUNCTIONS_Z(1,
            OO, RR, FF, CC, AArgs, vv, rr, ff, oobj, aargs)
};

} } // namespace

#endif // #include guard

