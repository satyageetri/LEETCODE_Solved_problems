/******************************************************************************

GRAPHS BASICS AND INTRODUCTION
TOPICS:
1 - TAKING INPUT FROM THE USER, IN TWO WAYS
            i) USING THE ADJACENY MATRIX
            ii) USING THE LIST
            
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
    std::vector<int> adjmat[n+1] ;
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjmat[u].push_back(v);
        adjmat[v].push_back(u);
    }
    for(int i =1 ; i<=m;i++){
        cout<<i<<' ';
        for(int j =0;j<adjmat[i].size() ;j++){
            cout<<adjmat[i][j]<<' ';
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
        int u,v;
        cin>>u>>v;
        adjmat[u][v] = 1;
        adjmat[v][u] = 1;
    }
    */
}