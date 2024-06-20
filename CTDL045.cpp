// Cho xâu ký tự S bao gồm các ký tự in thường. Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt lại các ký tự trong S để hai ký tự giống nhau đều không kề nhau hay không? Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1
#include <bits/stdc++.h>
using namespace std;


void check(string s){
    map<char, int> mp;                    // khởi tạo map<key, value> để lưu số lần xuất hiện của mỗi ký tự. 
    for (int i = 0; i < s.size(); i++){
        mp[s[i]]++;                       // cách hoạt động: mp[s[i]] sẽ tìm key trong map, nếu có nó sẽ thực hiện tăng value; nếu không, nó sẽ thực hiện insert key mới vào map (tham khảo https://en.cppreference.com/w/cpp/container/map)
    }
    int temp = 0;                        // tạo biến so sánh value của từng cặp trong map (là số lần xuất hiênj mỗi ký tự)
    for (auto pair : mp){                // vòng lặp (auto sẽ tự động chọn kiểu dữ liệu cho pair)
        if (pair.second > temp){         //pair.second = value của cặp <key, value>
            temp = pair.second;          // cập nhật temp
        }
    }
    if (temp < (s.size() / 2) ){         // nếu temp(số lần xuất hiện mỗi ký tự) > nửa chiều dài thì chắc chắn có ít nhất có 2 kí tự giông nhau đứng sát nhau. 
        cout<< 1;
    }else{
        cout<< - 1;
    }
}   

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        check(s);
        cout<<endl;
    }
}