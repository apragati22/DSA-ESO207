#include <iostream>
using namespace std;

void merge(long long int arr[],long long int l,long long int m,long long int r){
    long long int i,j,k,n1,n2;
    n1=m-l+1; 
    n2=r-m;
    long long int L[n1];
    long long int R[n2];
    for (i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for (j=0;j<n2;j++){
        R[j]=arr[m+j+1];
    }
    i=0;j=0;k=l;
    while (i<n1 && j<n2){
        if (L[i]<=R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }
    while (i<n1){
        arr[k++]=L[i++];
    }
    while (j<n2){
        arr[k++]=R[j++];
    }
}

void mergeSort(long long int arr[],long long int l,long long int r){
    if (l<r){
        long long int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

long long int min_heights(long long int arr[], long long int n,long long int k){
    long long int sum=arr[0];
    long long int rem=k;
    long long int cost=arr[n-1];
    long long int x=1;
    for (long long int i=0;i<n-1;i++){
        if (cost==0){
            return 0;
        }
               
        sum=((arr[n-i-1]+arr[n-i-2]+1)*(arr[n-i-1]-arr[n-i-2])/2);
        
        if (sum==0){
                x++;
            continue;
        }
        else if (x*sum==rem){
            rem=0;
            cost= arr[n-i-2];
            break;
        }
        else if (x*sum>rem){
            while(rem>=x*cost){
                    rem-=x*cost;
                    cost--;
                }
                return cost;  
            }
        else if (x*sum<rem){
                rem-=x*sum;
                x++;
                cost=arr[n-i-2];
        }
        
    }
    if (x==n){
            sum=((arr[0]+1)*(arr[0])/2);
            if (x*sum<=rem){
                return 0;
            }
            else{
                cost=arr[0];
                while (rem>=x*cost){
                    rem-=x*cost;
                    cost--;
                }
            }
            return cost;
        } 
    return cost;
}


int main(){
    long long int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long int arr[n];
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        long long int ans;
        mergeSort(arr,0,n-1);
        ans=min_heights(arr,n,k);
        cout<<ans<<endl;
    }
    return 0;
}
