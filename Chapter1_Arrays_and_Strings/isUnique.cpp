#include <iostream>
#include <unordered_set>

using namespace std;

bool isUnique(string & word){
    unordered_set<char> memo;
    for(char & ch : word){
        if(memo.find(ch) != memo.end())
            return false;
        memo.insert(ch);
    }

    return true;
}

int main(){
    string word = "abeotirmkl;'./";

    if(isUnique(word))
        cout << "String IS Unique\n";
    else
        cout << "String IS NOT unique\n";
}