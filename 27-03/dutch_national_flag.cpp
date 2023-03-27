#include<iostream>
using namespace std;
void dnf(int * arr, int n, int n1, int n2, int n3){
	int low = 0, mid = 0, high = n-1;
	while(mid <= high){
		if(arr[mid] == n1) swap(arr[low++], arr[mid++]);
		else if(arr[mid] == n2) mid++;
		else swap(arr[mid], arr[high--]);
	}
}
void print(int * arr, int n){
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}
int main(){
	int arr[] = {2, 0, 1, 1, 0, 2, 1, 0, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int n1 = 0, n2 = 1, n3 = 2;
	print(arr, n);
	dnf(arr, n, n1, n2, n3);
	print(arr, n);
	return 0;
}