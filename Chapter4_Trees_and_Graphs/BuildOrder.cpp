#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

void buildOrder(unordered_map<char, vector<char>> &dependencies, unordered_set<char> &done, vector<char> &answer, char curr)
{
    if (done.find(curr) != done.end())
        return;

    for (char ch : dependencies[curr])
        buildOrder(dependencies, done, answer, ch);

    done.insert(curr);
    answer.push_back(curr);
}

vector<char> given(vector<vector<char>> &depend, vector<char> &proj)
{
    unordered_map<char, vector<char>> dependencies;
    for (char p : proj)
        dependencies[p] = {};

    for (vector<char> &d : depend)
        dependencies[d[1]].push_back(d[0]);
    unordered_set<char> done;
    vector<char> answer;

    for (auto &d : dependencies)
        buildOrder(dependencies, done, answer, d.first);

    return answer;
}

int main()
{
    vector<vector<char>> depend = {{'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}, {'c', 'b'}};
    vector<char> proj = {'a','b','c','d','e','f'};
    cout << "Before\n";
    vector<char> answer = given(depend, proj);
    cout << "After\n";
    for(char &ans : answer)
        cout << ans << " ";
    cout << endl;
}