#pragma once

#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class Triangular_iterator {
    // friend int operator*(const Triangular_iterator &rhs);

    public:
        Triangular_iterator(int index): _index(index - 1) {}
        bool operator==(const Triangular_iterator&) const;
        bool operator!=(const Triangular_iterator&) const;
        int operator*() const;
        Triangular_iterator& operator++();  // 前置
        Triangular_iterator operator++(int);  // 后置
    private:
        void check_intergrity() const;
        int _index;
};

class Triangular {
    friend int operator*(const Triangular_iterator &rhs);

    // friend int Triangular_iterator::operator*():
    // friend void Triangular_iterator::check_integrity();

    friend class Triangular_iterator;

    public:
        typedef Triangular_iterator iterator;

        Triangular_iterator begin() const {
            return Triangular_iterator(_beg_pos);
        }

        Triangular_iterator end() const {
            return Triangular_iterator(_beg_pos + _length);
        }

        Triangular(int len = 1, int beg_pos = 1); // 也是default constructor
        Triangular& copy(const Triangular &rhs);
        
        int length() const { return _length; }
        void length(int len) { _length = len; }
        void beg_pos(int bp) { _beg_pos = bp; }
        int beg_pos() const { return _beg_pos; }
        int elem( int pos ) const;

        bool next( int &val ) const;
        void next_reset() const { _next = _beg_pos - 1; }

        static bool is_elem(int);
        static void gen_elements(int length);
        static void gen_elems_to_value(int value);
        static void display(int length, int beg_pos, ostream &os=cout);
        static int elem_size() {return _elems.size();};
        static int max_elems() {return _max_elems;};


    private:
        int _length;
        int _beg_pos;
        mutable int _next;

        static vector<int> _elems;
        static const int _max_elems = 1024;
};

class iterator_overflow : public exception {
    public:
    iterator_overflow(int index, int max): _index(index), _max(max) {}

    int index() {return _index;}
    int max() {return _max;}

    const char* what() const;

    private:
        int _index;
        int _max;
};

inline bool Triangular_iterator::operator==(const Triangular_iterator &rhs) const {
    return _index == rhs._index;
}

inline bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const {
    return !(*this == rhs);
}

inline int Triangular_iterator::operator*() const {
    check_intergrity();
    return Triangular::_elems[_index];
}

// inline int operator*(const Triangular_iterator &rhs) {
//     rhs.check_intergrity();

//     return Triangular::_elems[rhs._index];
// }

inline void Triangular_iterator::check_intergrity() const {
    if (_index >= Triangular::_max_elems) {
        iterator_overflow ex(
            _index,
            Triangular::_max_elems
        );

        throw ex;
    }

    if (_index >= Triangular::_elems.size()) {
        Triangular::gen_elements(_index + 1);
    }
}


inline Triangular_iterator& Triangular_iterator::operator++() {
    ++_index;
    check_intergrity();
    return *this;
}

inline Triangular_iterator Triangular_iterator::operator++(int) {
    Triangular_iterator tmp = *this;
    ++_index;
    check_intergrity();
    return tmp;
}


