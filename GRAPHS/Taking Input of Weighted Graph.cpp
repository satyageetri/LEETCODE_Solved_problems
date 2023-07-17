/******************************************************************************

GRAPHS BASICS AND INTRODUCTION
TOPICS:
TAKING INPUT OF WEIGHTED GRAPH  
            
*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    
    /* LIST Method */
    //
    //
    std::vector<pair<int,int>> adjmat[n+1] ;
    for(int i =0;i<m;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        adjmat[u].push_back(make_pair(v, weight));
        adjmat[v].push_back(make_pair(u, weight));
    }
    cout<<endl;
    for(int i =1 ; i<=m;i++){
        cout<<i<<endl;
        for(int j =0;j<adjmat[i].size() ;j++){
            cout<<adjmat[i][j].first<<' '<<adjmat[i][j].second<<endl;
        }
        cout<<endl;
    }
    //
    //
    //
    /* 
    ADJACENY MATRIX Method
    
    int adjmat[n+1][n+1];
    for(int i =0;i<m;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        adjmat[u][v] = weight;
        adjmat[v][u] = weight;
    }
    */
}