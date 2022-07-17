#include <vector>
#include <algorithm>
#include <iostream>
#include "LessThan.h"

int count_less_than(const vector<int> &vec, int comp) {
    LessThan lt(comp);

    int count = 0;
    for (int ix = 0; ix < vec.size(); ++ix) {
        if (lt(vec[ix])) {
            ++count;
        }
    }
    return count;
}

void print_less_than(const vector<int> &vec, int comp, ostream &os = cout) {
    LessThan lt(comp);

    vector<int>::const_iterator iter = vec.begin();
    vector<int>::const_iterator it_end = vec.end();

    os << "elements less than " << lt.comp_val() << endl;
    while((iter = find_if(iter, it_end, lt)) != it_end) {
        os << *iter << ' ';
        ++iter;
    }
}


int main() {
    LessThan lt10(10);
    vector<int> vec{
        17, 12, 44, 9, 18, 45, 6, 14,
        23, 67, 9, 0, 27, 55, 8, 16
    };

    int comp_val = 20;
    cout << "Number of elements less than "
        << comp_val << " ara "
        << count_less_than(vec, comp_val) << endl;
    
    print_less_than(vec, comp_val);
}