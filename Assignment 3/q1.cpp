#include<iostream>
using namespace std;
    int n;
    int top=-1;
    int stack[100];
	
void push(){
		int a;
		cout<<"enter the element to put in stack"<<endl;
		cin>>a;
		if(top==n-1){
			cout<<"is full"<<endl;
	    }
	    else {
	    	top++;
	    	stack[top]=a;
	    	cout<<"element pushed"<<a<<endl;
		}
    }
    void pop() {
    	if(top==-1) {
    		cout<<"the stack is empty"<<endl;
    	}
    	else {
    		top--;
    	}  
    }
    void peek() {
    	if(top==-1) {
    		cout<<"stack is empty"<<endl;
		}
		else {
		int b;
		b=stack[top];
		cout<<"the top element is"<<b<<endl;
	    }
    }
    void display() {
    	int i;
    	for(i=top;i>=0;i--)
    	{
    		cout<<"the elements are="<<stack[i]<<endl;
		}
	}

int main(){
	cout<<"enter the size of stack"<<endl;
	cin>>n;
	int ch;
	do {
	cout<<"enter 1. for push 2. for pop 3. for peek 4. display"<<endl;
	cin>>ch;
	switch(ch){
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			peek();
			break;
		case 4:
			display();
			break;
		default:cout<<"invalid choice"<<endl;
    }
}while(ch!=5);
			return 0;
	}
	
