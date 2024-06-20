#include <bits/stdc++.h>
using namespace std;

string test(string s){
        bool check = false;
        string ans = "";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                continue;
            }else if (s[i] == ')'){
                check = false;
            }else if (s[i] == '+'){
                if (check){
                    ans += '-';
                }else{
                    ans += '+';
                }
            }else if (s[i] == '-'){
                if (check && s[i+1] != '('){
                    ans += '+';
                }else if (check && s[i + 1] == '('){
                    check = false;
                    ans += '+';
                }else if (s[i + 1] == '('){
                    check = true;
                    ans += '-';
                }else{
                    ans += '-';
                }
            }else {
                ans += s[i];
            }
            if (check && s[i] == ')'){
                check = false;
            }
        }
        return ans;
}
int main(){
    int t; cin >> t;
    while(t--){
        string s1, s2; cin >> s1 >> s2;
        if (test(s1) == test(s2)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}