#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

void display(const vector<int> &vec) {
  for (int ix = 0; ix < vec.size(); ++ix) {
    cout << vec[ix] << ' ';
  }
  cout << endl;
  int ival;
  cout << "local: ival " << ival << endl;
}

void swap(int &val1, int &val2) {
  int temp = val1;
  val1 = val2;
  val2 = temp;
}

ofstream ofil("text_out1");
void bubble_sort(vector<int> &vec) {
  for (int ix = 0; ix < vec.size(); ++ix) {
    for (int jx = ix + 1; jx < vec.size(); ++jx) {
      if (vec[ix] > vec[jx]) {
        ofil << "about to call swap!"
          << " ix: " << ix << " jx: " << jx << '\t'
          << " swapping: " << vec[ix]
          << " with " << vec[jx] << endl;
        swap(vec[ix], vec[jx]);
      }
    }
  }
}


int main()
{
  vector<int> vec{8, 34, 3, 13, 1, 21, 5, 2};

  cout << "vector before sort: ";
  display(vec);

  bubble_sort(vec);

  cout << "vector after sort: ";
  display(vec);

  int ival;
  cout << "file scope:" << ival << endl;

}