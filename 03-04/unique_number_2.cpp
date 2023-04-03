#include<iostream>
using namespace std;
void un_num(int * arr, int n){
	int xor_all = 0;
	for(int i = 0; i < n; i++){
		xor_all ^= arr[i];
	}
	int mask = 1;
	while((xor_all & mask) == 0){
		mask <<= 1;
	}
	int u1 = 0, u2 = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] & mask) u1 ^= arr[i];
		else u2 ^= arr[i];
	}
	cout<<u1<<" "<<u2<<endl;
}
int main(){
	int arr[] = {1, 2, 4, 6, 8, 4, -5, 6, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	un_num(arr, n);
	return 0;
}