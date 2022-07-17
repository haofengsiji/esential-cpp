#include <iostream>
#include <string>
#include <vector>

#include "Stack.h"

using namespace std;


void fill_stack(Stack &stack, istream &is=cin) {
    string str;
    while(is >> str && !stack.full()){
        stack.push(str);
    }

    cout << "Read in " << stack.size() << " elements\n"; 
}

bool Stack::pop(string &elem)
{
    if(empty()) {
        return false;
    }

    elem = _stack.back();
    _stack.pop_back();
    return true;
}



bool Stack::peek(string &elem) {
    if (empty()) {
        return false;
    }

    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem) {
    if (full()) {
        return false;
    }

    _stack.push_back(elem);
    return true;
}

