#include<iostream>
#include<queue>
using namespace std;
class Stack{
	queue<int> q;
public:
	void push(int data){
		q.push(data);
		int n = q.size() - 1;
		for(int i = 0; i < n; i++){
			q.push(q.front());
			q.pop();
		}
	}
	void pop(){
		q.pop();
	}
	int top(){
		return q.front();
	}
	int size(){
		return q.size();
	}
	bool empty(){
		return q.empty();
	}
};
int main(){
	Stack s;
	int n = 10;
	for(int i = 1; i <= n; i++){
		cout<<i<<" ";
		s.push(i);
	}
	cout<<endl<<s.size()<<endl;
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	return 0;
}