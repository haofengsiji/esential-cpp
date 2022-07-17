#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class num_sequence {
public:
  virtual ~num_sequence(){};
  const string what_am_i() const { return typeid(*this).name(); }
  virtual int elem(int pos) const = 0;
  ostream &print(ostream &os = cout) const;

  int length() const { return _length; }
  int beg_pos() const { return _beg_pos; }
  static int max_elems() { return 64; }
  virtual void gen_elems(int pos) const { cout << "num_sequence::gen_elems" << '\n'; }

protected:
  
  bool check_integrity(int pos, int size) const;

  num_sequence(int len, int bp, vector<int> &re) 
    : _length(len), _beg_pos(bp), _relems(re) {}

  int _length;
  int _beg_pos;
  vector<int> & _relems; 
};


inline void display(ostream &os, const num_sequence &ns, int pos) {
  os << "The element at position " 
    << pos << " for the "
    << ns.what_am_i() << " sequence is "
    << ns.elem(pos) << endl;
}

