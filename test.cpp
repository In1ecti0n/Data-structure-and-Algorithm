// CON7_21

#include <bits/stdc++.h>
using namespace std;

void test(string s){
    stack<int> num;
    stack<char> temp;
    string ans = "";
    for (char c : s){
        if (c >= '1' && c <= '9'){
            num.push(c - '0');
        }else if (c == ']'){
            while(temp.top() != '['){
                ans = temp.top() + ans;
                temp.pop();
            }
            temp.pop();
            int number = num.top();
            num.pop();
            while(number > 1){
                ans += ans;
                number--;
            }
        }else{
            temp.push(c);
        }
    }
    cout<<ans;
}



int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        test(s);
        cout<<endl;
    }
}



// 3[a3[b]1[ab]]
// abbbababbbababbbab