//
// Created by KASIA on 2017-05-03.
//

#include <stdexcept>
#include <iostream>
#include <ostream>
#include <fstream>
#include<regex>
#include <sstream>
#include <string>
#include <stdlib.h>     /* atoi */

using namespace std;



int stringToint(string str1) {
    int i;
    std::istringstream iss(str1);
    iss >> i;
    return i;
}
int main(int argc, char** argv) {


    cout << "HALO" <<endl;
   /* regex pattern{R"((\d{2}):(\d{2}):(\d{2}),(\d{1,3})\s-->\s(\d{2}):(\d{2}):(\d{2}),(\d{1,3})\n(.*))"};
    string line {"00:20:41,150 --> 00:20:45,109\nLALA" };
    smatch matches;
    if (regex_match(line, matches, pattern)) {
        cout<<"udało się dopasować do linii: "<<line<<endl;
        cout<<"zerowa grupa przechwytująca to całe dopasowanie: "<<matches[0]<<endl;
        cout<<"pierwsza grupa przechwytująca to napis: "<<matches[1]<<endl;
        cout<<"druga grupa przechwytująca to liczba: "<<matches[2]<<endl;
        cout <<matches[3]<<endl;
        cout <<matches[4]<<endl;
        cout <<matches[5]<<endl;
        cout <<matches[9]<<endl;

    } */

    std::string str;
    std::string cos;
    std::stringstream *zdanie;
    cout<< "podaj";
    cin >> cos;
    *zdanie << cos;
    std::getline(*zdanie,str);
    cout<< " wynik: " << stringToint(str);





    return 0;
}