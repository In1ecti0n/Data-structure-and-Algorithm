// Cho dãy số A[] gồm N phần tử. Với mỗi A[i], bạn cần tìm phần tử bên phải đầu tiên lớn hơn nó.Nếu không tồn tại, in ra -1.
/*
3
4
4 5 2 25
3
2 2 2
4
4 4 5 5

5 25 25 -1
-1 -1 -1
5 5 -1 -1
*/
#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        stack <long long> temp;
        vector<int> ans;
        ans.push_back(-1);
        temp.push(arr[n - 1]);
        for (int i = n - 2; i >= 0; i--){
            if (!temp.empty() && arr[i] < temp.top()){
                ans.push_back(temp.top());
                temp.push(arr[i]);
            }else{
                while(!temp.empty() && arr[i] >= temp.top()){
                    temp.pop();
                }
                if (temp.empty()){
                    ans.push_back(-1);
                    temp.push(arr[i]);
                }else{
                    ans.push_back(temp.top());
                    temp.push(arr[i]);
                }
            }
        }
        for (int i = ans.size() - 1; i >= 0; i--){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}