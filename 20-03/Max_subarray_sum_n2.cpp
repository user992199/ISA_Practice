#include<iostream>
using namespace std;
int max_sum(int * arr, int n){
	int * csum = new int[n];
	csum[0] = arr[0];
	for(int i = 1; i < n; i++){
		csum[i] = csum[i-1] + arr[i];
	}
	int ans = INT_MIN;
	for(int s = 0; s < n; s++){
		for(int e = s; e < n; e++){
			int cs;
			if(s == 0) cs = csum[e];
			else  cs = csum[e] - csum[s-1];
			ans = max(ans, cs);
		}
	}
	return ans;
}
int max_sum_2(int * arr, int n){
	int ans = INT_MIN;
	for(int s = 0; s < n; s++){
		int cs = 0;
		for(int e = s; e < n; e++){
			cs += arr[e];
			ans = max(ans, cs);
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