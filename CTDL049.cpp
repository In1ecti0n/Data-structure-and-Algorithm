//Cho dãy số A[] gồm có N phần tử đã được sắp xếp tăng dần và số K. Nhiệm vụ của bạn là kiểm tra xem số K có xuất hiện trong dãy số hay không. Nếu có hãy in ra vị trí trong dãy A[], nếu không in ra “NO”.
#include <bits/stdc++.h>
using namespace std;

void binarysearch (int k, int n, int arr[]){    //tim kiếm nhị phân, thu hẹp dần khoảng tìm kiếm trong mảng 
    int start = 0;                              // start = index đầu; end = index cuối
    int end = n;
    for (int i = start; i < end; i++){          
        int mid = (start + end)/2;              // tìm index trung bình của mảng, nếu k < trung bình thì k sẽ trong khoảng từ start đến mid; nếu k > trung bình thi k nằm trong khoảng từ trung bình đến cuối mảng.
        if (k == arr[mid]){
            cout<<mid + 1;                      // vì đặt start = 0, nến index cuối phải +1. index = 0 là vị trí thứ 1.
            return;
        }else if (k < arr[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    cout<<"NO";
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        binarysearch(k, n, arr);
        cout<<endl;
    }
}