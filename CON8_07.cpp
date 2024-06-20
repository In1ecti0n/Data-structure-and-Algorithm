// Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 cónghĩa. Ví dụ số K = 1, 10, 101. Cho số tự nhiên N (N<263). Hãy cho biết có bao nhiêu số BDNnhỏ hơn N. Ví dụ N=100 ta có 4 số BDN bao gồm các số: 1, 10, 11, 100.
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int count = 0;
        queue<int> temp;
        vector<int> ans;
        temp.push(1);
        for (int i = 0; i < 1000; i++){
            int x = temp.front();
            ans.push_back(x);
            temp.pop();
            temp.push(x * 10);
            temp.push(x * 10 + 1);
        }
        for (int i : ans){
            if (i <= n){
                count++;
            }
        }
        cout<<count<<endl;
    }

}


