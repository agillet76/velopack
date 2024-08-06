// Automatically generated by flapigen
#pragma once

//for assert
#include <cassert>
//for std::abort
#include <cstdlib>
//for std::move
#include <utility>
//for std::conditional
#include <type_traits>

#include <stdint.h>

#include "c_Foo.h"

namespace velopack_cpp {

template<bool>
class FooWrapper;
using Foo = FooWrapper<true>;
using FooRef = FooWrapper<false>;


template<bool OWN_DATA>
class FooWrapper {
public:
    using value_type = FooWrapper<true>;
    friend class FooWrapper<true>;
    friend class FooWrapper<false>;

    using SelfType = typename std::conditional<OWN_DATA, FooOpaque *, const FooOpaque *>::type;
    using CForeignType = FooOpaque;

    FooWrapper(FooWrapper &&o) noexcept: self_(o.self_)
    {
        o.self_ = nullptr;
    }
    FooWrapper &operator=(FooWrapper &&o) noexcept
    {
        assert(this != &o);
        free_mem(this->self_);
        self_ = o.self_;
        o.self_ = nullptr;
        return *this;
    }
    explicit FooWrapper(SelfType o) noexcept: self_(o) {}
    FooOpaque *release() noexcept
    {
        FooOpaque *ret = self_;
        self_ = nullptr;
        return ret;
    }
    explicit operator SelfType() const noexcept { return self_; }
    FooWrapper<false> as_rref() const noexcept { return FooWrapper<false>{ self_ }; }
    const FooWrapper<true> &as_cref() const noexcept { return reinterpret_cast<const FooWrapper<true> &>(*this); }

    FooWrapper(const FooWrapper&) = delete;
    FooWrapper &operator=(const FooWrapper&) = delete;

    FooWrapper(int32_t val) noexcept
    {

        this->self_ = Foo_new(val);
        if (this->self_ == nullptr) {
            std::abort();
        }
    }

    int32_t f(int32_t a, int32_t b) const noexcept;
    //Custom doc comment
    void setField(int32_t v) noexcept;

private:
   static void free_mem(SelfType &p) noexcept
   {
        if (OWN_DATA && p != nullptr) {
            Foo_delete(p);
        }
        p = nullptr;
   }
public:
    ~FooWrapper() noexcept
    {
        free_mem(this->self_);
    }

private:
    SelfType self_;
};


    template<bool OWN_DATA>
    inline int32_t FooWrapper<OWN_DATA>::f(int32_t a, int32_t b) const noexcept
    {

        int32_t ret = Foo_f(this->self_, a, b);
        return ret;
    }

    template<bool OWN_DATA>
    inline void FooWrapper<OWN_DATA>::setField(int32_t v) noexcept
    {

        Foo_setField(this->self_, v);
    }

} // namespace velopack_cpp
