// Cho biểu thức số học, hãy cho biết biểu thức số học có dư thừa các cặp ký hiệu ‘(’,’) ‘ haykhông?
/*
3
((a+b))
(a + (b)/c)
(a + b*(c-d))

Yes
Yes
No
*/
#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s; getline(cin, s);
        bool check = false;
        stack<char> temp;
        for (char c : s){
            if (c == '+' || c == '-'|| c == '*' || c == '/' || c == '('){
                temp.push(c);
            }
            if (c == ')'){
                if (temp.top() == '('){                // nếu bắt gặp ngay mở ngoặc đầu stack có nghĩa là ko có toán tử nào, suy ra mở ngoặc đầu stack bị thừa, break vòng lặp, end
                    check = true;
                    break;
                }
                while(!temp.empty() && temp.top() != '('){
                    temp.pop();
                }
                temp.pop();
            }
        }
        if (check){                
            cout<<"Yes"<<endl;     // ko có toán tử trong ngoặc, suy ra ngoặc thừa
        }else{                     
            cout<<"No"<<endl;     // có toán tử trong ngoặc
        }
    }
}

/* Như trên nhưng thiết lập điều kiện khác nhau
#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        bool check, final = false;
        stack<char> temp;
        for (char c : s){
            if (c == '+' || c == '-'|| c == '*' || c == '/'){
                temp.push(c);
            }
            if (c == '('){
                temp.push(c);
            }
            if (c == ')' && !temp.empty()){
                while(!temp.empty() && temp.top() != '('){
                    if (temp.top() == '+' || temp.top() == '-' || temp.top() == '*'  ||  temp.top() == '/'){
                        check = true;        
                    }
                    temp.pop();
                }
                if (check){
                    check = false;
                }else{
                    final = true;
                }
                temp.pop();
            }
        }
        if (final){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        
    }
}
*/