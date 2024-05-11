//
// Created by HITO on 11/05/24.
//

#ifndef HSTL_ALLOCATOR_HPP
#define HSTL_ALLOCATOR_HPP

#include <cstddef>
#include <cstdlib>

namespace HSTL {

    struct AllocBlk {
        void* ptr;
        size_t size;
    };

    template<size_t Alignment = 8U>
    class Mallocator {
    public:
        Mallocator() noexcept = default;
        ~Mallocator() noexcept = default;

        AllocBlk allocate(size_t size) {
            AllocBlk blk{};
            blk.ptr = aligned_alloc(Alignment, size);
            blk.size = size;
            return blk;
        }
        void deallocate(AllocBlk blk) {
            free(blk.ptr);
        }
    };

}

#endif //HSTL_ALLOCATOR_HPP
