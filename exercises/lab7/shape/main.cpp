#include<iostream>
#include <vector>
#include <random>
#include "Shape.h"

using namespace std;

int main(){

    vector<Shape*> vs;
    default_random_engine generator(time(0));
    uniform_int_distribution<int> distribution(0,2);

    for(int i=0; i<=10;i++){
        int figure = distribution(generator);
        if(figure==0){
            vs.push_back(new Square());
        }
        else if(figure==1){
            vs.push_back(new Circle());
        }
        else{

            vs.push_back(new Triangle());
        }

    }
    for(vector<Shape*>::iterator it = vs.begin(); it != vs.end(); ++it){
        (*it)->draw();
    }

    return 0;
}
