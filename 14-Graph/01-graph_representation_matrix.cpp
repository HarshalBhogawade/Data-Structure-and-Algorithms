#include<bits/stdc++.h>
using namespace std;
//space complexity = O(N*M) = tc
int main(){
    int n,m;
    cin>>n>>m;
    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1; // if weighted graph replace one by actual wt 
        adj[v][u]= 1;
    }
    return 0;
}