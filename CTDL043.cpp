// Cho hệ gồm N hành động. Mỗi hành động được biểu diễn như một bộ đôitương ứng với thời gian bắt đầu và thời gian kết thúc của mỗi hành động. Hãy tìm phương án thực hiện nhiều nhất các hành động được thực hiện bởi một máy hoặc một người sao cho hệ không xảy ra mâu thuẫn
/*
1
6
1 3 0 5 8 5
2 4 6 7 9 9
*/
#include <bits/stdc++.h>
using namespace std;

void check(vector<vector<int>> arr, int n){
    for (int i = n - 1; i >= 0; i--){
        for (int j = 1; j <= i; j++){
            if(arr[1][j - 1] > arr[1][j]){
                swap(arr[1][j - 1], arr[1][j]);
                swap(arr[0][j - 1], arr[0][j]);
            }
        }
    }
    int ans = 1;
    for (int i = 1; i < n; i++){
        if (arr[0][i] >= arr[1][i - 1]){
            ans++;
        }else{
            arr[1][i] = arr[1][i - 1];
        }
    }
    /*   // hoặc 
    int ans = 1;
    for (int i = 0; i < n - 1; i++){
        if (arr[0][i+1] >= arr[1][i]){
            ans++;
        }else{
            arr[1][i+1] = arr[1][i];
        }
    }
    */
    cout<<ans<<endl;
}
/*
void check(vector<vector<int>> arr, int n){
    for (int i = n - 1; i >= 0; i--){
        for (int j = 1; j <= i; j++){
            if(arr[1][j - 1] > arr[1][j]){
                swap(arr[1][j - 1], arr[1][j]);
                swap(arr[0][j - 1], arr[0][j]);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n - 1; i++){
        if (arr[1][i] <= arr[0][i+1]){
            ans++;
        }else{
            arr[1][i+1] = arr[1][i];
            continue;
        }
    }
    cout<<ans<<endl;
}
*/

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> arr(2, vector<int>(n));
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        check(arr, n);
    }
}