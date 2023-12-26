#include<bits/stdc++.h>
using namespace std;

long long int dfnum;

void DFS(vector<long long int> adj_list[],long long int dfn[],long long int i){
    dfn[i]=dfnum;
    dfnum++;
    for (long long int j=0;j<adj_list[i].size();j++){
        if (dfn[adj_list[i][j]-1]<0){
            DFS(adj_list,dfn,adj_list[i][j]-1);
        }
    }
    return;
}

void dfs_traversal(vector<long long int> adj_list[],long long int dfn[], long long int n){
    dfnum=0;
    for (long long int i=0;i<n;i++){
        if (dfn[i]<0){
            DFS(adj_list,dfn,i);
        }
    }
    return;
}

int flag=1;

void col_vertices(vector<long long int> adj_list[],long long int col[],long long int i, int colour){
    col[i]=colour;
    int next_col;
    if (colour==1) next_col=2;
    if (colour==2) next_col=1;
    if (flag==-1) return; 
    for (long long int j=0;j<adj_list[i].size();j++){
        if (col[adj_list[i][j]-1]!=0 && col[adj_list[i][j]-1]!=next_col){
            flag=-1;
            return;
        }
        if (col[adj_list[i][j]-1]==0){
            col_vertices(adj_list,col,adj_list[i][j]-1,next_col);
        }
        if (flag==-1) return; 
    }
    return;
}

void col_traversal(vector<long long int> adj_list[],long long int col[], long long int n){
    for (long long int i=0;i<n;i++){
        if (flag==-1) return;
        if (flag==1){
            if (col[i]==0){
                col_vertices(adj_list,col,i,1);
            }
        }
    }
    return;
}

int main(){
    long long int n, m;
    cin>>n>>m;
    vector<long long int> adj_list[n];
    for (long long int i=0;i<m;i++){
        long long int a,b;
        cin>>a>>b;
        adj_list[a-1].push_back(b);
        adj_list[b-1].push_back(a);
    }
    long long int dfn[n];
    for (long long int i=0;i<n;i++){
        dfn[i]=-1;
    }
    dfs_traversal(adj_list,dfn,n);
    // for (long long int i=0;i<n;i++){
    //     cout<<dfn[i]<<" ";
    // }
    long long int col[n]={0};
    col_traversal(adj_list,col,n);
    if (flag==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    else{
        cout<<"YES"<<endl;
    }
    for (long long int i=0;i<n;i++){
        cout<<col[i]<<" ";
    }
    return 0;
}
