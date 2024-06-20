#include <bits/stdc++.h>
using namespace std;

int count(int s, int n){
	if (s >= n){
		return s - n;
	}esle if(t % 2 == 0){
		return 1 + dem(s, t /2);
	}esle{
		return 1 + dem(s, t + 1);
	}
}


int main(){
	int t; cin >> t;
	while(t--){
		int s, n; cin >> s >> n;
		cout<< count(s, n)<<endl;
	}
}
