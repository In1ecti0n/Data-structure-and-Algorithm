#include <bits/stdc++.h>
using namespace std;

int arr[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
int main(){
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < 10; i++){
            while(n >= arr[i]){
                ans += (n / arr[i]);
                n %= arr[i];
            }
        }
        cout<<ans<<endl;
    }
}