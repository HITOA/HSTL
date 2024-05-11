//
// Created by HITO on 11/05/24.
//

#ifndef HSTL_ARRAY_HPP
#define HSTL_ARRAY_HPP

#include <stddef.h>
#include <HSTL/iterator.hpp>

namespace HSTL {

    template<class T, size_t N = 1>
    class Array {
    public:
        using Iterator = T*;
        using ConstIterator = const T*;
        using ReverseIterator = HSTL::ReverseIterator<Iterator>;
        using ConstReverseIterator = HSTL::ReverseIterator<ConstIterator>;

        //Iterator

        Iterator begin() { return Iterator{ buff }; }
        Iterator end() { return Iterator{ buff + N }; }
        ConstIterator begin() const { return ConstIterator{ buff }; }
        ConstIterator end() const { return ConstIterator{ buff + N }; }
        ConstIterator cbegin() const { return ConstIterator{ buff }; }
        ConstIterator cend() const { return ConstIterator{ buff + N }; }
        ReverseIterator rbegin() { return ReverseIterator{ buff + N }; }
        ReverseIterator rend() { return ReverseIterator{ buff }; }
        ConstReverseIterator rbegin() const { return ConstReverseIterator{ buff + N }; }
        ConstReverseIterator rend() const { return ConstReverseIterator{ buff }; }
        ConstReverseIterator crbegin() const { return ConstReverseIterator{ buff + N}; }
        ConstReverseIterator crend() const { return ConstReverseIterator{ buff }; }

        //Element Access

        constexpr T& at(size_t idx) { return buff[idx]; }
        constexpr const T& at(size_t idx) const { return buff[idx]; }
        constexpr T& operator[](size_t idx) { return buff[idx]; }
        constexpr const T& operator[](size_t idx) const { return buff[idx]; }
        constexpr T* data() { return buff; }
        constexpr const T* data() const { return buff; }
        constexpr T& front() { return *buff; }
        constexpr const T& front() const { return *buff; }
        constexpr T& back() { return buff[N - 1]; }
        constexpr const T& back() const { return buff[N - 1]; }

        //Capacity

        [[nodiscard]] constexpr bool empty() const noexcept { return N > 0; }
        constexpr size_t size() const noexcept { return N; }
        constexpr size_t max_size() const noexcept { return N; }

        //Modifiers

        void swap(Array& array) noexcept {
            T* tmp = buff;
            buff = array.buff;
            array.buff = tmp;
        }

    private:
        T buff[N]{};
    };

    template<class T>
    class Array<T, 0> {
    public:
        using Iterator = T*;
        using ConstIterator = const T*;
        using ReverseIterator = HSTL::ReverseIterator<Iterator>;
        using ConstReverseIterator = HSTL::ReverseIterator<ConstIterator>;

        //Iterator

        Iterator begin() { return Iterator{ nullptr }; }
        Iterator end() { return Iterator{ nullptr }; }
        ConstIterator begin() const { return ConstIterator{ nullptr }; }
        ConstIterator end() const { return ConstIterator{ nullptr }; }
        ConstIterator cbegin() const { return ConstIterator{ nullptr }; }
        ConstIterator cend() const { return ConstIterator{ nullptr }; }
        ReverseIterator rbegin() { return ReverseIterator{ nullptr }; }
        ReverseIterator rend() { return ReverseIterator{ nullptr }; }
        ConstReverseIterator rbegin() const { return ConstReverseIterator{ nullptr }; }
        ConstReverseIterator rend() const { return ConstReverseIterator{ nullptr }; }
        ConstReverseIterator crbegin() const { return ConstReverseIterator{ nullptr }; }
        ConstReverseIterator crend() const { return ConstReverseIterator{ nullptr }; }

        //Element Access

        constexpr T* data() { return nullptr; }
        constexpr const T* data() const { return nullptr; }
        constexpr T& at(size_t idx) { return *data(); }
        constexpr const T& at(size_t idx) const { return *data(); }
        constexpr T& operator[](size_t idx) { return *data(); }
        constexpr const T& operator[](size_t idx) const { return *data(); }
        constexpr T& front() { return *data(); }
        constexpr const T& front() const { return *data(); }
        constexpr T& back() { return *data(); }
        constexpr const T& back() const { return *data(); }

        //Capacity

        [[nodiscard]] constexpr bool empty() const noexcept { return true; }
        constexpr size_t size() const noexcept { return 0; }
        constexpr size_t max_size() const noexcept { return 0; }

        //Modifiers

        void swap(Array& array) noexcept {}
    };

}

#endif //HSTL_ARRAY_HPP
