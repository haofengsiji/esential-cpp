#include "Fibonacci.h"
#include "Pell.h"
#include "Lucas.h"
#include "Triangular.h"
#include "Square.h"
#include "Pentagonal.h"

extern ostream &operator<<(ostream &os, const num_sequence &ns); 

int test1() {
    const int pos = 8;

    Fibonacci fib;
    display(cout, fib, pos);

    Pell pell;
    display(cout, pell, pos);

    Lucas lucas;
    display(cout, lucas, pos);

    Triangular trian;
    display(cout, trian, pos);

    Square square;
    display(cout, square, pos);

    Pentagonal penta;
    display(cout, penta, pos);
    
    return 0;
}


int test2() {
    Fibonacci fib(8);
    Pell pell(6, 4);
    Lucas lucas(10, 7);
    Triangular trian(12);
    Square square(6, 6);
    Pentagonal penta(8);
    cout << "fib: "     << fib      << '\n';
    cout << "pell: "    << pell      << '\n';
    cout << "lucas: "     << lucas      << '\n';
    cout << "trian: "     << trian      << '\n';
    cout << "square: "     << square      << '\n';
    cout << "penta: "     << penta      << '\n';
    return 0;
}

int main() {
    test1();
    test2();
}