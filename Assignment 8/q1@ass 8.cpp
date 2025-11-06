#include<iostream>
using namespace std;
struct node{
    char data;
    node *left;
    node *right;
node(char val){
    data=val;
    left=NULL;
    right=NULL;
}
};
void preorder(node *root){
    if(root!=NULL){
        cout<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }
}
void postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data;
    }
}
int main(){
    node *root=new node('A');
    root->left=new node('B');
    root->right=new node('C');
    root->left->left=new node('D');
    root->left->right=new node('E');
    root->right->left=new node('F');
    root->right->right=new node('G');
    root->left->left->left=new node('H');
    root->left->left->right=new node('I');
    root->left->right->left=new node('J');
    root->left->right->right=new node('K');
    root->right->left->left=new node('l');
    root->right->left->right=new node('M');
    root->right->right->left=new node('N');
     root->right->right->right=new node('Q');
     cout<<"PREORDER TRAVERSAL="<<endl;
     preorder(root);
     cout<<endl;
     cout<<"INORDER TRAVERSAL="<<endl;
     inorder(root);
     cout<<endl;
     cout<<"POSTORDER TRAVERSAL="<<endl;
     postorder(root);
     cout<<endl;
     
     
    
    
}
