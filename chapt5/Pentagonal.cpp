#include "Pentagonal.h"

vector<int> Pentagonal::_elems;

int Pentagonal::elem( int pos ) const {
    if (! check_integrity(pos) ) {
        return 0;
    }
    if (pos > _elems.size()) {
        Pentagonal::gen_elems(pos);
    }
    return _elems[pos - 1];
}


void Pentagonal::gen_elems(int pos) const {
    if(_elems.empty()) {
        _elems.push_back(1);
        _elems.push_back(3);
    }

    if (_elems.size() < pos) {
        int ix = _elems.size();

        for (; ix <= pos; ++ix) {
            _elems.push_back((ix + 1)* (3*(ix + 1) - 1)/2);
        }
    }

}

ostream& Pentagonal::print(ostream &os) const {
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;

    if (end_pos > _elems.size()) {
        Pentagonal::gen_elems(end_pos);
    }

    os << "( " << _beg_pos << ", "
        << _length << " ) ";
        
    while(elem_pos < end_pos) {
        os << _elems[elem_pos++] << ' ';
    }
    return os;
}