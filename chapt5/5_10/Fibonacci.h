#pragma once

#include "num_sequence.h"

class Fibonacci : public num_sequence {
public:
  Fibonacci(int len = 1, int beg_pos = 1);
  virtual int elem( int pos ) const;
  virtual void gen_elems(int pos) const;

protected:
  
  static vector<int> _elems;
};

inline Fibonacci::Fibonacci(int len, int beg_pos)
    : num_sequence(len, beg_pos, _elems) {}

