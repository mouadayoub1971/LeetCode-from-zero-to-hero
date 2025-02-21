// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> &adg, vector<bool> &visited){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : adg[node]){
            if(!visited[neighbor]){
                q.push(neighbor) ;
                visited[neighbor] = true;
            }
        }
    }
}
int main() {
    // Write C++ code here
    int n = 6;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false) ;
    
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};

    cout << "BFS Traversal: ";
    bfs(0, adj, visited);  
    cout << endl;

    return 0;
}