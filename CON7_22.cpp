// (HÌNH CHỮ NHẬT LỚN NHẤT) Cho N cột, mỗi cột có chiều cao bằng H[i]. Bạn hãy tìm hình chữ nhật lớn nhất bị che phủ bởi các cột?
// https://daynhauhoc.com/t/tim-hinh-chu-nhat-lon-nhat-tren-spoj/97085/3
#include <bits/stdc++.h>
using namespace std;

void test(long long arr[], long long n){   // cách dùng stack, O(n)
    stack<int> index;                      // chứa index của cột trong mảng
}

int main(){                          // duyệt cố định cột i,  tìm sang bên trái và bên phải cột đầu tiên nhỏ hơn cột thứ i, O(n ^ 2)
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        long long ans = 0;
        long long arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++){
            int begin = i, end = i;
            while(begin >= 0 && arr[begin] >= arr[i]){
                begin--;
            }
            while(end < n && arr[end] >= arr[i]){
                end++;
            }
            ans = max(ans, arr[i] * ((end - 1) - (begin + 1) + 1));
        }
        cout<<ans<<endl;
    }
}