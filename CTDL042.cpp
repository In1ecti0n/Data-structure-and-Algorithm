//Cho mảngA[], B[] đều có N phần tử. Nhiệm vụ của bạn là tìm giá trị nhỏ nhất của biểu thứcP = A[0]*B[0] + A[1]*B[1] + ..+A[N-1]*B[N-1] bằng cách tráo đổi vị trí các phầntử của cả mảng A[] và B[].
// vd mang A {1 6 3 4 5 2 7} mang B {1 1 1 2 3 4 3}.  Dễ nhận thấy để tổng tích các phần tử trong 2 mảng nhỏ nhất thì sẽ nhân số lớn nhất của 1 mảng với số bé nhất của một mảng với mảng còn lại
// nếu ko sắp xếp sẽ ko đoán trước được kết quả, nếu 2 mảng đều tăng dần hoặc giảm dần thì 2 số lớn nhất sẽ nhân với nhau. 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int sum = 0;
        vector<int> arr1(n);
        vector<int> arr2(n);
        for (int i = 0; i < n; i++){
            cin >> arr1[i];
        }
        for (int i = 0; i < n; i++){
            cin >> arr2[i];
        }
        sort(arr1.begin(), arr1.end());          // sắp xếp tăng dần
        sort(arr2.rbegin(), arr2.rend());        // sắp xếp giảm dần.
        for (int i = 0; i < n; i++){
            sum += arr1[i] * arr2[i];
        }
        cout<<sum<<endl;
    }
}