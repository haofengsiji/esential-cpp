#include <iostream>
#include <algorithm>
#include "Triangular.h"

using namespace std;

vector<int> Triangular::_elems;

Triangular::Triangular(int len, int beg_pos)
    :     _length(len > 0 ? len : 1),
    _beg_pos(beg_pos > 0 ? beg_pos : 1) {
    _next = _beg_pos - 1;
    int elem_cnt = _beg_pos + _length  - 1;
    if (_elems.size() < elem_cnt ) {
        gen_elements(elem_cnt);
    }
}

bool Triangular::next(int &value) const {
    if (_next < _beg_pos +_length - 1) {
        value = _elems[_next++];
        return true;
    }
    return false;
}

int Triangular::elem(int pos) const {
    return _elems[pos - 1];
}

Triangular& Triangular::copy(const Triangular &rhs) {
    if (this != &rhs) {
        _length = rhs._length;
        _beg_pos = rhs._beg_pos;
        _next = rhs.beg_pos() - 1;
    }
    return *this;
}

void Triangular::gen_elems_to_value(int value) {
    int ix = _elems.size();
    if(!ix) {
        _elems.push_back(1);
        ix = 1;
    }
    while(_elems[ix - 1] < value && ix < _max_elems) {
        ++ix;
        _elems.push_back(ix*(ix+1)/2);
    }
    if (ix == _max_elems) {
        cerr << "Triangular Sequence: oops: value too large"
            << value << "-- exceeds max size of "
            << _max_elems << endl;
    }
}

bool Triangular::is_elem(int value) {
    if(! _elems.size() || _elems[_elems.size() - 1] < value ) {
        gen_elems_to_value(value);
    }

    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();

    found_it = find(_elems.begin(), end_it, value);
    return found_it != end_it;
}

void Triangular::gen_elements(int length) {
    if (length < 0 || length > _max_elems) {
        cerr << "Wrong length";
        return;
    }

    if (_elems.size() < length) {
        int ix = _elems.size() ? _elems.size() + 1 : 1;
        for (; ix <= length; ++ix) {
            _elems.push_back(ix*(ix + 1)/ 2);
        }
    }
}

void Triangular::display(int length, int beg_pos, ostream& os) {
    if(length<=0 || beg_pos<=0){
         cerr << "invalid parameters -- unable to fulfill request: "
			  << length << ", " << beg_pos << endl;
		 return;
    }

    int elems=beg_pos+length-1;

    if(_elems.size()<elems){
        gen_elements(elems);
    }

    for (int next = beg_pos -  1; next < beg_pos + length - 1; ++next) {
        os << _elems[next] << ' ';
    }
}

istream& operator>>(istream &is, Triangular &rhs) {
    char ch1, ch2;
    int bp, len;

    is >> ch1 >> bp
        >> ch2 >> len;

    rhs.beg_pos(bp);
    rhs.length(len);
    rhs.next_reset();

    int elem_cnt = bp + len - 1;
    if (Triangular::elem_size() < elem_cnt)
        Triangular::gen_elements(elem_cnt);
    return is;

    return is;
}


ostream& operator<<(ostream &os, const Triangular &rhs) {
    os << "(" << rhs.beg_pos() << ", "
        << rhs.length() << " )";
    rhs.display(rhs.length(), rhs.beg_pos(), os);
    return os;
}
