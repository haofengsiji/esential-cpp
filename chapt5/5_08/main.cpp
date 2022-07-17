#include "Fibonacci.h"

extern ostream &operator<<(ostream &os, const num_sequence &ns);

int main() {
    Fibonacci fib1(12);
    Fibonacci fib2 = fib1;

    cout << fib1 << '\n';
    cout << fib2 << endl;
}