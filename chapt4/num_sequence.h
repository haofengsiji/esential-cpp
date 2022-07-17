#pragma once

#include <iostream>
#include <vector>

using namespace std;

class num_sequence {
    public:
        typedef void (num_sequence::*PtrType)(int);

        void fibonacci(int);
        void pell(int);
        void lucas(int);
        void triangular(int);
        void square(int);
        void pentagonal(int);
    
    private:
        PtrType _pmf;
        vector<int>* _elem;

        static const int num_seq = 7;
        static PtrType func_tbl[num_seq];
        static vector<vector<int> > seq;


};