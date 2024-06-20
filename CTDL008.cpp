#include <bits/stdc++.h>
using namespace std;



/*  ??? Runtime Error
void gray(vector<char> &binary){
    queue<char> temp;
    temp.push(binary[0]);
    for (int i = 1; i < binary.size(); i++){
        if (binary[i-1] == binary[i]){
            temp.push('0');
        }else{
            temp.push('1');
        }
    }
    while(!temp.empty()){
        cout<<temp.front();
        temp.pop();
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        vector<char> binary;
        for (int i = 0; i < s.size(); i++){
            binary.push_back(s[i]);
        }
        gray(binary);
        cout<<endl;
    }
}
*/
void gray(string s){                 // chuyển đổi nhị phân sang gray bằng cách dùng phép toán thao tác bit XOR
    queue<char> temp;
    temp.push(s[0]);                 // kí tự đầu tiên khi chuyển từ nhị phân sang mã gray luôn giống nhau
    for (int i = 1; i < s.size(); i++){     // xét lần lượt các kí tự sau kí tự đầu tiên, giống nhau thì = 0 khác nhau thì = 1, cho vào queue và in ra, đó chính là mã gray
        if (s[i-1] == s[i]){
            temp.push('0');
        }else{
            temp.push('1');
        }
    }
    while(!temp.empty()){
        cout<<temp.front();
        temp.pop();
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        gray(s);
        cout<<endl;
    }
}