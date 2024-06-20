// Cho dãy số A[] gồm n số nguyên dương. Tam giác đặc biệt của dãy số A[] là tam giác được tạo ra bởi n hàng, trong đó hàng thứ 1 là dãy số A[], hàng i là tổng hai phần tử liên tiếp của hàng i-1 (2≤i≤n)
/*
1
5
1 2 3 4 5

[1 2 3 4 5]
[3 5 7 9]
[8 12 16]
[20 28]
[48]

*/
#include <bits/stdc++.h>
using namespace std;


void check(vector<int> &temp){
    cout<<'[';
    for (int i = 0; i < temp.size() - 1; i++){
        cout<<temp[i]<<" ";
    }
    cout<<temp[temp.size() - 1]<<']'<<endl;
    if (temp.size() == 1){
        return;
    }
    vector<int> mid;
    for (int i = 0; i < temp.size() - 1; i++){
        mid.push_back(temp[i] + temp[i+1]);
    }
    check(mid);
}


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> temp(n);
        for (int i = 0; i < n; i++){
            cin >> temp[i];
        }
        check(temp);
    }
}