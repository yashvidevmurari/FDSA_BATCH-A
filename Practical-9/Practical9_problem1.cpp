#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, vector<int> graph[], bool visited[]) {
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node]) {
        if (!visited[next]) {
            DFS(next, graph, visited);
        }
    }
}


void BFS(int start, vector<int> graph[], int n) {
    bool visited[10] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {

    int n = 6;

    vector<int> graph[6];

   
    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[1].push_back(4);

    graph[2].push_back(0);
    graph[2].push_back(5);

    graph[3].push_back(1);
    graph[4].push_back(1);
    graph[5].push_back(2);

    int start = 0;

    cout << "DFS Traversal: ";
    bool visited[10] = {false};
    DFS(start, graph, visited);

    cout << "\nBFS Traversal: ";
    BFS(start, graph, n);

    return 0;
}