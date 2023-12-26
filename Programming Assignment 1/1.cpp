#include<iostream>
using namespace std;

void max_sum_i(long long int arr[], long long int sum[],int n){
    sum[n-1]=arr[n-1];
    for (int i=n-2;i>=0;i--){
        if (sum[i+1]>0){
            sum[i]=sum[i+1]+arr[i];
        }
        else{
            sum[i]=arr[i];
        }
    }
}

int main()
{
    long long int t,n;
    
    cin>>t;
    while(t--)
    {
        cin>>n; 
        long long int a[n];
        long long int sum[n];
        for(long long int i=0;i<n;i++)
            cin>>a[i];     
        max_sum_i(a,sum,n);
        for (long long int i=0;i<n;i++){
            cout<<sum[i]<<" ";
        }
        cout<<endl;
    }
}