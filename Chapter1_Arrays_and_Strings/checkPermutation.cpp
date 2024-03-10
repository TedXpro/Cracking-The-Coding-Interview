#include <iostream>
#include <unordered_map>

using namespace std;

bool checkPermutation(string &word1, string &word2){
    unordered_map<char, int> memo;
    for(char &ch : word1)
        memo[ch]++;
    
    for(char &ch : word2){
        if(memo.find(ch) == memo.end())
            return false;
        else {
            memo[ch]--;
            if(memo[ch] < 0)
                return false;
        }
    }

    return true;
}

int main(){
    string word1 = "abcdef";
    string word2 = "feicba";

    if(checkPermutation(word1, word2))
        cout << "YES its possible!\n";
    else
        cout << "NO its not possible!\n";
}