// Cho hai xâu nhị phân biểu diễn hai số. Nhiệm vụ của bạn là đưa ra tích của hai số. Ví dụ với xâu S1=”1100” và S2=”1010” ta sẽ có kết quả là 120
#include <bits/stdc++.h>
using namespace std;

void check(string s1, string s2){
    int a = s1.size() - 1;
    int b = s2.size() - 1;
    int ans1 = 0;
    int ans2 = 0;
    for (char c : s1){
        int temp = c - '0';
        ans1 += temp * pow(2, a);
        a--;
    } 
    for (char c : s2){
        int temp = c - '0';
        ans2 += temp * pow(2, b);
        b--;
    } 
    cout<< ans1 * ans2 <<endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        check(s1, s2);
    }
}