#include <iostream>

using namespace std;

int main() {
  bool next_seq = true;
  bool go_for_it = true;
  bool got_it = false;
  int num_tries = 0;
  int num_right = 0;

  int next_elem;

  while (next_seq == true) {
    // 为用户显示数列
    ;
    while ((got_it == false) && (go_for_it == true)) {
      int usr_guess;
      cin >> usr_guess;
      num_tries++;
      if (usr_guess == next_elem) {
        got_it = true;
        num_right++;
      }
      else {
        // 用户猜错了
        // 告诉答错
        // 是否继续
        bool usr_rsp = true;
        cin >> usr_rsp;
        if ( usr_rsp == 'N' || usr_rsp == 'n') {
          go_for_it = false;;
        }
      }
    }  // 内层while结束

    cout << "Want to try again? (Y/N)";
    char try_again;
    cin >> try_again;

    if ( try_again == 'N' || try_again == 'n') {
      next_seq = false;
    }
  }
}