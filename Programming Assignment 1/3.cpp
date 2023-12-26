#include<iostream>
using namespace std;

long long int result,n,k;
long long int mat[20][20];
long long int new_mat[20][20];

void mat_mul(long long int mat1[20][20],long long int mat2[20][20]){
    long long int sum;
    long long int mat3[20][20];
    for (long long int i=0;i<k;i++){
        for (long long int j=0;j<k;j++){
            sum=0;
            for (long long int l=0;l<k;l++){
                sum+=((mat1[i][l]%998244353)*(mat2[l][j]%998244353))%998244353;
            }
            mat3[i][j]=sum%998244353;
        }
    }
    for (long long int i=0;i<k;i++){
        for (long long int j=0;j<k;j++){
            new_mat[i][j]=mat3[i][j];
        }
    }
    return;
}

void pow_mat (long long int mat[20][20],long long int x,long long int new_mat[20][20]){
    if (x<=1){
        return;
    }
    pow_mat(mat,x/2,new_mat);
    mat_mul(new_mat,new_mat);
    if (x%2==0){
        return;
    }
    else{
        mat_mul(new_mat,mat);
        return;
    }
}

void NumberOfways() {
    long long int arr[k];
    arr[0]=1;
    
    for (long long int i=1;i<k;i++){
        arr[i]=(2*arr[i-1])%998244353;
    }
    if (n<=k){
        result =arr[n-1]%998244353;
        return;
    }
    for (long long int i=0;i<k;i++){
        result+=new_mat[0][i]*arr[k-i-1];
    }
    return;
}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
            for (long long int i=0;i<k;i++){
                for (long long int j=0;j<k;j++){
                    if ((i==0 || (i-j)==1)){
                        mat[i][j]=1;
                        new_mat[i][j]=1;
                    }
                    else{
                        mat[i][j]=0;
                        new_mat[i][j]=0;
                    }
                }
            }
            result=0;
            pow_mat(mat,n-k,new_mat);
            NumberOfways();
            cout<<result%998244353<<endl;
        }
    //}
    return 0;
}
