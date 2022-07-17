#include "Triangular.h"

extern ostream& operator<<(ostream &os, const Triangular &rhs);
extern istream& operator>>(istream &is, Triangular &rhs);

int main() {
    Triangular tri(6, 3);
    cout << tri << '\n';

    Triangular tri2;
    cin >> tri2;

    cout << tri2;

}