#include <iostream>
#include<cstdlib>
using namespace std;

typedef struct node{
    long long int data;
    struct node* left;
    struct node* right;
    struct node* parent;
    int child_side;                            //1 if left child      //2 if right child          //0 initially
}node;

node* head;
long long int len=0;

node* create_node(long long int x){
    node* temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=NULL;
    temp->child_side=0;
    return temp;
}

node* search (long long int x){
    node* temp;
    temp=head;
    int found=0;
    while (temp!=NULL && found==0){
        if (x==temp->data){
            return temp;
        }
        else if (x<temp->data){
            temp=temp->left;
        }
        else if (x>temp->data){
            temp=temp->right;
        }
    }
    return NULL;
}


void insert(node* temp){
    node* curr;
    curr=head;
    if (temp==head){
        return;
    }
         long long int data;
         data=temp->data;
            while(curr!=NULL){
                if (data==curr->data){
                    break;
                }
                if (curr->left==NULL && data<curr->data){
                    curr->left=temp;
                    temp->parent=curr;
                    temp->child_side=1;
                    len++;
                    break;
                }
                else if (curr->right==NULL && data>curr->data){
                    curr->right=temp;
                    temp->parent=curr;
                    temp->child_side=2;
                    len++;
                    break;
                }
                else if (curr->left!=NULL && data<curr->data){
                    curr=curr->left;
                }
                else if (curr->right!=NULL && data>curr->data){
                    curr=curr->right;
                }
            }
            return;
}


node* find_predecessor(node* temp){
    node* pred;
    pred=temp->left;

    while((pred->right)!=NULL){
        pred=pred->right;
    }
    return pred;
}

void swap_values(node* pred, node* temp){
    long long int val;
    val=pred->data;
    pred->data=temp->data;
    temp->data=val;
}

void delete_node(long long int stock){
    node* temp;
    temp=search(stock);
    if (temp==NULL || len==0){
        return;
    }
    else{
        if (temp->left!=NULL && temp->right!=NULL && temp!=head){
            node* pred;
            pred=find_predecessor(temp);
            swap_values(pred,temp);
            temp=pred;
        }
        if (temp==head){
            if (temp->left==NULL){
                head=temp->right;
                len--; return;
            }
            else if (temp->right==NULL){
                head=temp->left;
                len--; return;
            }
            else{
                node* pred;
            pred=find_predecessor(temp);
            swap_values(pred,temp);
            temp=pred;
            }
        }
        
        if (temp->left==NULL){
            if (temp->child_side==1){
                if (temp->right!=NULL){
                    temp->right->parent=temp->parent;
                    temp->right->child_side=1;
                }
                temp->parent->left=temp->right;
                len--; return;
            }
            else{
                if (temp->right!=NULL){
                    temp->right->parent=temp->parent;
                    temp->right->child_side=2;
                }
                temp->parent->right=temp->right;
                len--; return;
            }
        }
        else if (temp->right==NULL){
            if (temp->child_side==1){
                if (temp->left!=NULL){
                    temp->left->parent=temp->parent;
                    temp->left->child_side=1;
                }
                temp->parent->left=temp->left;
                len--; return;
            }
            else{
                if (temp->left!=NULL){
                    temp->left->parent=temp->parent;
                    temp->left->child_side=2;
                }
                temp->parent->right=temp->left;
                len--; return;
            }
        }
        return;
    }
}

void traversal(node* temp){
    node* p;
    p=temp;
    if (p==NULL) return;
    else {
        if (p->left!=NULL) traversal(p->left);
        printf("%d ", p->data);
        if (p->right!=NULL) traversal(p->right);
    }
}

int main(){
    long long int d;
    cin>>d;
    char ppl;
    long long int stock;
    head=NULL;
    
    while(d--){
        cin>>ppl;
        cin>>stock;

        if (ppl=='B'){
            node* temp;
            temp=create_node(stock);
            if (len==0){
                head=temp;
                len++;
            }
            insert(temp);
        }
        else if (ppl=='S'){
            delete_node(stock);
        } 
        
        else if (ppl=='R'){
            node* temp;
            temp=search(stock);
            if (temp==NULL) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        // traversal(head);
        // printf("\n");
    }
    // printf("\n");
    // cout<<head->data<<endl;
     // traversal(head);
     //    printf("\n");
    return 0;
}