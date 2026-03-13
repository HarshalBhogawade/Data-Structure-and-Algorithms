#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    //undericted graph
    //space O(2E)
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //for undericrted graph
    //space O(E)
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //u-->v
        adj[u].push_back(v);
        //no need of below as u will direct to v , no v to u directed
        // adj[v].push_back(u);
    }

    //for weighted undirected graph 
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    return 0;

}