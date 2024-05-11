//
// Created by HITO on 11/05/24.
//

#include <HSTL/array.hpp>
#include <stdio.h>
#include <algorithm>

int main() {

    HSTL::Array<int, 4> myIntArray{};
    myIntArray[0] = 2;
    myIntArray[1] = 7;
    myIntArray[2] = 3;
    myIntArray[3] = 1;

    std::sort(myIntArray.rbegin(), myIntArray.rend());

    for (auto i : myIntArray) {
        printf("%i\n", i);
    }

    return 0;
}