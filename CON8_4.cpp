/*
Cho xâu ký tự S[] bao gồm các ký tự in hoa [A, B, ...,Z]. Ta định nghĩa giá trị của xâu S[] làtổng bình phương số lần xuất hiện mỗi ký tự trong xâu. Hãy tìm giá trị nhỏ nhất của xâu S[] sau khi loại bỏ K ký tự trongxâu.

2
0
ABCC
1
ABCC

6
3
*/
#include <bits/stdc++.h>
using namespace std;



int main(){
    int t; cin >> t;
    while(t--){
        int n;
        string s;
        int final = 0; 
        cin >> n >> s;
        map<char, int> solanxuathien;
        priority_queue<int> ans;
        for (char c : s){
            solanxuathien[c]++;
        }
        for (auto x : solanxuathien){
            ans.push(x.second);
        }
        for (int i = 1; i <= n; i++){
            int temp = ans.top();
            ans.pop();
            ans.push(--temp);
        }
        while(!ans.empty()){
            final += ans.top() * ans.top();
            ans.pop();
        }

        cout<<final<<endl;
       
    }

}


