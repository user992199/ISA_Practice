#include<iostream>
using namespace std;
int rwt(int * arr, int n){
	int ans = 0;
	int * lm = new int[n];
	int * rm = new int[n];
	lm[0] = arr[0];
	rm[n-1] = arr[n-1];
	for(int i = 1; i < n; i++){
		lm[i] = max(lm[i-1], arr[i]);
	}
	for(int i = n-2; i >= 0; i--){
		rm[i] = max(rm[i+1], arr[i]);
	}
	for(int i = 0; i < n; i++){
		ans += min(lm[i], rm[i]) - arr[i];
	}
	return ans;
}
int main(){
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<rwt(arr, n)<<endl;
	return 0;
}