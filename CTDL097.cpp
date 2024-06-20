#include <bits/stdc++.h>
using namespace std;
template <class val>

/*
void check(string s){
    stack <string> temp;    // tạo stack để push các toán hạng vào
    for (char c : s){
        if (c == '+' || c == '*' || c == '-' || c == '/' || c == '^'){   // nếu kí tự tiếp theo là các dấu thì pop 2 phần tử trong stack ra (tương ứng với 2 toán hạng) và cộng lại thành 1 string mới rồi push ngược lại vào stack
            string a = temp.top();       // VD: B
            temp.pop();
            string b = temp.top();       // Vd: A
            temp.pop(); 
            string x = c + b + a;        // VD: '+' + 'B' + 'A'
            temp.push(x);                // push +AB
        }else{
            temp.push(string{c});    // push các toán hạng ( lưu ý chuyển đổi char c sang string để có thể push vào stack <string>)   // temp.push(str.append(1, c))
        }
    }
    cout<<temp.top()<<endl;             // VD: +AB-CD
}

int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        check(s);
    }
} 
*/


void doit(string s){
    stack<char> prefix;
    prefix.push('(');
    for (int i = 0; i < s.size(); i++){
        if (s.[i] >= 'A'){
            prefix.push(s[i]);
        }else if (42 <= s[i] <= 47){
            char temp = prefix.top();
            prefix.pop();
            prefix.push(s[i]);
            prefix.push(temp);
        }
    }
}