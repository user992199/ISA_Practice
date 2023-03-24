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
void assign_degree(node * root, unordered_map<int, vector<node*> > &umap, int cd = 0){
	if(!root) return;
	umap[cd].push_back(root);
	assign_degree(root -> left, umap, cd-1);
	assign_degree(root -> right, umap, cd+1);
}
void vot(node * root){
	unordered_map<int, vector<node*> > umap;
	assign_degree(root, umap); // O(n)
	cout<<"Vertical Order Traversal: \n";
	for(auto it = umap.begin(); it != umap.end(); it++){ // O(n)
		for(int j = 0; j < it->second.size(); j++){
			cout<<it -> second[j] -> data<<" ";
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