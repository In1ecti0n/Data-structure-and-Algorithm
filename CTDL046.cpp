//Giả sử bạn là một người nghèo trong địa phương của bạn. Địa phương của bạn có duy nhất một cửa hàng bán lương thực. Cửa hàng của bạn mở cửa tất cả các ngày trong tuần ngoại trừ chủ nhật. Cho bộ ba số N, S, M thỏa mãn ràng buộc sau:

//N : số đơn vị lương thực nhiều nhất bạn có thể mua trong ngày.

//S : số lượng ngày bạn cần được sử dụng lương thực để tồn tại.

//M : số đơn vị lương thực cần có mỗi ngày để bạn tồn tại.Giả sử bạn đang ở ngày thứ 2 trong tuần và cần tồn tại trong S ngày tới. Hãy cho biết số lượng ngày ít nhất bạn cần phải mua lương thực từ của hàng để tồn tại hoặc bạn sẽ bị chết đói trong S ngày tới.
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, s, m;
        cin >> n >> s >> m;
        int x = s - (s / 7);         // các ngày có thể mua lương thực (trừ chủ nhật nên mỗi tuần - 1); s/7 = số ngày chủ nhật
        if (n * x < s * m){          // nếu lượng lương thực mua được tối đa của tất cả các ngày có thể mua < lượng lương thực có thể sống sót trong s ngày
            cout<< -1;
        }else if ((m * s) % n == 0) {  // n*x = s * m suy ra kết quả chính = n
            cout<<(m * s) / n;
        }else{
            cout<<(m * s) / n + 1;     // n * x > s * m suy ra min x (số ngày mua ít nhất)
        }
        cout<<endl;
    }
}