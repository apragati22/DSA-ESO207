#include<bits/stdc++.h>
using namespace std;
long long int distance_val;

void BFS(vector<long long int> adj_list[],long long int dist[],long long int parent[],long long int i){
    queue<long long int> Q;
    dist[i]=distance_val;
    Q.push(i);
    while(!Q.empty()){
        long long int v=Q.front();
        Q.pop();
        if (adj_list[v].size()==0){
            distance_val++;
            continue;
        }
        for (long long int j=0;j<adj_list[v].size();j++){
            if (dist[adj_list[v][j]-1]==INT_MAX){
                dist[adj_list[v][j]-1]=dist[v]+1;
                parent[adj_list[v][j]-1]=v+1;
                Q.push(adj_list[v][j]-1);
                distance_val=dist[v]+2;
            }
        }
    }
    return;
}

void bfs_traversal(vector<long long int> adj_list[],long long int dist[],long long int parent[], long long int n){
    distance_val=0;
    for (long long int i=0;i<n;i++){
        if (dist[i]==INT_MAX){
            BFS(adj_list,dist,parent,i);
        }
    }
    return;
}

int main(){
    long long int n, m;
    cin>>n>>m;
    long long int a[m];
    long long int b[m];
    for (long long int i=0;i<m;i++){
        cin>>a[i];
    }
    for (long long int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<long long int> adj_list[n];
    for (long long int i=0;i<m;i++){
        long long int u,v;
        u=a[i];
        v=b[i];
        adj_list[u-1].push_back(v);
        adj_list[v-1].push_back(u);
    }
    long long int dist[n];
    long long int parent[n];
    for (long long int i=0;i<n;i++){
        dist[i]=INT_MAX;
        parent[i]=0;
    }
    bfs_traversal(adj_list,dist,parent,n);
    // for (long long int i=0;i<n;i++){
    //     cout<<dist[i]<<" ";
    // }
    // cout<<endl;
    // for (long long int i=0;i<n;i++){
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl;
    int result[n]={0};
    for(long long int i=0;i<m;i++){
        long long int x,y;
        x=a[i];
        y=b[i];
        if (parent[x-1]==y || parent[y-1]==x){
            continue;
        }
        if (dist[x-1]==dist[y-1]){
            result[x-1]=1;
            result[y-1]=1;
            long long int par1=parent[x-1];
            long long int par2=parent[y-1];
            while(par1!=par2){
                result[par1-1]=1;
                result[par2-1]=1;
                par1=parent[par1-1];
                par2=parent[par2-1];
            }
            result[par1-1]=1;
            result[par2-1]=1;
        }
        else{
            if (dist[x-1]>dist[y-1]){
                result[x-1]=1;
                result[y-1]=1;
                x=parent[x-1];
                result[x-1]=1;
                long long int par1=parent[x-1];
                long long int par2=parent[y-1];
                while(par1!=par2){
                    result[par1-1]=1;
                    result[par2-1]=1;
                    par1=parent[par1-1];
                    par2=parent[par2-1];
                }
                result[par1-1]=1;
                result[par2-1]=1;
            }
            if (dist[x-1]<dist[y-1]){
                result[x-1]=1;
                result[y-1]=1;
                y=parent[y-1];
                result[y-1]=1;
                long long int par1=parent[x-1];
                long long int par2=parent[y-1];
                while(par1!=par2){
                    result[par1-1]=1;
                    result[par2-1]=1;
                    par1=parent[par1-1];
                    par2=parent[par2-1];
                }
                result[par1-1]=1;
                result[par2-1]=1;
            }
        }
    }
    for (long long int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}

