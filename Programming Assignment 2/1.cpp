#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


long long int merge_Inversions(long long int arr[], long long int l, long long int m, long long int r)
{
    long long int i, j, k;
    long long int n1 = m - l + 1;
    long long int n2 = r - m;
    long long int p=l;
    long long int L[n1], R[n2];
    long long int count3=0;
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;j = 0;k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
            p++;
        }
        else {
            arr[k++] = R[j++];
            count3+=(m-p+1);
        }
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return count3;
}

long long int Sort_Inversions(long long int arr[],long long int l, long long int r)
{
    if (l==r){
        return 0;
    }
    else{
        long long int m = (l+r) / 2;
        long long int count1,count2,count3;
        
        count1=Sort_Inversions(arr, l, m);
        count2=Sort_Inversions(arr, m + 1, r);

        count3=merge_Inversions(arr, l, m, r);
        return count1+count2+count3;
    }
    return 1;
}

int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int arr[n];
        for (long long int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long int ans;
        ans=Sort_Inversions(arr,0,n-1);
        cout<<ans<<endl;
    }
    return 0;
}