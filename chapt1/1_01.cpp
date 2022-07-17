#include <iostream>
#include <string>

using namespace std;

int main()
{

  string user_name;
  string last_name;
  cout << "Please enter your first name and last name: ";
  cin >> user_name >> last_name;
  cout << '\n'
       << "Hello, "
       << user_name
       << " "
       << last_name
       << "... and goodbye!\n";

  return 0;
}