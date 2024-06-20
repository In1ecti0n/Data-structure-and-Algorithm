#include <bits/stdc++.h>
using namespace std;
// Cho một chuỗi chứa các ký tự đại diện '0', '1' và '?' tạo ra tất cả các chuỗi nhị phân có thể được hình thành bằng cách thay thế mỗi ký tự đại diện bằng '0' hoặc '1'.


/*
// cach nhanh nhat (su dung de quy) hoac co the su dung queue
void ans(string str, int index){
	if (index == str.size()){
		cout << str << endl;
		return;
	}

	if (str[index] == '?'){
		str[index] = '0';
		ans(str, index + 1);
		str[index] = '1';
		ans(str, index + 1);
	}
	else
		ans(str, index + 1);
}
*/


// Cách chậm hơn (tự nghĩ)
vector<int> spilt(vector<int> &binary){              // tạo một hàm trả về hoán vị của tập hợp nhị phân (đầu vào 000 đầu ra là 001)
    for (int i = binary.size() - 1; i >= 0; i--){
        if (binary[i] == 0){
            binary[i] = 1;
            return binary;
        }else{
            binary[i] = 0;
        }
    }
    return binary;
}

void ans(string &s){                              // hàm in ra trường hợp thay thế dấu ?
    int arr[10001];                                 // mảng đánh dấu index của dấu ? trong string 
    vector<int> binary;                              // vector chứa giá trị thay thế cho dấu ?
    int count = 0;                                  // đếm dấu ?, số kết quả in ra = 2^count (vd có 3 dấu ? tương ứng vs ??? (từ 000 đến 111 có 2^3 = 8 giá trị))
    memset(arr, 0, sizeof(arr));                    // đặt tất cả mảng = 0
    for (int i = 0; i < s.size(); i++){             
        if (s[i] == '?'){                          // nếu s[i] == '?' thì count + 1; vị trí trong arr[index] = 1 tương ứng vs index trong string
            count++;
            arr[i] = 1;
            binary.push_back(0);                  // thêm 0 vào tương ứng vs trường hợp đầu tiên (thay dấu ? = 0)  (vd ??? = 000)
        }
    }
    for (int i = 1; i <= pow(2, count); i++){     //vòng lặp số trường hợp đc in ra
        int coutx = 0;                            // index của vector binary
        for (int j = 0; j < s.size(); j++){       
            if(arr[j] == 1){                        // nếu arr[index] = 1 tương ứng vs s[index] = ?
                s[j] = binary[coutx] + '0';         // thay ? bằng binary[index] (vd: s[index của dấu ? đầu tiên] = binary[index phần tử đầu tiên])
                coutx++;                            // tăng index để kí tự ? tiếp theo tương ứng vs phần tử tiếp theo trong vector
            }
        }
        for (int k = 0; k < s.size(); k++){
            cout<<s[k];                             // in string s đã được thay thế dấu ?
        }
        cout<<endl;
        spilt(binary);                             // tham chiếu hoán vị tiếp theo của đấu ?   (vd: ??? - 000 - 001 - 010 - 100 - ....)
    }
}

int main(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s; 
        getline(cin, s);
        s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());   // xóa khoảng trắng khi nhập string
        ans(s);
    }
}