#include <bits/stdc++.h>
using namespace std;
/*
void check(string s){
    int n = s.size();
    int ans = 1;
    vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		a[i][i] = 1;
	for (int i = 1; i < n; i++){
		for (int j = 0; j < n - i; j++){
			int x = i + j;
            if ((j + 1 > x - 1 || a[j + 1][x - 1]) && s[j] == s[x]){
                a[j][x] = 1;
            }else{
                a[j][x] = 0;
            }
			if (a[j][x])
				ans = i + 1;
		}
    }
    cout<<ans<<endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        check(s);
    }
}
*/

void check(string s){
    int n = s.size();
    int ans = 1;
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        temp[i][i] = 1;
    }
    for (int i = 2; i <= n; i++){             //                     // test Lỏ ko có dấu = ở 2 vòng lặp vẫn đúng :D
        for (int j = 0; j <= n - i; j++){
            int x = i + j - 1;
            if ((j + 1 > x - 1 || temp[j + 1][x - 1]) && s[j] == s[x]){
                temp[j][x] = 1;
            }
            if(temp[j][x]){
                ans = i;
            }
        }
    }
    cout<<ans<<endl;
}
/*
void check(string s){
    int n = s.size();
    int ans = 1;
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        temp[i][i] = 1;
    }
    for (int i = 2; i <= n; i++){    
        for (int j = 0; j <= n - i; j++){
            int x = i + j - 1;
            if (i == 2 && s[j] == s[x]){
                temp[j][x] = 1;
            }
            if (temp[j + 1][x - 1] && s[j] == s[x]){
                temp[j][x] = 1;
            }
            if(temp[j][x]){
                ans = i;
            }
        }
    }
    cout<<ans<<endl;
}
*/
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        check(s);
    }
}