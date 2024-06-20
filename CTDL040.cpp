//Cho mảng A[] gồm các số từ 0 đến 9. Nhiệm vụ của bạn là tìm tổng nhỏ nhất của hai số được tạo bởi các số trong mảng A[]. Chú ý, tất cả các số trong mảng A[] đều được sử dụng để tạo nên hai số. 1<= size của mảng <= 20.
#include <bits/stdc++.h>
using namespace std;

long long minsum(int n, int arr[]){            // sắp xếp các hàm tăng dần rồi lấy mỗi cặp số làm số đầu tiên của 2 số cần tạo (vd mảng {2,3,4,5,6,7} thì 2,3 thành 2xx và 3xx; tiếp đến 4,5 thành 24x và 35x,....)
    string num1 = "";
    string num2 = "";
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            num1 += arr[i] + '0';
        }else{
            num2 += arr[i] + '0';
        }
    }
    return stoi(num1) + stoi(num2);
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);               // hàm sắp xếp có sẵn trong stlib c++
        cout<<minsum(n, arr);
        cout<<endl;
    }
}