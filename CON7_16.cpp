// Hãy viết chương trình chuyển tính toán giá trị của biểu thức hậu tố.
/*
2
231*+9–
875*+9-
*/
#include <bits/stdc++.h>
using namespace std;

void test(string s){
    stack<int> temp;
    for (char c : s){
        if (c >= '0' && c <= '9'){
            temp.push(c - '0');
        }else{
            int a = temp.top();
            temp.pop();
            int b = temp.top();
            temp.pop();
            switch(c){
                case '+': b += a; break;
                case '-': b -= a; break;
                case '*': b *= a; break;
                case '/': b /= a; break;
            }

            temp.push(b);
        }
    }
    cout<<temp.top();
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        test(s);
        cout<<endl;
    }
}