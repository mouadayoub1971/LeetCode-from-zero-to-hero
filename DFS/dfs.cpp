// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int start, vector<vector<int>> &adg, vector<bool> &visited){
    stack<int> s;
    s.push(start);
    visited[start] = true;
    
    while(!s.empty()){
        int node = s.top();
        s.pop();
        cout << node << " ";
        for(auto it = adg[node].rbegin() ; it != adg[node].rend(); ++it){
            if(!visited[*it]){
                s.push(*it);
                visited[*it] = true;
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

    cout << "dfs Traversal: ";
    dfs(0, adj, visited);  
    cout << endl;

    return 0;
}