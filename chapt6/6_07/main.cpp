#include "LessThan.h"


int main() {
    LessThan<int> lti(1024);
    LessThan<string> lts("Pooh");
    LessThanPred<int> ltpi(1024);
    LessThanPred<string, SttringLen> ltps("Pooh");
}