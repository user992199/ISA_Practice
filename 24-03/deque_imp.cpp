#include<iostream>
using namespace std;
class node{
public:
	int data;
	node * next, * prev;
	node(int d):data(d), next(0), prev(0){}
};
class deque{
	node * head, * tail;
	int cs;
public:
	deque():head(0), tail(0), cs(0){}
	void push_front(int data){
		cs++;
		if(head == 0 and tail == 0){
			head = tail = new node(data);
			return;
		}
		node * temp = new node(data);
		temp -> next = head;
		head -> prev = temp;
		head = temp;
	}
	void push_back(int data){
		cs++;
		if(head == 0 and tail == 0){
			head = tail = new node(data);
			return;
		}
		tail -> next = new node(data);
		tail -> next -> prev = tail;
		tail = tail -> next;
	}
	void pop_front(){
		if(!head) return;
		node * temp = head;
		head = head -> next;
		delete temp;
		if(!head) tail = 0;
		else head -> prev = 0;
		cs--;
	}
	void pop_back(){
		if(!head) return;
		node * temp = tail;
		tail = tail -> prev;
		delete temp;
		if(!tail) head = 0;
		else tail -> next = 0;
		cs--;
	}
	int front(){
		return head -> data;
	}
	int back(){
		return tail -> data;
	}
	bool empty(){
		return head == 0;
	}
	int size(){
		return cs;
	}

};
int main(){
	deque d;
	// 6 5 4 2
	d.push_back(1);
	d.push_back(2);
	d.pop_front();
	d.push_back(3);
	d.push_front(4);
	d.push_front(5);
	d.pop_back();
	d.push_front(6);
	cout<<d.size()<<endl;
	while(!d.empty()){
		cout<<d.back()<<" ";
		d.pop_back();
	}cout<<endl;
	cout<<d.size()<<endl;
	return 0;
}