#include <bits/stdc++.h>
using namespace std;

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
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        check(s);
    }
}

