//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends



class Solution {
  public:
  
    void dfs(vector<int>graph[], int node, vector<int>&vis, int &sz){
        vis[node] = 1;
        sz+=1;
        for(auto it: graph[node]){
            if(!vis[it]){
                dfs(graph,it, vis, sz);
            }
        }
        return;
    }
    
    bool ok(vector<int>graph[], int node, vector<int>&chk, int sz){
        chk[node]=1;
        if(graph[node].size() != sz-1) return false;
        for(auto adj: graph[node]){
            if(!chk[adj]){
                return ((graph[adj].size() == sz-1) && ok(graph,adj,chk,sz));
            }
        }
        return true;
    }
    
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<int>graph[v+1];
        for(int i = 0; i<e; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(v+1,0);
        int fans = 0;
        for(int i = 1; i<=v; i++){
            if(!vis[i]){
                int sz = 0;
                dfs(graph,i,vis,sz);
                vector<int>chk(v+1,0);
                if(ok(graph,i,chk,sz)) fans+=1;
            }
        }
        return fans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends