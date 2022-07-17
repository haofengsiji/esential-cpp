#pragma once
#include <iostream>

using namespace std;

class LessThan {
    public:
        LessThan(int val) : _val(val) {}
        int comp_val() const {return _val;}
        void comp_val(int nval) {_val = nval;}

        bool operator() (int value) const;
    private:
        int _val; 
};


inline bool LessThan::operator() (int value) const {
    return value < _val;
}

