#include <iostream>
#include "Palindrome.h"

using namespace std;

int main(){
    int znak;
    cout << "Kliknij: \n 1 <- Sprawdz palindrom \n 2 <- Wyjscie \n";
    cin >> znak;
    if (znak==1){
        string wyrazenie;
        cout << "Podaj wyrazenie: \n";
        cin >> wyrazenie;
        if(is_palindrome(wyrazenie)==true)
            cout << "To jest palindrom" << endl;
        else
            cout << "To nie jest palindrom" << endl;
    }
    if(znak==2){
        exit(0);
    }
    return 0;
}