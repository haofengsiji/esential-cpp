#include <iostream>
#include <vector>

using namespace std;

bool seq_elem(int pos, int &elem);
const vector<int> *fibon_seq(int size);
const vector<int> *lucas_seq(int size);
const vector<int> *pell_seq(int size);
const vector<int> *triang_seq(int size);
const vector<int> *square_seq(int size);
const vector<int> *pent_seq(int size);

const int seq_cnt = 6;
extern const vector<int>* (*seq__array[seq_cnt])(int);