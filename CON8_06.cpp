// Cho số tự nhiên N. Hãy tìm số nguyên dương X nhỏ nhất được tạo bởi số 9 và số 0 chia hết cho N. Ví dụ với N = 5 ta sẽ tìm ra X = 90. N <= 100.
#include <bits/stdc++.h>
using namespace std;

vector<long long> ans;
void check(){
    ans.push_back(9);
    int i = 0;
    while(i < 10000){
        long long temp = ans[i];
        ans.push_back(temp * 10);
        ans.push_back(temp * 10 + 9);
        i++;
    }
}


int main(){
    int t; cin >> t;
    check();
    while(t--){
        int n; cin >> n;
        for (int i = 0; i < 10000; i++){
            if (ans[i] % n == 0){
                cout<<ans[i]<<endl;
                break;
            }
        }  
    }
}