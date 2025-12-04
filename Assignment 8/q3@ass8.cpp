#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
  node(int val){
  	data=val;
  	left=right=NULL;
  }
};
node* insert(node *root,int data){
	if(root==NULL)
	return new node(data);
	if(data<root->data){
		root->left=insert(root->left,data);
	}
	else if(data>root->data){
		root->right=insert(root->right,data);
	}
	else {
	cout<<"duplicate value "<<data<<"ignored"<<endl;
	return root;
}
}
node* findmin(node* root) {
	while(root->left)
		root=root->left;
	return root;
}
node* deletenode(node* root,int data){
	if(data<root->data){
		root->left=deletenode(root->left,data);
	}
	else if(data>root->data){
		root->right=deletenode(root->right,data);
		}
	else if(!root->left&&!root->right){
		delete root;
		return NULL;
	}
	else if(!root->right){
		node* temp=root->left;
		delete root;
		return temp;
	}
	else if(!root->left){
		node* temp=root->right;
		delete root;
		return temp;
	}
	else {
		node* temp=findmin(root->right);
		root->data=temp->data;
		root->right=deletenode(root->right,temp->data);
	}
	return root;
}

int maxdepth(node* root){
	if(!root)
	return 0;
	int leftdepth=maxdepth(root->left);
	int rightdepth=maxdepth(root->right);
	return max(leftdepth,rightdepth)+1;
	
}
int mindepth(node* root){
	if(!root)
	return 0;
	if(!root->left&&!root->right)
	return 1;
	if(!root->left){
		return mindepth(root->right)+1;
	}
	if(!root->right){
		return mindepth(root->left)+1;
	}
	int leftdepth=mindepth(root->left);
	int rightdepth=mindepth(root->right);
	int mindepth=min(leftdepth,rightdepth);
	
}
void inorder(node* root) {
    if(!root)
	 return;
    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
}
int main() {
    node* root=NULL;
    root=insert(root, 10);
    root=insert(root, 5);
    root=insert(root, 20);
    root=insert(root, 3);
    root=insert(root, 7);
    root=insert(root, 15);
    root=insert(root, 30);
    
    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;
    
    root=insert(root, 7);
    cout<<"After inserting duplicate 7: ";
    inorder(root);
    cout<<endl;
    
    cout<<"Maximum depth: " << maxdepth(root) << endl;
    cout<<"Minimum depth: " << mindepth(root) << endl;
    
    root= deletenode(root, 5);
    cout <<"After deleting 5: ";
    inorder(root);
    cout<<endl;
    
    root=deletenode(root, 20);
    cout<<"After deleting 20: ";
    inorder(root);
    cout<<endl;
    
    cout<<"Maximum depth: " << maxdepth(root) << endl;
    cout<<"Minimum depth: " << mindepth(root) << endl;
    
    return 0;
}

