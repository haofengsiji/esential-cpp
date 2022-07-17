#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os=cout) {
    typename vector<elemType>::const_iterator iter = vec.begin();
    typename vector<elemType>::const_iterator end_it = vec.end();

    // 如果 vec 是空的， iter 便等于 end_it,
    // 于是 for 循环便不会被执行
    for (; iter != end_it; ++iter) {
        os << *iter << ' ';
    }
    os << endl;
}

template <typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last, const elemType &value)
{
    for (; first != last; ++first) {
        if (value == *first) {
            return first;
        }
    }
    return last;
}


int main() {
    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};

    vector<int> ivec(ia, ia+asize);
    list<int> ilist(ia, ia+asize);

    int *pia = find(ia, ia+asize, 21);
    if (pia != ia+asize) {
        cout << "find it!\n"; 
    }

    vector<int>::iterator it;
    it = find(ivec.begin(), ivec.end(), 21);
    if (it != ivec.end()) {
        cout << "find it!\n"; 
        display(ivec);
    }

    list<int>::iterator iter;
    iter = find(ilist.begin(), ilist.end(), 21);
    if (iter != ilist.end()) {
        cout << "find it!\n"; 
    }
    return 0;
}