#include<iostream>
#include "Shape.h"

using namespace std;

void Square::draw() {
    for(int col=0;col<=18;col++){
        cout<<"+";
    }
    cout<<"\n";
    for(int row=0;row<8;row++){
        cout<<"+";
        for(int col=0;col<=16;col++){
            cout<<" ";
        }
        cout<<"+"<<endl;
    }
    for(int col=0;col<=18;col++){
        cout<<"+";
    }
    cout<<"\n";
}


void Circle::draw() {
    cout<<"       ++"<<endl;
    cout<<"   +        +"<<endl;
    cout<<" +            +"<<endl;
    cout<<"+              +"<<endl;
    cout<<"+              +"<<endl;
    cout<<" +            +"<<endl;
    cout<<"   +        +"<<endl;
    cout<<"       ++"<<endl;
    cout<<"\n";
}

void Triangle::draw() {
    cout<<"       +"<<endl;
    cout<<"      + +"<<endl;
    cout<<"     +   +"<<endl;
    cout<<"    +     +"<<endl;
    cout<<"   +       +"<<endl;
    cout<<"  +         +"<<endl;
    cout<<" +           +"<<endl;
    cout<<"+++++++++++++++"<<endl;
    cout<<"\n";
}