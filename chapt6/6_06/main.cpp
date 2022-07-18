#include "num_sequence.h"

template <int len, int beg_pos>
extern ostream &operator<<(ostream &os, const num_sequence<len, beg_pos> &ns);

int main() {
  Fibonacci<8> fib1;
  Fibonacci<8, 8> fib2;
  Fibonacci<12, 8> fib3;

  cout << "fib1: " << fib1 << "\n";
  cout << "fib2: " << fib2 << "\n";
  cout << "fib3: " << fib3 << endl;
}