#include<iostream>
#include<string>
using namespace std;
int n;
string str;
char stack[100];
int top=0;
int main(){
	cout<<"enter the string"<<endl;
	cin>>str;
	int n=str.length();
	for(int i=0;i<n;i++)
	{
		stack[top++]=str[i];
	}
	cout<<"reversed string"<<endl;
	while(top!=-1)
	{
		cout<<stack[top--];
	}
	cout<<endl;
}
