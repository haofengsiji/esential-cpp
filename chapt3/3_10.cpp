#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os=cout) {
    typename vector<elemType>::const_iterator iter = vec.begin();
    typename vector<elemType>::const_iterator end_it = vec.end();

    // 如果 vec 是空的， iter 便等于 end_it,
    // 于是 for 循环便不会被执行
    for (; iter != end_it; ++iter) {
        os << *iter << ' ';
    }
    os << endl;
}


int main() {
    string word;
    vector<string> text;

    while(cin >> word) {
        text.push_back(word);
    }

    sort(text.begin(), text.end());

    for(int ix = 0; ix < text.size(); ++ix) {
        cout << text[ix] << '-';
    }

    cout << "test!!\n" <<  endl;

    cin >> word;

    cout << word;

    cin >> word;

    cout << word;

    istream_iterator<string> is(cin);
    istream_iterator<string> eof;

    vector<string> text1;
    copy(is, eof, back_inserter(text1));

    sort(text1.begin(), text1.end());

    display(text1);

    ostream_iterator<string> os(cout, " ");
    copy(text1.begin(), text1.end(), os);


    cout << "test!!\n";

    ifstream in_file("input_file.txt");
    ofstream out_file("output_file.txt");

    if(! in_file ||! out_file) {
        cerr << "!! unable to open necessary files\n";
        return -1;
    }

    istream_iterator<string> is1(in_file);
    istream_iterator<string> eof1;


    vector<string> text2;
    copy(is1, eof1, back_inserter(text2));

    sort(text2.begin(), text2.end());

    ostream_iterator<string> os1(out_file, " ");
    copy(text2.begin(), text2.end(), os1);


    return 0;
}