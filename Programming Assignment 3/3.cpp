#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll common_ancestor(ll u,ll v, vector<ll> A[], ll depth[], ll n, ll power2[]){
    if(depth[u]<depth[v]){
        ll temp=u;
        u=v;
        v=temp;
    }
    ll x=log2(n);
    ll req=depth[u]-depth[v];
    for(ll j=x-1;j>-1;j--){
        if(power2[j]<=req){
            u=A[u][j];
            req=req-power2[j];
        }
    }
    for(ll j=x-1;j>-1;j--){
        if(A[u][j]!=A[v][j]){
            u=A[u][j];
            v=A[v][j];
        }
    }
    if (u==v) return v;
    return A[u][0];
}

void DFS(vector<long long int> adj_list[],ll i, long long int bread_crms[], int visited[]){
    visited[i]=1;
    for (long long int j=0;j<adj_list[i].size();j++){
        ll w=adj_list[i][j];
        if (visited[w]==0){
            DFS(adj_list,w,bread_crms,visited);
            bread_crms[i]+=bread_crms[w];
        }
    }
    return;
}

void dfs_traversal(vector<long long int> adj_list[],long long int n, long long int bread_crms[] ){
    int visited[n+1]={0};
    for (long long int i=1;i<n+1;i++){
        if (visited[i]==0){
            DFS(adj_list,i,bread_crms,visited);
        }
    }
    return;
}

void DFS1(vector<long long int> adj_list[],ll i, long long int dist[], ll parent[],int visited[]){
    visited[i]=1;
    
    for (long long int j=0;j<adj_list[i].size();j++){
        ll u=adj_list[i][j];
        if (visited[u]==0){
            dist[u]=dist[i]+1;
            parent[u]=i;
            DFS1(adj_list,u,dist,parent,visited);
        }
    }
    return;
}

void dfs_traversal1(vector<long long int> adj_list[],long long int dist[],ll parent[], long long int n ){
    int visited[n+1]={0};
    for (long long int i=1;i<n+1;i++){
        if (visited[i]==0){
            DFS1(adj_list,i,dist,parent,visited);
        }
    }
    return;
}

int main(){
    ll n,k;
    cin>>n>>k;
    ll m=n-1;
    long long int a[m];
    long long int b[m];
    for (long long int i=0;i<m;i++){
        cin>>a[i];
    }
    for (long long int i=0;i<m;i++){
        cin>>b[i];
    }
    ll path1[k];
    ll path2[k];
    for (long long int i=0;i<k;i++){
        cin>>path1[i];
        cin>>path2[i];
    }
    vector<long long int> adj_list[n+1];
    adj_list[0]={0};
    for (long long int i=0;i<m;i++){
        long long int u,v;
        u=a[i];
        v=b[i];
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    long long int dist[n+1];
    long long int parent[n+1];
    for (long long int i=0;i<n+1;i++){
        dist[i]=0;
        parent[i]=1;
    }
    dfs_traversal1(adj_list,dist,parent,n);
    
    ll j=ceil(log2(n));
    vector<ll> A[n+1];
    for(ll i=1;i<n+1;i++){
        A[i].push_back(parent[i]);
    }
    for(ll x=1;x<=j;x++){
        for(ll i=1;i<n+1;i++){
            ll temp=A[i][x-1];
            A[i].push_back(A[temp][x-1]);
        }
    }
    long long int bread_crms[n+1];
    for(ll i=0;i<n+1;i++){
        bread_crms[i]=0;
    }
    ll power2[j+1];
    power2[0]=1;
    for(ll i=1;i<j+1;i++){
        power2[i]=power2[i-1]*2;
    }
    for (long long int i=0;i<k;i++){
        long long int u,v;
        u=path1[i];
        v=path2[i];
        ll x;
        x=common_ancestor(u,v,A,dist,n,power2);
        //shortest_path(u,v,x,bread_crms,parent);
        if(u==v){
            bread_crms[u]+=1;
        }
        else{
            bread_crms[u]+=1;
            bread_crms[v]+=1;
            bread_crms[x]-=1;
        }
        if(x!=parent[x]){
            bread_crms[parent[x]]-=1;
        }
    
    }
    dfs_traversal(adj_list,n,bread_crms);
    for(ll i=1;i<n+1;i++){
        cout<<bread_crms[i]<<" ";
    }
    return 0;
}