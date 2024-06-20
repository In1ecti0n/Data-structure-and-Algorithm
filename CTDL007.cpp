#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    int n;
    while (t--){
        vector<int> temp;
        cin >> n;
        for (int i = n; i >= 1; i--){
            temp.push_back(i);
        }
        do{
            for (int i = 0; i < temp.size(); i++){
                cout<<temp[i];
            }
            cout<<" ";
        }while(prev_permutation(temp.begin(), temp.end()));
        cout<<endl;
    }
}