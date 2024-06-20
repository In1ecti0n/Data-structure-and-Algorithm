// Cho một số thập phân n. Tìm mã gray của số này ở dạng thập phân.
#include <bits/stdc++.h>
using namespace std;

int greyConverter(int n) { 
    return n ^ (n >> 1);    // sử dụng toán tử bitwise để dịch bit.
}

int main(){
    int t ; cin >> t;
    while(t--){
        int n; cin >> n;
        cout<<greyConverter(n)<<endl;
    }
}