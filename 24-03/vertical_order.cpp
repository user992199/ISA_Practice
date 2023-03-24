#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
class node{
public:
	int data;
	node * left, * right;
	node(int d): data(d), left(0), right(0){}
};
void cbt(node * &root){
	int data;
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
		cin>>data;
		if(data != -1) {
			temp -> left = new node(data);
			q.push(temp->left);
		}
		cin>>data;
		if(data != -1) {
			temp -> right = new node(data);
			q.push(temp->right);
		}
	}
}
void find_degree(node * root, int &mid, int &mad, int cd = 0){
	if(!root) return;
	if(cd > mad) mad = cd;
	if(cd < mid) mid = cd;
	find_degree(root -> left, mid, mad, cd-1);
	find_degree(root -> right, mid, mad, cd+1);
}
void assign_degree(node * root, vector<vector<node*> > &v, int cd){
	if(!root) return;
	v[cd].push_back(root);
	assign_degree(root -> left, v, cd-1);
	assign_degree(root -> right, v, cd+1);
}
void vot(node * root){
	int mid = 0, mad = 0;
	find_degree(root, mid, mad); // O(n)
	vector<vector<node*> > v(mad - mid + 1);
	int drn = -1*mid;
	assign_degree(root, v, drn); // O(n)
	cout<<"Vertical Order Traversal: \n";
	for(int i = 0; i < v.size(); i++){ // O(n)
		cout<<i-drn<<": ";
		for(int j = 0; j < v[i].size(); j++){
			cout<<v[i][j] -> data<<" ";
		}cout<<endl;
	}
	cout<<endl;
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
	vot(root);
	return 0;
}