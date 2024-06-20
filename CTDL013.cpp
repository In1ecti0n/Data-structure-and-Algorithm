//Cho hai số nguyên dương N và K. Nhiệm vụ của bạn là hãy liệt kê tất cả các tập con K phần  tử của 1, 2, .., N. Ví dụ với N=5, K=3 ta có 10 tập con của 1, 2, 3, 4, 5 như sau: {1, 2, 3}, {1, 2, 4},{1, 2, 5},{1, 3, 4},{1, 3, 5},{1, 4, 5},{2, 3, 4},{2, 3, 5},{2, 4, 5},{3, 4, 5}.
#include <bits/stdc++.h>
using namespace std;
 /*
vector<int> temp;
void dequy(int k, int index, int n){
    for (int i = index; i <= n; i++){
        temp.push_back(i);
        if (temp.size() == k){
            for (int i : temp){
                cout<<i;
            }
            cout<<" ";
        }else{
            dequy(k, temp.back() + 1, n);        
        }
        temp.pop_back();
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        dequy(k, 1, n);
        cout<<endl;
    }
}
*/
  
/*
vector<int> temp;                            // vector chứa 1 tổ hợp con
void dequy(int k, int index, int n){         //backtracking
    for (int i = index + 1; i <= n; i++){
        temp.push_back(i);
        if (temp.size() == k){            // in ra số trong vector
            for (int i : temp){
                cout<<i;
            }
            cout<<" ";
        }else{
            dequy(k, temp.back(), n);    // gọi đệ quy để thêm giá trị tiếp theo vào vector (VD đang có {12} thì giá trị tiếp theo cần thêm vào sẽ là 3 hoặc 4)
        }
        temp.pop_back();                // quay lui (lúc này vector đang có giá trị 123, bỏ 3 kết thúc 1 lần vòng lặp với i = 3, tiếp đến vòng lặp i = 4 thì thêm 4 vào thành 124)
    }                                   // tương tự lúc 124, bỏ 4 vòng lặp i = 5 > n = 4, kết thúc lặp, hàm đệ quy trước đó  với vòng lặp i = 2 sẽ chạy tiếp đến hàm pop.back(), loại 2 ra vector còn 1, vòng lặp tiếp theo với i = 3 thêm vào vector = {13}.
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        dequy(k, 0, n);
        cout<<endl;
    }
}
*/

// xem lại cách dưới, nghĩ theo hướng tăng dần 1 số đến tổ hơpj cuối cùng 123 đến 234, có vẻ no hope
