#include <iostream>
#include "Triangular.h"

int sum(const Triangular &trian) {
    if( ! trian.length()) {
        return 0;
    }

    int val, sum = 0;
    trian.next_reset();
    while (trian.next(val))
    {
        sum += val;
    }
    return sum;
}

int main() {
    Triangular tri(4);
    cout << "-- sum of elements: " << sum(tri) << endl;

    Triangular tri2(4, 3);
    cout << "-- sum of elements: " << sum(tri2) << endl;

    Triangular tri3(4, 8);
    cout << "-- sum of elements: " << sum(tri3) << endl;

}