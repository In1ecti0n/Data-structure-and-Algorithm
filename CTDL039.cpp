//Cho mảng A[] gồm N phần tử.Nhiệm vụ của bạn là tìmimage.png bằng cách sắp đặt lại các phần tử trong mảng. Chú ý, kết quả của bài toán có thể rất lớn vì vậy bạn hãy đưa ra kết quả lấy modulo với 109+7.
#include <bits/stdc++.h>
using namespace std;
#define mol 1000000007;

int ans(int n, int arr[]){       // in ra max của sigma A[i] * i ( i chạy từ 0 đến n - 1)
    int tong = 0;
    for (int i = 0; i < n; i++){
        tong += arr[i] * i % mol;
    }
    return tong % mol;
}

void insertsort(int n, int *arr) {           // sắp xếp lại mảng
    for (int i = 1; i < n; i++) {
        int last = arr[i];
        int j = i;
        while ((j > 0) && (arr[j-1] > last)) {
            arr[j] = arr[j-1];
            j = j - 1; 
        }
        arr[j] = last;
    } 
}

/*                                 // cach viết khác của insertsort
void insertsort(int n, int *arr){        // *arr trỏ tới mảng arr cố định 
    for (int i = 1; i < n; i++){        //vòng lặp bắt đầu từ index 1
        int last = arr[i];              // gán số thay đổi vị trí
        bool check = true;              // biến kiểm tra xem có sự thay đổi vị trí hay ko (nếu mảng có sự thay đổi vị trí thì = false, ko thì true)
        for (int j = i; j >= 1; j--){   //so sánh số hiện tại với số trước nó
            if (arr[j - 1] > last){
                arr[j] = arr[j - 1];
                check = false;
            }
        }
        if (!check){            // nếu có sự thay đổi trong mảng thì phần tử đầu = last (vd 4,3,2,10 với index = 2 thi last = 2, arr thành 2,3,4,10 có sự thay đổi index 1 (= 4) thành last = 2)
            arr[0] = last;
        }
    }
}
*/

int main (){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        insertsort(n, arr);
        cout<<ans(n, arr)<<endl;
    }
}