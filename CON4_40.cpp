// Cho mảng A[] gồm N phần tử chỉ bao gồm các số 0 và 1. Các số 0 được đặt trước các số 1. Hãy đếm các số 0 với thời gian log(N).
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        int count = 0;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            if (arr[i] == 0){
                count++;
            }
        }
        cout<< count <<endl;
    }
}