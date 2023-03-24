#include<iostream>
using namespace std;
int fmp(int * arr, int n){
	for(int i = 0; i < n; i++){
		if(arr[i] <= n and arr[i] > 0 and arr[arr[i]-1] != arr[i]){
			swap(arr[i], arr[arr[i]-1]);
			if(arr[i] != i+1)
				i--;
		}
	}
	for(int i = 0; i < n; i++){
		if(arr[i] != i+1){
			return i+1;
		}
	}
	return n+1;
}
int main(){
	int arr[] = {1, 3, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<fmp(arr, n)<<endl;
	return 0;
}