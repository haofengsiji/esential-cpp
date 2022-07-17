#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int usr_guess;
  char usr_rsp;
  bool next_seq = true;
  bool go_for_it = true;
  bool got_it = false;
  int num_tries = 0;
  int num_right = 0;
  int num_cor = 0;


  const int seq_size = 18;
  vector<int> elem_seq{
    1, 2, 3, 3, 4, 7, 2, 5, 12,
    3, 6, 10, 4, 9, 16, 5, 12, 22
  };

  const int max_seq = 6;
  string seq_names[max_seq] = {
    "Fib",
    "Luc",
    "Pell",
    "Tri",
    "Squ",
    "Pen"
  };


  int cur_tuple = 0;
  
  while (next_seq == true && cur_tuple  < seq_size) {
    cout << "The first two: " 
      << elem_seq[cur_tuple] << ", "
      << elem_seq[cur_tuple+1] 
      << "\nThe Next is? 3";
    cin >> usr_guess;
    if ( usr_guess == elem_seq[cur_tuple + 2]) {
      ++num_cor;
      cout << "Very good"
        << elem_seq[cur_tuple + 2]
        << " is the next element in the " 
        << seq_names[cur_tuple/3] <<" sequence.\n";
    } else {
      cout << "Wrong guess !";
    }
    cout << "Do you want to play it again?[Y/N]: ";
    cin >> usr_rsp;
    if (usr_rsp == 'N' || usr_rsp == 'n')
      next_seq = false;
    else {
      cur_tuple += 3;
    }
  }
}