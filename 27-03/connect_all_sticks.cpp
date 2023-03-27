#include<iostream>
#include<queue>
using namespace std;
int min_cost(int * arr, int n){
	int ans = 0;
	priority_queue<int, vector<int>, greater<int> > pq(arr, arr+n);
	while(pq.size() > 1){
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		int cost = first + second;
		ans += cost;
		pq.push(cost);
	}
	cout<<pq.top()<<endl;
	return ans;
}
int main(){
	int arr[] = {3, 1, 5, 4, 8, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<min_cost(arr, n)<<endl;
	return 0;
}