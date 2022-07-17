#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

void display_message(const string&, const vector<int>&);
void display_message(const string&, const vector<double>&);
void display_message(const string&, const vector<string>&);

template <typename elemType>
void display_message(const string&msg, const vector<elemType>&vec) {
  cout << msg;
  for (int ix = 0; ix < vec.size(); ++ix) {
    cout << vec[ix] << ' ';
  }
  cout << '\n';
}



int main()
{

}