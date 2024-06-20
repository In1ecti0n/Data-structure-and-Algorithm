/*
Cho một xâu chỉ gồm các kí tự ‘(‘ và ‘)’. Một dãy ngoặc đúng được định nghĩa như sau:

- Xâu rỗng là 1 dãy ngoặc đúng.

- Nếu A là 1 dãy ngoặc đúng thì (A) là 1 dãy ngoặc đúng.

- Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.

Cho một xâu S. Nhiệm vụ của bạn là hãy tìm dãy ngoặc đúng dài nhất xuất hiện trong xâu đã cho.
*/
#include <bits/stdc++.h>
using namespace std;


void test(string s){                 // hàm push index của các dấu ngoặc sai (dấu ngoặc khiến dãy ngoặc đúng bị ngắt)
    int ans = 0;
    stack<int> temp;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            temp.push(i);
        }else{
            if (!temp.empty() && s[temp.top()] == '('){
                temp.pop();
            }else{
                temp.push(i);
            }
        }
    }
    int end = s.size();       
    while(!temp.empty()){            // tính khoảng cách giữa các dấu ngoặc sai (do tồn tại dãy ngoặc đúng giữa các ngoặc sai)
        int now = temp.top();         // vi dụ " ()() ) ()() ) ", index ngoặc sai trong stack là 4 và 9, suy ra giữa 0 và 4, 4 và 9, 9 và 10(10 là kích thước của xâu ban đầu)(khả năng có dãy ngoặc đúng sau index 9) 
        temp.pop();
        ans = max(ans, end - now - 1);    // tìm ra dãy ngoặc đúng dài nhất
        end = now;
    }
    cout<<max(ans, end);
    
}


int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        test(s);
        cout<<endl;
    }
}


/*
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        stack<pair<char, int>> st;
        int ans = 0, n = s.size();
        vector<int> F(n, 0);
        for (int i = 0; i < n; i++){
            if (s[i] == ')' && !st.empty() && st.top().first == '('){
                F[i] = F[i - 1];
                if (st.top().second != 0)
                    F[i] += F[st.top().second - 1];
                F[i] += 2;
                st.pop();
            }
            else{
                st.push({s[i], i});
            }
        }
        for (int i = 0; i < n; i++){
            ans = max(ans, F[i]);
        }    
        cout << ans << endl;
    }
}
*/


/*
void test(string s){
    int ans = 0;
    stack<pair<char, int>> temp;
    vector<int> temp1(s.size(), 0);
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ')'){
            if (!temp.empty() && temp.top().first == '('){
                temp1[i] = temp1[i - 1];
                if (temp.top().second != 0){
                    temp1[i] += temp1[temp.top().second - 1];
                }
                temp1[i] += 2;
                temp.pop();
            }else{
                temp.push({s[i], i});
            }

        }else{
            temp.push({s[i], i});
        }
    }

}
*/