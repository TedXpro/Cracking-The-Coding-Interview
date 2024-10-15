#include <iostream>
#include <unordered_map>

using namespace std;

int wordFrequencies(unordered_map<string, int>& memo, string &word){
    if(memo.find(word) == memo.end()){
        return 0;
    }
    return memo[word];
}

void countWords(unordered_map<string, int>& memo, string& book){
    string currWord = "";
    for(char ch : book){
        if((ch == ' ' || ispunct(ch)) && !currWord.empty()){
            memo[currWord]++;
            currWord = "";
        } else if (ch != ' ' && !ispunct(ch)) {
            currWord += ch;
        }
    }

    if(!currWord.empty()){
        memo[currWord]++;
    }
}

int main(){

    unordered_map<string, int> memo;
    string book = "This is a sample textbook. This is a book i am testing on book; book? book. book";
    string word = "book";
    countWords(memo, book);

    cout << "The number of occurence of 'book' in the string is " << wordFrequencies(memo, word) << endl;

}