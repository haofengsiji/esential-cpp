#include "Triangular.h"

bool has_elem(Triangular_iterator first, Triangular_iterator last, int elem) {


    bool status = true;
    try {
        while(first != last) {
            if (*first == elem) {
                return status;
            }
            ++first;
        }
    }

    catch(iterator_overflow &iof) {
        log_message(iof.what_happend());
        log_message("check if iterators address same container");
    }

    status = false;
    return status;
}