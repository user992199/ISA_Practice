#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void sieve(int n1, int n2){
	vector<bool> v(n2+1, true);
	v[2] = true;
	for(int i = 2; i <= sqrt(n2); i++){
		if(v[i]){
			for(int mult = i * i; mult <= n2; mult += i){
				v[mult] = false;
			}
		}
	}
	for(int i = n1; i <= n2; i++){
		if(v[i]) cout<<i<<" ";
	}
	cout<<endl;
}
int main(){
	int n1 = 10, n2 = 100;
	sieve(n1, n2);
	return 0;
}