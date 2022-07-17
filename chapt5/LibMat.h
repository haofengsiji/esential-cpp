#pragma once

#include <iostream>
#include <vector>

using namespace std;

class LibMat {
    public:
        LibMat () {
            cout << "LibMat::LibMat() default constructor!\n";
        }

        virtual ~LibMat() {
            cout << "LibMat::~LibMat() destructor!\n";
        }

        virtual void print() const {
            cout << "LibMat::print() --- I am a LibMat object!\n";
        }
};

void print(const LibMat &mat) {
    cout << "in global print(): about to print mat.print()\n";

    // 动态绑定
    mat.print();
}

