//
// Created by mwypych on 02.02.17.
//

#include "Factorial.h"

int factorial(int value) {
  int wynik=1;
  if (value>=13)
    return 0;
  else {
    while (value > 0) {
      wynik = wynik * value;
      value--;
    }
    while (value < 0) {
      wynik = wynik * value;
      value++;
    }
    return wynik;
  }
}