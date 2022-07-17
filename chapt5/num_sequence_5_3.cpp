#include "num_sequence_5_3.h"



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
    if (!check_integrity(pos)) {
        return 0;
    }

    if (pos > _elem->size()) {
        (this->*_pmf)(pos);
    }

    return (*_elem)[pos-1];
}

int num_sequence::elem(int pos) const {
    if (!check_integrity(pos)) {
        return 0;
    }

    if (pos > _elem->size()) {
        return 0;
    }

    return (*_elem)[pos-1];
}

void num_sequence::set_sequence(ns_type nst) {
    switch (nst)
    {
        default:
            cerr << "invalid type: setting to 0 \n";
        
        case ns_unset:
            _pmf = 0;
            _elem = 0;
            _isa = ns_unset;
            break;

        case ns_fibonacci: case ns_pell: case ns_lucas:
        case ns_triangular: case ns_square: case ns_pentagonal:
            _pmf = func_tbl[nst];
            _elem = &seq[nst];
            _isa = nst;
            break;

    }
}


const string num_sequence::what_am_i() const {
    static string names[num_seq] = {
        "notSet",
        "fibonacci", "pell",
        "lucas", "triangular",
        "square", "pentagonal"
        
    };
    
    return names[_isa];
}


