#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

void dfs(int curr, unordered_set<int> &visited, unordered_map<int, vector<int>> &graph)
{
    if (visited.find(curr) != visited.end())
        return;
    cout << curr << " -> ";
    visited.insert(curr);

    for (int i = 0; i < graph[curr].size(); i++)
    {
        int num = graph[curr][i];
        if (visited.find(num) != visited.end())
            continue;
        dfs(num, visited, graph);
    }
}

void bfs(unordered_map<int, vector<int>> &graph)
{
    queue<int> neighbours;
    unordered_set<int> visited;

    neighbours.push(graph.begin()->first);
    while (!neighbours.empty())
    {
        int curr = neighbours.front();
        neighbours.pop();
        if (visited.find(curr) != visited.end())
            continue;
        cout << curr << " -> ";
        visited.insert(curr);

        // push the neighbours to the queue.
        for (int i = 0; i < graph[curr].size(); i++)
        {
            if (visited.find(graph[curr][i]) != visited.end())
                continue;
            neighbours.push(graph[curr][i]);
        }
    }
}

int main()
{
    unordered_map<int, vector<int>> graph;
    graph[1].push_back(2);
    graph[1].push_back(7);
    graph[2].push_back(7);
    graph[2].push_back(1);
    graph[2].push_back(8);
    graph[2].push_back(9);
    graph[7].push_back(1);
    graph[7].push_back(2);
    graph[8].push_back(2);
    graph[8].push_back(5);
    graph[8].push_back(0);
    graph[9].push_back(2);
    graph[9].push_back(12);
    graph[5].push_back(12);
    graph[5].push_back(8);
    graph[0].push_back(8);
    graph[0].push_back(3);
    graph[3].push_back(0);
    graph[12].push_back(9);
    graph[12].push_back(5);

    unordered_set<int> visited;
    cout << "\nDepth First Search of the given graph\n";
    dfs(graph.begin()->first, visited, graph);
    cout << "\nBreadth First Search of the given graph\n";
    bfs(graph);
    cout << endl << endl;
}