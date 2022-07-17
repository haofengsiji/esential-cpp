#pragma once

#include <iostream>
#include <vector>
#include <string>

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

        enum ns_type {
            ns_unset, ns_fibonacci, ns_pell, ns_lucas,
            ns_triangular, ns_square, ns_pentagonal
        };

        static ns_type nstype(int num) {
            return num <= 0 || num >= num_seq
                ? ns_unset
                : static_cast<ns_type>(num);
        }

        void set_sequence(ns_type);
        const string what_am_i() const;
        int elem(int);
        int elem(int) const;
        bool check_integrity(int) const;

    private:
        PtrType _pmf;
        vector<int>* _elem;
        ns_type _isa; 

        static const int num_seq = 7;
        static PtrType func_tbl[num_seq];
        static vector<vector<int> > seq;
        static const int _max_size = 1024;
        
};

class iterator_overflow{};

inline void display(ostream &os, const num_sequence &ns, int pos) {
    os << "The element at position "
        << pos << " for the "
        << ns.what_am_i() << " sequence is "
        << ns.elem(pos) << endl;
}

inline bool num_sequence::check_integrity(int pos) const {
    if (pos >= _max_size) {
        return false;
    }
    return true;
}