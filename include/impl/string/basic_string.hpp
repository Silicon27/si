//
// Created by David Yang on 2025-10-11.
//

#ifndef BASIC_STRING_HPP
#define BASIC_STRING_HPP

#include "../../compat/sconfig.h"
#include "../../si/memory.hpp"
#include "char_traits.hpp"

SI_NAMESPACE_START

template <
    typename CharT,
    typename Traits = char_traits<CharT>,
    typename Allocator = allocator<CharT>
>
class basic_string {
    CharT* m_data;
    size_t m_size;
    size_t m_capacity;
    Allocator m_allocator;
public:
    using value_type = CharT;
    using traits_type = Traits;
    using allocator_type = Allocator;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator = pointer;
    using const_iterator = const_pointer;

    basic_string() noexcept = default; // default
    explicit basic_string(const allocator_type& alloc) noexcept : m_data(nullptr), m_size(0), m_capacity(0),
                                                                  m_allocator(alloc) {} // allocator aware default
    

};

SI_NAMESPACE_END

#endif //BASIC_STRING_HPP
