#include "Triangular.h"

using namespace std;

int main() {
    Triangular tri(20);

    Triangular::iterator it = tri.begin();
    Triangular::iterator end_it = tri.end();

    cout << "Triangular Series of " << tri.length() << " elements\n";
    while (it != end_it) {
        cout << *it << ' ';
        it++;
        // ++it;
    }
    cout << endl;
}