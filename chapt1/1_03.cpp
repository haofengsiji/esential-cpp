#include <iostream>

using namespace std;

int main() {
	string usr_name;
	int usr_var;
	int num_tries = 0;
	int num_right = 0;
	string sequence_name = "Fibonaci";
	double usr_score = 0.0;
	char usr_more;
	cout << "Try another sequence? Y/N? ";
	cin >> usr_more;
	bool go_for_it = true;
	const int max_tries = 3;
	const double pi = 3.14159;

	const int line_size = 8;
	int cnt = 1;

	// cout << a_string
	// 	<< ( cnt % line_size ? ' ' : '\n');


	bool usr_more = true;
	char usr_rsp;

	if ( usr_rsp == 'N' || usr_rsp == 'n')
		usr_more = false;
	

	if ( !usr_more )
		cout << "Your score for this session is "
			<< usr_score << " Bye!\n";
}