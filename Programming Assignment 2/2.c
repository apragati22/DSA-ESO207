#include <stdlib.h>
#include<stdio.h>


typedef struct node{
    long long int data;
    struct node* left;
    struct node* right;
    long long int height;
    long long int index;
}node;

node* head;
node* create_node(long long int x, long long int y){
    node* temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=0;
    temp->index=y;
    return temp;
}

void insert(node* temp, long long int index){
    node* curr;
    curr=head;
    if (temp==head){
        return;
    }
        while(curr!=NULL){
                
            if (curr->index>temp->index && curr->left==NULL){
                curr->left=temp;
                temp->height+=1;
                break;
            }
            else if (curr->index<temp->index && curr->right==NULL){
                curr->right=temp;
                temp->height+=1;
                break;
            }
            else if (curr->index<temp->index && curr->right!=NULL){
                curr=curr->right;
                temp->height+=1;
            }
            else if (curr->index>temp->index && curr->left!=NULL){
                curr=curr->left;
                temp->height+=1;
            }
        }
        return;
}

long long int maximum(long long int arr[], long long int l, long long int r){
    long long int max=arr[l];
    long long int pos=l;
    for (long long int i=l;i<=r;i++){
        if (arr[i]>max){
            max=arr[i];
            pos=i;
        }
    }
    return pos;
}

long long int max_ele;

void bst(long long int arr[],long long int l,long long int r,long long int ans[]){
    node* temp;
    temp=NULL;
    long long int m,x;
    
    while (l<=r){
        x=maximum(arr,l,r);
        temp=create_node(arr[x],x);
        if (x==max_ele){
            head=temp;
        }
        insert(temp,x);
        ans[x]=temp->height;
        bst(arr,l,x-1,ans);                           
        bst(arr,x+1,r,ans);                           
        return;
    }
}


int main(){
    long long int t;
    scanf("%lld",&t);
    while(t--){
        long long int n;
        scanf("%lld",&n);
        long long int arr[n];
        head=NULL;
        for (long long int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }
        max_ele=maximum(arr,0,n-1);
        long long int ans[n];
        bst(arr,0,n-1,ans);  
        for (long long int i=0;i<n;i++){
            printf("%lld ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}