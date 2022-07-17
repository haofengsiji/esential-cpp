#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

void display_message(const string&, const vector<int>&);
void display_message(const string&, const vector<double>&);
void display_message(const string&, const vector<string>&);

template <typename elemType>
void display_message(const string&msg, const vector<elemType>&vec) {
  cout << msg;
  for (int ix = 0; ix < vec.size(); ++ix) {
    cout << vec[ix] << ' ';
  }
  cout << '\n';
}

void display_message(const string&msg, ostream &os=cout) {
  os << msg;
  os << '\n';
}


bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int)) {
  if (!seq_ptr) {
    display_message("Internal Error: seq_ptr is set to null!");
  }
  const vector<int> *pseq = seq_ptr(pos);

  if (!pseq) {
    elem = 0;
    return false;
  }

  elem = (*pseq)[pos - 1];
  return true;
}

 enum ns_type {
    ns_fibon, ns_lucas, ns_pell,
    ns_triang, ns_square, ns_pent
  };


int main()
{

}