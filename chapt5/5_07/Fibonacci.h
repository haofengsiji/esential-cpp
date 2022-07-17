#pragma once

#include "num_sequence.h"

class Fibonacci : public num_sequence {
public:
    Fibonacci(int len = 1, int beg_pos = 1 );
    virtual const string what_am_i () const { return "Fibonacci"; };

protected:
    virtual void gen_elems(int pos) const;
    static vector<int> _elems;
};