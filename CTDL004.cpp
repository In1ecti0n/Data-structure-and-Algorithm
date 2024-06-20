#include <bits/stdc++.h>
using namespace std;
// Xâu ký tự str được gọi là xâu AB nếu mỗi ký tựtrong xâu hoặc là ký tự ‘A’ hoặc là ký tự ‘B’. Ví dụ xâu str=”ABBABB” là xâu ABđộ dài 6. Nhiệm vụ của bạn là hãy liệt kê tất cả các xâuAB có độ dài n.
void sinhtohop(vector<char> &temp, int n){            // hàm sinh hoán vị 
        for (int i = temp.size() - 1; i >= 0; i--){   // chạy từ cuối lên 
                if (temp[i] == 'A'){                  // nếu gặp A thì đổi A thành B và kết thúc (vd từ AAAA thì xâu tiếp theo là AAAB)
                        temp[i] = 'B';
                        return;
                }else{
                        temp[i] = 'A';                // nếu gặp B thì đổi B thành A và tiếp tục vòng lặp đến kí tự kế tiếp nó (vd từ AABB thì xâu tiếp theo là ABAA)                                                            
                }
        }
}
bool check(vector<char> &temp, int n){           // kiểm tra điều kiện của xâu
        for (int i = 0; i < temp.size(); i++){
                if (temp[i] == 'A'){               // nếu xâu có kí tự A thì thưcj hiện sinh hoán vị
                        sinhtohop(temp, n);
                        return true;             // true, vòng lặp có thể tiếp tục sinh hoán vị
                }
        }
        return false;                            //false, lúc này vector chỉ toàn kí tự 'B' nên ko còn hoán vị theo thứ tự từ điển, (nghĩa là đã in ra các xâu từ kí tự toàn A đến kí tự toàn B)
}

int main(){
    int t; cin >> t;
    int n;
    while(t--){
        cin >> n;
        vector<char> temp;
        for (int i = 0; i < n; i++){     // tạo vector toàn A
                temp.push_back('A');
        }
        do {
                for (int i = 0; i < temp.size(); i++){     // in ra xâu đầu tiên toàn A
                        cout<<temp[i];
                }
                cout<< " ";
        }while(check(temp, n));         // kiểm tra điều kiện và thực hiện sinh tổ hợp hoán vị
        cout<<endl;
        
    }
}




