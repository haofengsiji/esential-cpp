#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;


bool fibon_elem(int pos, int &elem);

int main()
{
  int pos;
  cout << "Please enter a position: ";
  cin >> pos;

  int elem;
  if (fibon_elem(pos, elem)) {
    cout << "element # " << pos
      << " is " <<  elem << endl;
  }
  else {
    cout << "Sorry。 Cloud not calculate element # "
      << pos << endl;
  }
}



bool fibon_elem( int pos, int &elem) {
/* 
* Fibonacci 数列的第一元素和第二元素
* 都是1；接下来每个元素都是前两个元素和
* 
* 输入：
*  pos: ...
* 输出：
*  elem: ...
* 
*/

// check the validity
if (pos <= 0 && pos > 1024) {
  elem = 0;
  return false;
}

elem = 1;
int n_1 = 1;
int n_2 = 1;
for ( int ix = 3; ix <= pos; ++ix) {
  elem = n_2 + n_1;
  n_2 = n_1;
  n_1 = elem;
}

return true;
}
