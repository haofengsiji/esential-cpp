#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

extern bool grow_vec(vector<int>&, int);

bool is_elem(vector<int> &vec, int elem)
{
    int max_value = vec.empty() ? 0 : vec[vec.size() - 1];

    if (max_value < elem) {
        return grow_vec(vec, elem);
    }

    if (max_value == elem) {
        return true;
    }

    vector<int> temp(vec.size());
    copy(vec.begin(), vec.end(), temp.begin());
    sort(temp.begin(), temp.end());

    return binary_search(vec.begin(), vec.end(), elem);
}


int main() {
    return 0;
}