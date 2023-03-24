#include<iostream>
using namespace std;
int rwt(int * arr, int n){
	int l = 0, r = n-1;
	int lm = 0, rm = 0;
	int ans = 0;
	while(l < r){
		lm = max(lm, arr[l]);
		rm = max(rm, arr[r]);
		if(lm <= rm){
			ans += lm - arr[l];
			l++;
		}else{
			ans += rm - arr[r];
			r--;
		}
	}
	return ans;
}
int main(){
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<rwt(arr, n)<<endl;
	return 0;
}