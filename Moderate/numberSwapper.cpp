#include <iostream>

using namespace std;

void numberSwapper(int &a, int &b){
    a = a + b; // holds the sum of the two numbers;
    b = a - b; // holds the difference of the sum of the two numbers and the second number meaning it will hold the first number.
    a = a - b; // holds the second number as it finds the difference between the sum of the two numbers and the first number.
}

int main(){
    int a = 10, b = 600;
    numberSwapper(a, b);
    cout << a << " " << b << endl;

    a = 600;
    b = 20;
    numberSwapper(a, b);
    cout << a << " " << b << endl;

    a = 10000;
    b = 1;
    numberSwapper(a, b);
    cout << a << " " << b << endl;

    a = -120;
    b = 120;
    numberSwapper(a, b);
    cout << a << " " << b << endl;

    a = -120;
    b = -120009;
    numberSwapper(a, b);
    cout << a << " " << b << endl;
}