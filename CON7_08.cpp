// Cho biểu thức đúng P chỉ bao gồm các phép toán +, -, các toán hạng cùng với các ký tự ‘(’, ‘)’.
/*Hãy bỏ tất cả các ký tự ‘(’, ‘)’ trong P để nhận được biểu thức tương đương. Ví dụ với P = a –(b + c) ta có kết quả P = a – b – c .
*/

/*
C1: if else
C2: stack
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        bool check = false;            // true = đổi dấu sau mở ngoặc tiếp theo; false = kết thúc đổi dấu ngoài ngoặc
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
                if (check && s[i+1] != '('){          // (a '-' b)
                    ans += '+';
                }else if (check && s[i + 1] == '('){  // -(a '-' (b - c))
                    check = false;
                    ans += '+';
                }else if (s[i + 1] == '('){           // '-'()
                    check = true;
                    ans += '-';
                }else{                              
                    ans += '-';                         // -a-b
                }
            }else {
                ans += s[i];                            // a b c
            }
            if (check && s[i] == ')'){
                check = false;
            }
        }
        cout<<ans<<endl;
    }
}