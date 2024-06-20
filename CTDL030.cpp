// Cho số tự nhiên K và xâu ký tự các chữ số S. Nhiệm vụ của bạn là đưa ra số lớn nhất bằng cách thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S. Ví dụ K =3 và S = “1234567” ta được “7654321” hoac 3435335 thanh 5543333. 1<=K<=10; s.size()<=7
#include <bits/stdc++.h>
using namespace std;

// hàm void check bên dưới có thể thay bằng hàm đề quy ngắn hơn nhiều (gọi đệ quy start = s.begin(), end = s.end(); hoán đổi vị trí rồi giảm dần end, tăng dần start và đệ quy)
void check(int k, string s){                
    stack<char> temp1;
    queue<char> temp2;
    int temp3;
    if (k <= s.size() /2){
        temp3 = k;
    }else{
        temp3 = s.size() / 2;
    }
    for (int i = 1; i <= temp3; i++){
        if(!s.empty()){
            temp1.push(s[0]);
            temp2.push(s[s.size() - 1]);
            s.erase(0,1);
            s.pop_back();
        }else{
            break;
        }
    }
    while(!temp2.empty()){
        cout<<temp2.front();
        temp2.pop();
    }
    cout<<s;
    while(!temp1.empty()){
        cout<<temp1.top();
        temp1.pop();
    }
}

int main (){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        string s; cin >> s;
        sort(s.begin(), s.end());
        check(k, s);
        cout<<endl;
    }
}


/*
// nhanh vlon ??
void check(int k, string s){             // số lớn nhất chắc chắn là string với các kí tự xếp giảm dần. 
    sort(s.begin(), s.end());            // xếp các kí tự tăng dần
    reverse(s.begin(), s.end());        // đảo
    cout<<s;
}

int main (){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        string s; cin >> s;
        check(k, s);
        cout<<endl;
    }
}
*/