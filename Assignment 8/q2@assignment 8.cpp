#include<iostream>
using namespace std;
struct node{
    char data;
    node *right;
    node *left;
node(char val){
    data=val;
    right=NULL;
    left=NULL;
}
};
node *insert(node *root,char val){
    if(root==NULL){
     return new node(val);
    }
    if(val<root->data){
    root->left=insert(root->left,val);
    }
    if(val>root->data){
        root->right=insert(root->right,val);
    }
        return root;
    }
    node *searchre(node *root,char key){
        if(root->data==key||root==NULL){
            return root;
        }
        if(key<root->data){
            return searchre(root->left,key);
        }
        else{
            return searchre(root->right,key);
        }
        cout<<"NOT FOUND"<<endl;
    }
    node *nonrecur(node *root,char key){
        while(root!=NULL){
            if(root->data==key){
                return root;
            }
            else if(root->data>key){
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
            cout<<"NOT FOUND"<<endl;
            return NULL;
        
    }
        node *maxNode(node *root) {
            if(root==NULL){
            	return NULL;
            }
                else if(root->right!=NULL){
                    root=root->right;
                }
                cout<<"max element="<<root->data<<endl;
            return root;
        }
        node *minNode(node *root){
            if(root==NULL){
            	return NULL;
            }
                if(root->left!=NULL){
                    root=root->left;
                }
                cout<<"min element"<<root->data<<endl;
                return root;
        }
        node *inordersucc(node *root,node *target){
        	if(target->right!=NULL){
        		return minNode(target->right);
			}
			node *succ=NULL;
			node *ance=root;
			while(ance!=NULL){
				if(target->data<ance->data){
					succ=ance;
					ance=ance->left;
					
				}
				else if(target->data>ance->data){
					ance=ance->right;
				}
			}
			return succ;
		}
		node *inorderpre(node *root,node *target){
			if(target->left!=NULL){
				return maxNode(target->left);
			}
			node *pre=NULL;
			node *ance=root;
			while(ance!=NULL){
				if(target->data>ance->data){
					pre=ance;
					ance=ance->right;
				}
				else if(target->data<ance->data){
					ance=ance->left;
				}
			}
			return pre;
		}
		void inorder(node *root){
			if(root==NULL){
				return ;
			}
			inorder(root->left);
			cout<<root->data<<endl;
			inorder(root->right);
		}
		int main(){
			node *root=NULL;
            root=insert(root,'F');
            root=insert(root,'B');
            root=insert(root,'A');
            root=insert(root,'D');
            root=insert(root,'C');
            root=insert(root,'E');
            root=insert(root,'G');
            root=insert(root,'I');
            root=insert(root,'H');
            cout<<"Inorder traversal="<<endl;
            inorder(root);
            cout<<endl;
            node* target = nonrecur(root, 'F');
            node* succ = inordersucc(root, target);
            node* pre = inorderpre(root, target);

            if (succ)
             cout << "Inorder Successor of " << target->data << " = " << succ->data << endl;
            else
             cout << "Inorder Successor of " << target->data << " = None" << endl;

             if (pre)
             cout << "Inorder Predecessor of " << target->data << " = " << pre->data << endl;
            else
             cout << "Inorder Predecessor of " << target->data << " = None" << endl;

            return 0;
} 
            
		
