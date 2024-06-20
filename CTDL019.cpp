#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int temp;
        vector<int> input;
        for (int i = 0; i < n; i++){
            cin >> temp;                // luu y ko dung dc cin >> input[i] do vector khởi tạo ban đầu ko có kích thước
            input.push_back(temp);
        }
        while(next_permutation(input.begin(), input.end())){
            for (int i = 0; i < input.size(); i++){
                cout<<input[i]<<" ";
            }
            break;
        }
        cout<<endl;
    }
}