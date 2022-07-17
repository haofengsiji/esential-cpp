#include "NumericSeq.h"

void display(const vector<int> &vec, ostream &os) {
  for (int ix = 0; ix < vec.size(); ++ix) {
    os << vec[ix] << ' ';
  }
  os << endl;
}
