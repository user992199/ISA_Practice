#include<iostream>
#include<stack>
using namespace std;
class Queue{
	stack<int> s1;
	stack<int> s2;
public:
	void push(int data){
		while(s1.size()){
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(data);
		while(s2.size()){
			s1.push(s2.top());
			s2.pop();
		}
	}
	void pop(){
		s1.pop();
	}
	int front(){
		return s1.top();
	}
	int size(){
		return s1.size();
	}
	bool empty(){
		return s1.empty();
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