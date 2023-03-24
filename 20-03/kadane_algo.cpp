#include<iostream>
using namespace std;
int kadane(int * arr, int n){
	int cs = 0, ms = INT_MIN;
	for(int i = 0; i < n; i++){
		cs += arr[i];
		ms = max(ms, cs);
		cs = max(cs, 0);
	}
	return ms;
}
int main(){
	int arr[] = {-5, -4, -3, -2, -1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<kadane(arr, n)<<endl;
	return 0;
}