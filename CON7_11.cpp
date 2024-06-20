//CON7_11 - BIẾN ĐỔI TRUNG TỐ - HẬU TỐ
#include <bits/stdc++.h>
using namespace std;

/*
void test(string s){
    stack<string> temp;
    stack<string> ans;
    string final = "";
    for (char c : s){
        if (c == '('){
            continue;
        }else if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^'){
            temp.push(c + string(""));      // hoặc khai báo string temp1 = "", và đặt string("") thành +temp1;
        }else if (c == ')'){
            string a = ans.top();
            ans.pop();
            string b = ans.top();
            ans.pop();
            string n = temp.top();
            temp.pop();
            string x = b + a + n;
            ans.push(x);
        }else{
            ans.push(c + string(""));
        }
    }
    while(!ans.empty()){
        final = ans.top() + final;
        ans.pop();
    }
    cout<<final;
}
*/
/*
Duyet xâu, gặp toán hạng cho vào string ans
Gặp dấu (, cho vào stack
Gặp dấu ), đẩy tất cả phần từ trong stack ra string ans cho đến khi gặp dấu ( {cho cả dấu ( ra ngoài}
Gặp toán tử, nếu có toán tử trong stack có độ ưu tiên cao hơn thì pop toán tử đó ra và push toán tử hiện tại vào. Nếu ko, push toán tử hiện tại vào
Duyệt xong nếu stack còn phần tử thì đẩy hết ra. 
*/
int check(char c){
    if (c == '+' || c == '-'){
        return 1;
    }
    if (c == '*' || c == '/' || c == '^'){
        return 2;
    }else{
        return 0;
    }
}


void test(string s){
    stack<char> temp;
    string ans = "";
    for (char c : s){
        if ((c >= 'A' && c <= 'Z')  || (c >= 'a' && c <= 'z')){
            ans += c;
        }else{
            if (c == '('){
                temp.push(c);
            }
            if (c == ')'){
                while(temp.top() != '('){
                    ans += temp.top();
                    temp.pop();
                }
                temp.pop();
            }
            if (c == '*' || c == '/' || c == '^' ||  c == '+' || c == '-'){
                if (!temp.empty() && check(c) <= check(temp.top())){
                    ans += temp.top();
                    temp.pop();
                }
                temp.push(c);
            }
        }
    }
    while(!temp.empty()){
        ans += temp.top();
        temp.pop();
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