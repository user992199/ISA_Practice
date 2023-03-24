#include<iostream>
#include<stack>
using namespace std;
class Queue{
	stack<int> s;
public:
	void push(int data){
		if(s.empty()) {
			s.push(data);
			return;
		}
		int te = s.top();
		s.pop();
		push(data);
		s.push(te);
	}
	void pop(){
		s.pop();
	}
	int front(){
		return s.top();
	}
	int size(){
		return s.size();
	}
	bool empty(){
		return s.empty();
	}
};
int main(){
	Queue q;
	int n = 10;
	for(int i = 1; i <= n; i++){
		cout<<i<<" ";
		q.push(i);
	}
	cout<<endl<<q.size()<<endl;
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	return 0;
}