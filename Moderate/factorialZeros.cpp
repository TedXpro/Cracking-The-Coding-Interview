#include <iostream>
#include <unordered_map>

using namespace std;

int factorialZeros(int n){
    return n / 5;
}

int main(){
    int n = 30;
    int answer = factorialZeros(n);

    cout << n << " factorialZeros: " << answer << endl;
}