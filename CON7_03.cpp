// Cho một xâu ký tự str bao gồm nhiều từ trong xâu. Hãy đảo ngược từng từ trong xâu?
/*
2
ABC DEF
123 456

CBA FED
321 654
*/

#include <bits/stdc++.h>
using namespace std;


void test(string s){
    stack<char> temp;
    for (char c : s){
        if(!temp.empty() && c == ','){
            while(!temp.empty()){
                cout<<temp.top();
                temp.pop();
            }
            cout<< " ";
        }else{
            temp.push(c);
        }
    }
}


int main(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        for (char& c : s){    //tham chiếu (nếu ko, char c ở đây được độc lập với phần tử trong xâu s )
            if (c ==  ' '){
                c = ',';       //đánh dấu vị trí khoẳng trắng bằng dấu ',' (ABC,CDE,)
            }
        }
        s.push_back(',');
        test(s);
        cout<<endl;
    }
}