// Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất. Biết chi phí nốisợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j].
// vd {4,3,2,6}, muốn chi phí nhỏ nhất thì lấy 2 dây bé nhất cộng lại = x rồi nhét x lại vào dãy.
// (2,3,4,6), 2 + 3 = 5 (4,5,6), 4+5 = 9 (6,9), 6 + 9 = 15. 5 + 9 + 15 = 29.
#include <bits/stdc++.h>
using namespace std;

void check(vector<int> temp){             
    deque<int> test;                        // chứa độ dài các dây, lấy 2 dây có độ dài bé nhất để cộng
    int sum = 0;                            // tổng chi phí nối dây
    for (int i = 0; i < temp.size(); i++){
        test.push_back(temp[i]);
    }
    while(test.size() > 1){                 // nếu test còn 1 giá trị thì ngừng, tránh lỗi do pop_front 2 lần
        int a = test.front();     
        test.pop_front();
        int b = test.front();
        test.pop_front();
        sum += a + b;                      // cộng 2 dây có độ dài bé nhất
        test.push_front(a + b);
        vector<int> s(test.begin(), test.end());   // copy giá trị trong deque ra vector
        sort(s.begin(), s.end());                  // sắp xếp tăng dần
        test.assign(s.begin(), s.end());           // copy giá trị đã tăng dần vào deque để tiếp tục xử lý.
        // 3 dòng trên có thể rút gọn lại = sort(test.begin(), test.end());
    }
    cout << sum;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> temp(n);
        for (int i = 0; i < n; i++){
            cin >> temp[i];
        }
        sort(temp.begin(), temp.end());    // sắp xếp theo thứ tự tăn dần của vector chứa độ dài các dây.
        check(temp);
        cout<<endl;
    }
}