#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

int factorialZeros(int n){
    int count = 0;
    int i = 1;
    while(n >= pow(5, i)){
        count += n / pow(5, i);
        i++;
    }
    return count;
}

int main(){
    int n = 30;
    int answer = factorialZeros(n);

    cout << n << " factorialZeros: " << answer << endl;
}