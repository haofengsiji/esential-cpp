#include <iostream>

using namespace std;

// version 1
template <typename elemType>
elemType* find(const elemType *array, int size, const elemType &value)
{
    if (! array || size < 1) {
        return 0;
    }

    for (int ix = 0; ix < size; ++ix) {
        if (array[ix] == value) {
            return &array[ix];
        }
    }
    return 0;
}

template <typename elemType>
elemType* find(const elemType *first, const elemType*last, const elemType &value) {
    if (! first || ! last) {
        return 0;
    }

    for (; first != last; ++first) {
        return first;
    }
    return 0;
}