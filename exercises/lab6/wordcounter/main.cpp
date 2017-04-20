#include <iostream>
#include <ostream>
#include <fstream>
#include "WordCounter.h"

using namespace datastructures;
using namespace std;

int main() {

    ifstream is("myfile.txt");

    WordCounter wc = WordCounter::FromInputStream(is) ;

    cout << wc << endl;

    cout <<  "DistinctWords = "<<  wc.DistinctWords() << endl;
    cout <<  "TotalWords = "<<  wc.TotalWords() << endl;

    cout <<"Ilosc: "<<wc["test"]<< endl;
    return 0;
}