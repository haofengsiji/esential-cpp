#include "Pell.h"

vector<int> Pell::_elems;

int Pell::elem( int pos ) const {
    if (! check_integrity(pos) ) {
        return 0;
    }
    if (pos > _elems.size()) {
        Pell::gen_elems(pos);
    }
    return _elems[pos - 1];
}


void Pell::gen_elems(int pos) const {
    if(_elems.empty()) {
        _elems.push_back(1);
        _elems.push_back(2);
    }

    if (_elems.size() < pos) {
        int ix = _elems.size();
        int n_2 = _elems[ix-2];
        int n_1 = _elems[ix-1];

        for (; ix <= pos; ++ix) {
            int elem = n_2 + 2*n_1;
            _elems.push_back(elem);
            n_2 = n_1;
            n_1 = elem;
        }
    }
}

ostream& Pell::print(ostream &os) const {
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;

    if (end_pos > _elems.size()) {
        Pell::gen_elems(end_pos);
    }

    os << "( " << _beg_pos << ", "
        << _length << " ) ";
        
    while(elem_pos < end_pos) {
        os << _elems[elem_pos++] << ' ';
    }
    return os;
}