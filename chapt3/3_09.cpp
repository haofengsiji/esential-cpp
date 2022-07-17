#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

template <typename InputIterator>
void display(InputIterator first, InputIterator last, ostream &os=cout) {
    // 如果 vec 是空的， iter 便等于 end_it,
    // 于是 for 循环便不会被执行
    for (; first != last; ++first) {
        os << *first << ' ';
    }
    os << endl;
}

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

vector<int> less_than_10(const vector<int> &vec)
{
    vector<int> nvec;
    for (int ix = 0; ix < vec.size(); ++ix) {
        if(vec[ix] < 10) {
            nvec.push_back(vec[ix]);
        }
    }
    return nvec;
}

vector<int> less_than(const vector<int> &vec,  int less_than_val)
{
    vector<int> nvec;
    for (int ix = 0; ix < vec.size(); ++ix) {
        if(vec[ix] < less_than_val) {
            nvec.push_back(vec[ix]);
        }
    }
    return nvec;
}

vector<int> filter(const vector<int> &vec, int filter_value, bool (*pred)(int, int)) {
    vector<int> nvec;
    for (int ix = 0; ix < vec.size(); ++ix) {
        if(pred(vec[ix], filter_value)) {
            nvec.push_back(vec[ix]);
        }
    }
    return nvec;
}

bool less_than(int v1, int v2) {
    return v1 < v2 ? true : false;
}

bool greater_than(int v1, int v2) {
    return v1 > v2 ? true : false;
}

// 在不对任意元素进行两次以上查看前提下，反复地在容器上进行find();
int count_occurs(const vector<int> &vec, int val) {
    vector<int>::const_iterator iter = vec.begin();
    int occurs_count = 0;
    while((iter = find(iter, vec.end(), val)) != vec.end()) {
        ++occurs_count;
        ++iter;
    }
    return occurs_count;
}

vector<int> filter(const vector<int> &vec, int val, less<int> &lt) {
    vector<int> nvec;
    vector<int>::const_iterator iter = vec.begin();

    while((iter = find_if(iter, vec.end(), bind2nd(lt, val))) != vec.end()) {
        nvec.push_back(*iter);
        iter++;
    }
    return nvec;
}

template <typename InputIterator, typename OutputIterator, 
    typename ElemType, typename Comp>
OutputIterator 
filter(InputIterator first, InputIterator last, 
        OutputIterator at, const ElemType &val, Comp pred) {
    while ((first = find_if(first, last, bind2nd(pred, val))) != last) {
        cout << "found value: " << *first << endl;
        *at++ = *first++;
    }
    return at;
}


vector<int> sub_vec(const vector<int> &vec, int val) {
    vector<int> local_vec(vec);
    sort(local_vec.begin(), local_vec.end());

    vector<int>::iterator iter = 
        find_if( local_vec.begin(), local_vec.end(), bind2nd(greater<int>(), val));
    
    local_vec.erase(iter, local_vec.end());
    return local_vec;
}

template <typename InputIterator, typename ElemType>
vector<ElemType> sub_vec(InputIterator first, InputIterator last, ElemType val) {
    vector<ElemType> local_vec(first, last);
    sort(local_vec.begin(), local_vec.end());

    vector<int>::iterator iter = 
        find_if( local_vec.begin(), local_vec.end(), bind2nd(greater<int>(), val));
    
    local_vec.erase(iter, local_vec.end());
    return local_vec;
}


int main() {
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia+elem_size);

    int ia2[elem_size];
    vector<int> ivec2;

    cout << "filtering integer array for values less than 8\n";
    filter(ia, ia+elem_size, ia2, elem_size, less<int>());
    display(ia2, ia2+elem_size);

    cout << "filtering integer array for values greater than 8\n";
    filter(ivec.begin(), ivec.end(), back_inserter(ivec2), elem_size, greater<int>());
    display(ivec2);

    vector<int> ivec3 = sub_vec(ivec.begin(), ivec.end(), elem_size);
    display(ivec3);

    return 0;
}