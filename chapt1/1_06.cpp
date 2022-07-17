#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
  const int seq_cnt = 6;
  srand(seq_cnt); // random seed

  vector<int> fib{1, 1, 2, 3, 5, 8, 12, 21};
  vector<int> luc{1, 3, 4, 7, 11, 18, 29, 47};
  vector<int> pell{1, 2, 5, 12, 29, 70, 169, 408};
  vector<int> tri{1, 3, 6, 10, 15, 21, 28, 36};
  vector<int> squ{1, 4, 9, 16, 25, 36, 49, 64};
  vector<int> pen{1, 5, 12, 22, 35, 51, 70, 92};

  // 指针数组，大小为seq_cnt
  // 每个指针都指向 vector<int> 对象
  vector<int> *seq_addrs[seq_cnt] = {
    &fib, &luc, &pell,
    &tri, &squ, &pen
  };

  // vector<int> *current_vec = 0;
  // for (int ix = 0; ix < seq_cnt; ++ix) {
  //   current_vec = seq_addrs[ix];
  // }

  // seq_index = rand() % seq_cnt
  // current_vec = seq_addrs[seq_index];


}