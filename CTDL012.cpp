//Cho số nguyên N. Nhiệm vụ của bạn cần tìm số nguyên X nhỏ nhất là bội của N, và X chỉ chứa hai chữ số 0 và 9.
#include <bits/stdc++.h>
using namespace std;
/*    // Đúng 9/10 test, test cuối thời gian >1s.
bool check(int n){
    while(n > 0 ){
        if (n % 10 != 0 && n % 10 != 9){
            return false;
        }
        n /= 10;
    }
    return true;
}
int main(){
    int t; cin >> t;
    while(t--){
       int n; cin >> n;
       int temp = 9;                              //??đề bài yêu cầu số có cả 0 và 9; 09 = 9 thì làm gì có 0;
       while(1){
            if (temp % n == 0 && check(temp)){
                cout<<temp;
                break;
            }
            temp += 9;
       }
       cout<<endl;
    }
}
*/

vector<int> string09;                          // tạo vector chứa các số kết hớp bởi 2 số 0 và 9.
void test(){
    int count = 1000;
    queue<int> x;
    x.push(9);
    string09.push_back(9);                     // ?? đề bài yêu cầu số có cả 0 và 9; 09 = 9 thì làm gì có 0;
    while(count > 0){
        int temp = x.front();
        x.pop();
        x.push(temp * 10);                     // vd 90
        string09.push_back(temp * 10);
        x.push(temp * 10 + 9);                 // vd 99
        string09.push_back(temp * 10 + 9);
        count--;
    }
}


int main(){
    int t; cin >> t;
    test();
    while(t--){
        int n; cin >> n;
        for (int i = 0; i < string09.size(); i++){    // xem số nào chia hết cho n thì cout và break (do chọn số bé nhất chia hết cho n)
            if (string09[i] % n == 0){
                cout<<string09[i]<<endl;
                break;
            }
        }
    }
}