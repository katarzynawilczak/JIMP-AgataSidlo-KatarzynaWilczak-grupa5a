#include <string>
#include "Palindrome.h"

bool is_palindrome(std::string str){
    int a=0;
    int b=str.length()-1;
    while(a<b){
        if(str[a]!=str[b]){
            return false;
        }
        a++;
        b--;
    }
    return true;
}


