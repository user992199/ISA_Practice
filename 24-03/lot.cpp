#include<iostream>
#include<queue>
using namespace std;
class node{
public:
	int data;
	node * left, * right;
	node(int d): data(d), left(0), right(0){}
};
void cbt(node * &root){
	int data;
	cout<<"Enter the data for root node: ";
	cin>>data;
	if(data == -1){
		return;
	}
	root = new node(data);
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node * temp = q.front();
		q.pop();
		cout<<"Enter the left child of "<<temp -> data<<": ";
		cin>>data;
		if(data != -1) {
			temp -> left = new node(data);
			q.push(temp->left);
		}
		cout<<"Enter the right child of "<<temp -> data<<": ";
		cin>>data;
		if(data != -1) {
			temp -> right = new node(data);
			q.push(temp->right);
		}
	}
}
void lot(node * root){
	if(!root) return;
	queue<node*> q;
	q.push(root);
	q.push(0);
	cout<<"Level Order Traversal: \n";
	while(q.size() > 1){
		root = q.front();
		q.pop();
		if(!root){
			cout<<endl;
			if(q.empty()) return;
			q.push(root);
			continue;
		}
		cout<<root -> data<<" ";
		if(root -> left) q.push(root -> left);
		if(root -> right) q.push(root -> right);
	}
	cout<<endl;
}
int main(){
	node * root = 0;
	cbt(root);
	lot(root);
	return 0;
}