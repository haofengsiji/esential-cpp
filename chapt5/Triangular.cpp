#include "Triangular.h"

vector<int> Triangular::_elems;

int Triangular::elem( int pos ) const {
    if (! check_integrity(pos) ) {
        return 0;
    }
    if (pos > _elems.size()) {
        Triangular::gen_elems(pos);
    }
    return _elems[pos - 1];
}


void Triangular::gen_elems(int pos) const {
    if(_elems.empty()) {
        _elems.push_back(1);
        _elems.push_back(3);
    }

    if (_elems.size() < pos) {
        int ix = _elems.size();
        int n_2 = _elems[ix-2];
        int n_1 = _elems[ix-1];

        for (; ix <= pos; ++ix) {
            _elems.push_back((ix + 1)*(ix + 2)/ 2);
        }
    }

}

ostream& Triangular::print(ostream &os) const {
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;

    if (end_pos > _elems.size()) {
        Triangular::gen_elems(end_pos);
    }

    os << "( " << _beg_pos << ", "
        << _length << " ) ";

    while(elem_pos < end_pos) {
        os << _elems[elem_pos++] << ' ';
    }
    return os;
}