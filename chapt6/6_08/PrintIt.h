#pragma once

#include <iostream>

using namespace std;

class PrintIt {
public:
  PrintIt(ostream &os) : _os(os) {}

  template <typename elemType>
  void print(const elemType &elem, char delimiter = '\n') {
    _os << elem << delimiter;
  }

private:
  ostream &_os;
};

template <typename OutStream> class PrintIt2 {
public:
  PrintIt2(OutStream &os) : _os(os) {}
  template <typename elemType>
  void print(const elemType &elem, char delimiter = '\n') {
    _os << elem << delimiter;
  }

private:
  ostream &_os;
};
