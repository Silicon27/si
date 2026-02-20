//
// Created by David Yang on 2026-02-20.
//

#ifndef SI_REVERSE_ITERATOR_HPP
#define SI_REVERSE_ITERATOR_HPP

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

template <typename Iter>
class reverse_iterator {
public:
    using iterator_type = Iter;
    using value_type = typename Iter::value_type;
    using difference_type = typename Iter::difference_type;
    using pointer = typename Iter::pointer;
    using reference = typename Iter::reference;

    reverse_iterator() : current() {}

    explicit reverse_iterator(Iter it) : current(it) {}

    Iter base() const { return current; }

    reference operator*() const { return *--current; }
    pointer operator->() const { return &(operator*()); }

    reverse_iterator& operator++() { --current; return *this; }
    reverse_iterator operator++(int) { reverse_iterator tmp(*this); --current; return tmp; }
    reverse_iterator& operator--() { ++current; return *this; }
    reverse_iterator operator--(int) { reverse_iterator tmp(*this); ++current; return tmp; }
private:
    Iter current;
};

SI_NAMESPACE_END

#endif //SI_REVERSE_ITERATOR_HPP