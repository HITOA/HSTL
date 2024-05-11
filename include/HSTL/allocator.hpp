//
// Created by HITO on 11/05/24.
//

#ifndef HSTL_ALLOCATOR_HPP
#define HSTL_ALLOCATOR_HPP

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

namespace HSTL {

    struct AllocBlk {
        void* ptr;
        size_t size;
    };

    template<size_t Alignment = 8U>
    class Allocator {
    public:
        Allocator() noexcept = default;
        ~Allocator() noexcept = default;

        AllocBlk allocate(size_t size) {
            AllocBlk blk{};
            blk.ptr = aligned_alloc(Alignment, size);
            blk.size = size;
            return blk;
        }
        AllocBlk reallocate(AllocBlk blk, size_t new_size) {
            AllocBlk new_blk{};
            new_blk.ptr = aligned_alloc(Alignment, new_size);
            new_blk.size = new_size;
            memcpy(new_blk.ptr, blk.ptr, blk.size);
            free(blk.ptr);
            return new_blk;
        }
        void deallocate(AllocBlk blk) {
            free(blk.ptr);
        }
    };

}

#endif //HSTL_ALLOCATOR_HPP
