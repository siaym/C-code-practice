#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* newNode(int x){
    struct node* t=malloc(sizeof(struct node));
    t->data=x;
    t->left=t->right=NULL;
    return t;
}

/* insert */
struct node* insert(struct node* root,int x){
    if(x<root->data){
        if(root->left) insert(root->left,x);
        else root->left=newNode(x);
    }
    else if(x>root->data){
        if(root->right) insert(root->right,x);
        else root->right=newNode(x);
    }
    return root;
}

/* search */
struct node* search(struct node* root,int x){
    if(!root || root->data==x) return root;
    if(x<root->data) return search(root->left,x);
    return search(root->right,x);
}

/* traverses */
void inorder(struct node* root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

/* min node */
struct node* min(struct node* root){
    while(root->left) root=root->left;
    return root;
}

/* delete */
struct node* delete(struct node* root,int x){
    if(!root) return root;

    if(x<root->data) root->left=delete(root->left,x);
    else if(x>root->data) root->right=delete(root->right,x);
    else{
        if(!root->left){
            struct node* t=root->right;
            free(root);
            return t;
        }
        if(!root->right){
            struct node* t=root->left;
            free(root);
            return t;
        }
        struct node* t=min(root->right);
        root->data=t->data;
        root->right=delete(root->right,t->data);
    }
    return root;
}

int main(){
    int a[]={45,12,78,34,56,90,23,67},i,n=8;

    struct node* root=newNode(a[0]);   // first value as root

    for(i=1;i<n;i++)
        insert(root,a[i]);

    inorder(root);      // 12 23 34 45 56 67 78 90
    printf("\n");

    if(search(root,56)) printf("Found\n");

    root=delete(root,56);

    inorder(root);      // after delete
}