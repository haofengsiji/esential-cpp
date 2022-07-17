#include "num_sequence.h"


bool num_sequence::check_integrity(int pos, int size) const {
    if (pos <=0 || pos > max_elems()) {
        cerr << "!! invalid position: " << pos 
            << " Cannot honor request\n";
        return false;
    }

    if (pos > size) {
        gen_elems(pos);
    }
    
    return true;
}

ostream &operator<<(ostream &os, const num_sequence &ns) {
  return ns.print(os);
}


ostream& num_sequence::print(ostream &os) const {
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;

    if (end_pos > _relems.size()) {
        gen_elems(end_pos);
    }

    os << "( " << _beg_pos << ", "
        << _length << " ) ";
        
    while(elem_pos < end_pos) {
        os << _relems[elem_pos++] << ' ';
    }
    return os;
}
