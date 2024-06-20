// Cho một số nguyên dương N. Nhiệm vụ là tạo ra tất cả các chuỗi nhị phân của N bit. Các chuỗi nhị phân này phải theo thứ tự tăng dần.

#include <bits/stdc++.h>
using namespace std;

void binary (int n, int k){  // ham chuyển đổi số thập phân sang nhị phân và in ra màn hình 
    int binary = 0;
    stack<int> bit;
    while (n > 0){           // chia liên tiếp cho 2
        binary = n % 2;      // push phần dư vào stack
        bit.push(binary);
        n /= 2;
    }
    while (bit.size() < k){   // nếu số phần tử trong stack < số bit thì thêm số 0 và stack (vd 2 sang số nhị phân là 10 nhưng 2 trong 3bit là 010)
        bit.push(0);
    }
    while (!bit.empty()){     // in ra số trong stack (đọc từ dưới lên như khi số liên tuêps cho 2; số đầu của stack là số dư đọc từ cuối lên)
        cout<<bit.top()<<" ";
        bit.pop();
    }
}
 
int main (){
    int t, n; cin >> t;
    while (t--){
        cin >> n;
        for (int i = 0; i < (pow(2,n)); i++){    // 3 bit = 000 đến 111 (chính = từ 0 đến 2^3 - 1)
            binary(i, n);
            cout<<endl;
        }
    }
}