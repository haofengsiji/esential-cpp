#include "PrintIt.h"

int main() {
    PrintIt to_cout(cout);

    to_cout.print("hello");
    to_cout.print(1024);

    string my_string("i am a string");
    to_cout.print(my_string);

    PrintIt2<ostream> to_cout2(cout);

    to_cout2.print("hello");
    to_cout2.print(1024);
    to_cout2.print(my_string);
}