//Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng tiền tố về dạng trung tố.
#include <bits/stdc++.h>
using namespace std;

void test(string s){
    reverse(s.begin(), s.end());
    stack<string> ans;
    string mid = "";
    for (char c : s){
        if (c == '+'  || c == '-' || c == '/' || c == '*'){
            string a = ans.top();
            ans.pop();
            string b = ans.top();
            ans.pop();
            string temp = ')' + b + (mid + c) + a + '(';
            ans.push(temp);  
        }else{
            ans.push(c + mid);
        }
    }
    string final = ans.top();
    reverse(final.begin(), final.end());
    cout<<final;

}



int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        test(s);
        cout<<endl;
    }
}