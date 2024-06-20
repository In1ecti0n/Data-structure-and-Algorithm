#include <bits/stdc++.h>
using namespace std;


void test(string s){
    stack<int> ans;
    int num = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'D'){
            if (i == 0 || s[i - 1] == 'I'){
                ans.push(++num);
            }
            ans.push(++num);
        }else{
            while(!ans.empty()){
                cout<<ans.top();
                ans.pop();
            }
            if (i == 0){
                cout<<++num;
            }
            if (s[i + 1] != 'D'){    //s[i+1] ngoài kích thước s có thể được tính (đại diện cho I trước nó là cuối cùng), vd DI = 213
                cout<<++num;
            }
        }
    }
    while (!ans.empty()){
        cout<<ans.top();
        ans.pop();
    }
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
void solution()
{
    string s;
    stack<int> mystack;
    cin >> s;
    int i, j = 0;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == 'D')
        {
            if (i == 0 || s[i - 1] == 'I')
                mystack.push(++j);
            mystack.push(++j);
        }
        else
        {
            while (!mystack.empty())
            {
                cout << mystack.top();
                mystack.pop();
            }
            if (i == 0)
                cout << ++j;
            if (s[i + 1] != 'D')
                cout << ++j;
        }
    }
}
*/