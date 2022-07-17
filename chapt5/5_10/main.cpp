#include "Fibonacci.h"

extern ostream &operator<<(ostream &os, const num_sequence &ns);

int main() {
  Fibonacci fib1(12);
  Fibonacci fib2 = fib1;

  cout << fib1.what_am_i() << '\n';
  cout << fib2.what_am_i() << endl;

  num_sequence *ps = &fib1;

  if (typeid(*ps) == typeid(Fibonacci)) {
    Fibonacci *pf = static_cast<Fibonacci*>(ps); // 无条件转换
    pf->gen_elems(64);
    cout<< "!" << endl;
  }

  ps->gen_elems(64);
  // ps->Fibonacci::gen_elems(64);  # 错误


  if (Fibonacci *pf = dynamic_cast<Fibonacci*>(ps)) {
    pf->gen_elems(64);
    cout<< "!!" << endl;
  }
}