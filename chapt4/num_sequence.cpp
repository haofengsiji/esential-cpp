#include "num_sequence.h"

const int num_sequence::num_seq;
vector<vector<int> > num_sequence::seq(num_seq);

typedef num_sequence::PtrType PtrType;

PtrType num_sequence::func_tbl[num_seq] =
{
    0,
    &num_sequence::fibonacci,
    &num_sequence::pell,
    &num_sequence::lucas,
    &num_sequence::triangular,
    &num_sequence::square,
    &num_sequence::pentagonal
};

int num_sequence::elem(int pos) {
    if (! check_integrity(pos)) {
        return 0;
    }

    if (pos > _elem->size()) {
        (this->*_pmf)(pos);
    }

    return (*_elem)[pos-1];
}

void num_sequence::set_sequence(ns_type nst)
