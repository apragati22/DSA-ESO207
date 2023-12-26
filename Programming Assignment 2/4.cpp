#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

long long int n,s;



typedef struct segment{
    long long int l;
    long long int r;
    long long int sum;
} seg;

void find_arr_sum(long long int arr[], long long int sum_arr[], long long int size){
    sum_arr[0]=arr[0];
    for (long long int i=1;i<size;i++){
        sum_arr[i]=sum_arr[i-1]+arr[i];
    }
}

long long int compute_sum(long long int arr[],long long int sum_arr[],long long int l, long long int r){
    long long int sum=0;
    if (l==1){
        sum=sum_arr[r-1];
    }
    else{
        sum=sum_arr[r-1]-sum_arr[l-2];
    }
    return sum;
}

int main(){
    long long int t;
    cin>>t;
    long long int ans;
    long long int pos_till_now;
    while (t--){
        ans=-1;
        pos_till_now=0;
        cin>>n>>s;
        long long int arr[n];
        for (long long int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long int sum_arr[n]={0};
        
        seg inp_seg[s];
        
        find_arr_sum(arr,sum_arr,n);
        for (long long int i=0;i<s;i++){
            inp_seg[i].sum=0;
            cin>>inp_seg[i].l;
            cin>>inp_seg[i].r;
            
            inp_seg[i].sum=compute_sum(arr,sum_arr,inp_seg[i].l,inp_seg[i].r);
            if (inp_seg[i].sum>0) pos_till_now++;
        }
        
        long long int q,k;
        cin>>q>>k;
        long long int queries[q];
        for (long long int i=0;i<q;i++){
            cin>>queries[i];
        }
        if (pos_till_now>=k){
                ans=0;
                cout<<ans<<endl;
                continue;
        }
        long long int mid;
        long long int l=0;
        long long int r=q;
        
        while(l<=r){
            pos_till_now=0;
            mid=(l+r)/2;
            long long int copy[n];
            
            for (long long int i=0;i<n;i++){
                copy[i]=arr[i];
            }
            for (long long int i=0;i<mid;i++){
                    copy[queries[i]-1]=1;
            }
            find_arr_sum(copy,sum_arr,n);
            // for(int i=0; i<n; i++){
            //     cout<<sum_arr[i]<<" ";
            // }
            // cout<<endl;
            for (long long int i=0;i<s;i++){
                int temp =compute_sum(copy,sum_arr,inp_seg[i].l,inp_seg[i].r);
                if (temp>0) pos_till_now++;
            }
            if (pos_till_now>=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    
        cout<<ans<<endl;

    }    
    return 0;
}