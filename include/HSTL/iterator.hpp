//
// Created by HITO on 11/05/24.
//

#ifndef HSTL_ITERATOR_HPP
#define HSTL_ITERATOR_HPP

#include <stddef.h>

namespace HSTL {

#ifndef HSTL_USE_STD_ITERATOR_TAG
    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag       : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };
    struct contiguous_iterator_tag    : public random_access_iterator_tag { };
#elif
    #include <iterator>
    using namespace std;
#endif

    template<typename Iterator>
    struct IteratorTraits {
        using iterator_category = typename Iterator::iterator_category;
        using difference_type   = typename Iterator::difference_type;
        using value_type        = typename Iterator::value_type;
        using pointer           = typename Iterator::pointer;
        using reference         = typename Iterator::reference;
    };

    template<typename T>
    struct IteratorTraits<T*> {
        using iterator_category = random_access_iterator_tag;
        using difference_type   = ptrdiff_t;
        using value_type        = T;
        using pointer           = value_type*;
        using reference         = value_type&;
    };

    template<typename T>
    struct IteratorTraits<const T*> {
        using iterator_category = random_access_iterator_tag;
        using difference_type   = ptrdiff_t;
        using value_type        = T;
        using pointer           = const value_type*;
        using reference         = const value_type&;
    };

    template<typename Iterator>
    struct ReverseIterator {
        using iterator_category = typename IteratorTraits<Iterator>::iterator_category;
        using difference_type   = typename IteratorTraits<Iterator>::difference_type ;
        using value_type        = typename IteratorTraits<Iterator>::value_type;
        using pointer           = typename IteratorTraits<Iterator>::pointer;
        using reference         = typename IteratorTraits<Iterator>::reference;

        ReverseIterator() = default;
        explicit ReverseIterator(Iterator iterator) : iterator{ iterator } {}

        reference operator*() const {
            Iterator i{ iterator };
            return *--i;
        }
        pointer operator->() { return &(operator*()); }
        ReverseIterator& operator++() {
            --iterator;
            return *this;
        }
        ReverseIterator operator++(int) {
            ReverseIterator tmp = *this;
            --(*this);
            return tmp;
        }
        ReverseIterator& operator--() {
            ++iterator;
            return *this;
        }
        ReverseIterator operator--(int) {
            ReverseIterator tmp = *this;
            ++(*this);
            return tmp;
        }
        ReverseIterator& operator+=(difference_type n) {
            iterator -= n;
            return *this;
        }
        ReverseIterator& operator-=(difference_type n) {
            iterator += n;
            return *this;
        }
        friend ReverseIterator operator+(ReverseIterator lhs, difference_type rhs) {
            lhs += rhs;
            return lhs;
        }
        friend ReverseIterator operator-(ReverseIterator lhs, difference_type rhs) {
            lhs -= rhs;
            return lhs;
        }
        friend difference_type operator-(const ReverseIterator& lhs, const ReverseIterator& rhs) {
            return rhs.iterator - lhs.iterator;
        }
        friend bool operator==(const ReverseIterator& rhs, const ReverseIterator& lhs) { return rhs.iterator == lhs.iterator; }
        friend bool operator!=(const ReverseIterator& rhs, const ReverseIterator& lhs) { return rhs.iterator != lhs.iterator; }
        friend bool operator<(const ReverseIterator& rhs, const ReverseIterator& lhs) { return lhs - rhs > 0; }
        friend bool operator>(const ReverseIterator& rhs, const ReverseIterator& lhs) { return lhs < rhs; }
        friend bool operator<=(const ReverseIterator& rhs, const ReverseIterator& lhs) { return !(rhs > lhs); }
        friend bool operator>=(const ReverseIterator& rhs, const ReverseIterator& lhs) { return !(rhs < lhs); }

    private:
        Iterator iterator{};
    };

}

#endif //HSTL_ITERATOR_HPP
