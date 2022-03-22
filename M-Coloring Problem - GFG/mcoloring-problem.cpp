// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int node, int color[], int N, bool graph[101][101], int col){
    for(int k=0; k<N; k++){
        // If it's an adjacent node '(graph[k][node])' i,e., if it has an edge
        // && it already has our current color
        if(k != N && graph[k][node] == 1 && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, int color[], int M, int N, bool graph[101][101]){
    if(node == N)   return true;
    
    // Check for every col from 1 --> N
    for(int i=1; i<=M; i++){
        if(isSafe(node, color, N, graph, i)){
            color[node] = i;
            if(solve(node+1, color, M, N, graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    int color[n] = {0};
    if(solve(0, color, m, n, graph))
        return true;
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends