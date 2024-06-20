// Cho xâu ký tự mã hóa str. Hãy viết chương trình giải mã xâu ký tự str. Xâu ký tự mã hóa đượcthực hiện theo số lần lặp các xâu con của str như sau:
/*
Xâu đầu vào: “abbbababbbababbbab ”
Xâu mã hóa : "3[a3[b]1[ab]]"

2
1[b]
3[b2[ca]]

b
bcacabcacabcaca

*/
#include <bits/stdc++.h>
using namespace std;

void test(string s){
    stack<int> num;
    stack<char> temp;
    string ans = "";
    string final = "";
    int number;
    for (char c : s){
        if (c >= '1' && c <= '9'){
            num.push(c - '0');
        }else if (c == ']'){
            while(temp.top() != '['){
                ans = temp.top() + ans;
                temp.pop();
            } temp.pop();
            number = num.top();  num.pop();
            while(number > 0){
                if (number % 2 == 0){
                    ans += ans;
                    number -= 2;
                }else{
                    final += ans;
                    number--;
                }
            }
            ans = final;
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