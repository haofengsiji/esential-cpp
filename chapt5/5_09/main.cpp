#include <iostream>
#include <string>
#include <vector>

using namespace std;

class num_sequence {
public:
  virtual const string what_am_i() const { return "num_sequence\n"; }
  virtual num_sequence *clone() = 0;
};

class Fibonacci : public num_sequence {
public:
  virtual const string what_am_i() const { return "Fibonacci\n"; }
  Fibonacci *clone() {return new Fibonacci(*this); }
};

int main() {
  Fibonacci b;
//   num_sequence p;

  num_sequence *pp = &b;
  cout << pp->what_am_i();

  cout << b.what_am_i();
  return 0;
}
