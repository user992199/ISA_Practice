#include<iostream>
#include<string>
#include<vector>
using namespace std;

void compute_lps(string pat, vector<int> &lps){
	int i = 1, j = 0;
	while(i < pat.size()){
		if(pat[i] == pat[j]){
			j++;
			lps[i+1] = j;
			i++;
		}else{
			if(j == 0){
				lps[i+1] = 0;
				i++;
			}else{
				j = lps[j];
			}
		}
	}
}

int kmp(string text, string pat){
	vector<int> lps(pat.size()+1, 0);
	compute_lps(pat, lps);
	int i = 0, j = 0;
	int t_len = text.length(), p_len = pat.size();
	while(i < t_len){
		// cout<<i<<" "<<j<<endl;
		if(text[i] == pat[j]){
			i++; j++;
		}
		if(j == p_len){
			return i - j;
		}
		else if(i < t_len and text[i] != pat[j]){
			if(j != 0){
				j = lps[j];
			}else{
				i = i+1;
			}
		}
	}
	return -1;
}
int main(){
	string text = "aaaaaaaaaab";
	string pat = "aaab";
	cout<<kmp(text, pat)<<endl;
	return 0;
}