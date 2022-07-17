#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{

    string usr_name;
    cout << "Please enter your name: ";
    cin >> usr_name;
    
    fstream iofile("seq_data.txt", ios_base::in|ios_base::app);
    int num_tries = 0;
	int num_cor = 0;

    if (!iofile) {
        cerr << "Oops! Unable to save session data!\n";
    } 
    else {
        iofile.seekg(0);

        // ok
        string name;
        int nt;
        int nc;

        while (iofile >> name) {
            iofile >> nt >> nc;
            if (name == usr_name) {
                // find him/her
                cout << "Welcome back, " << usr_name
                    << "\nYour current score is " << nc
                    << " out of " << nt << "\nGood Luch!\n";
                num_tries = nt;
                num_cor = nc;
            }
        }
    }

}