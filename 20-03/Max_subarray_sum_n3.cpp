#include<iostream>
using namespace std;
int max_sum(int * arr, int n){
	int ans = INT_MIN;
	for(int s = 0; s < n; s++){
		for(int e = s; e < n; e++){
			int curr_sum = 0;
			for(int l = s; l <= e; l++){
				curr_sum += arr[l];
			}
			ans = max(ans, curr_sum);
		}
	}
	return ans;
}
int main(){
	int arr[] = {10, 3, -5, 4, -180, 3, 3, -7, 5, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<max_sum(arr, n)<<endl;
	return 0;
}