#include "Fibonacci.h"

vector<int> Fibonacci::_elems;

int Fibonacci::elem( int pos ) const {
    if (! check_integrity(pos, _elems.size()) ) {
        return 0;
    }
    if (pos > _elems.size()) {
        Fibonacci::gen_elems(pos);
    }
    return _elems[pos - 1];
}


void Fibonacci::gen_elems(int pos) const {
    cout << "Fibonacci::gen_elems" << '\n';
    if(_elems.empty()) {
        _elems.push_back(1);
        _elems.push_back(1);
    }

    if (_elems.size() < pos) {
        int ix = _elems.size();
        int n_2 = _elems[ix-2];
        int n_1 = _elems[ix-1];

        for (; ix <= pos; ++ix) {
            int elem = n_2 + n_1;
            _elems.push_back(elem);
            n_2 = n_1;
            n_1 = elem;
        }
    }
}