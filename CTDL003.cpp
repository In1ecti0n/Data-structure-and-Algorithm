#include <bits/stdc++.h>
using namespace std;
// Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân tiếp theo của X[]. Ví dụ X[] =”010101” thì xâu nhị phân tiếp theo của X[] là “010110”.
/*
// Cach toi uwu nhat (ap dung tinh chat cong so nhi phan 0 + 1 = 1; 1 + 1 = 10) so tiep theo trong day nhi phan se +1 (gap so 1 se doi sang 0 nhớ 1; gap so 0 se doi sang 1 vaf break)
int main(){
    int t; cin >> t;
    string s; 
    while(t--){
        cin >> s;
        for (int i = s.size()- 1; i >= 0; i--){
            if (s[i] == '1'){
                s[i] = '0';
            }else{
                s[i] = '1';
                break;
            }
        }
        cout<<s<<endl;
    }
}

*/
bool check(vector<int>x){
    for (int i = 0; i < x.size(); i++){
        if (x[i] == 0){
            return false;
        }
    }
    return true;
}

long long decimal(vector<int> x){
    long long ans = 0;
    long long temp = 0;
    for (int i = x.size() - 1; i >= 0; i--){
        ans += x[i] * pow(2, temp);
        temp++;
    }
    return ans;
}

void binary (long long n, int k){  // ham chuyển đổi số thập phân sang nhị phân và in ra màn hình 
    stack<int> bit;
    while (n > 0){           // chia liên tiếp cho 2 
        bit.push(n % 2);
        n /= 2;
    }
    while (bit.size() < k){   // nếu số phần tử trong stack < số bit thì thêm số 0 và stack (vd 2 sang số nhị phân là 10 nhưng 2 trong 3bit là 010)
        bit.push(0);
    }
    while (!bit.empty()){     // in ra số trong stack (đọc từ dưới lên như khi số liên tuêps cho 2; số đầu của stack là số dư đọc từ cuối lên)
        cout<<bit.top();
        bit.pop();
    }
}

int main(){                            // xem lai loi cho nao, đầu vào nhị phân dài quá thì kết quả ra toàn 0.
    int t; cin >> t;
    string s;
    while(t--){
        cin >> s;
        vector<int> x;
        for (char c : s){
            x.push_back(c - '0');
        }
        if (check(x)){
            for (int i = 0; i < x.size(); i++){
                cout<<0;
            }
        }else{
            long long temp = decimal(x);
            temp++;
            binary(temp, x.size());
        }
        cout<<endl;
    }
}