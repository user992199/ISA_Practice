#include<iostream>
using namespace std;
int rwt(int * arr, int n){
	int ans = 0;
	for(int i = 0; i < n; i++){
		int lm = arr[i];
		for(int j = i-1; j >= 0; j--){
			lm = max(lm, arr[j]);
		}
		int rm = arr[i];
		for(int j = i+1; j < n; j++){
			rm = max(rm, arr[j]); 
		}
		ans += min(lm, rm) - arr[i];
	}
	return ans;
}
int main(){
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<rwt(arr, n)<<endl;
	return 0;
}