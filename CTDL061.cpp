//Cho 2 xâu S1 và S2. Hãy tìm xâu con chung dài nhất của 2 xâu này (các phần tử không nhất thiết phải liên tiếp nhau).
//https://dothanhspyb.com/bai-toan-xau-con-chung-dai-nhat/
//https://interviewing.io/questions/longest-common-subsequence
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        vector<vector<int>> matrix(s1.size()+1, vector<int>(s2.size()+1, 0));
        for (int i = 0; i < s1.size(); i++){
            for (int j = 0; j < s2.size(); j++){
                if (s1[i] == s2[j]){
                    matrix[i+1][j+1] = matrix[i][j] + 1;
                }else{
                    matrix[i+1][j+1] = max(matrix[i+1][j], matrix[i][j+1]);
                }
            }
        }
        cout<<matrix[s1.size()][s2.size()]<<endl;
    }
}
// tại sao đặt array trong hàm main nếu ko memset thì array có giá trị rác, còn để ngoài hàm main thi array có giá trị 0. 
// https://stackoverflow.com/questions/73491264/what-is-the-difference-in-declaring-a-array-inside-the-int-main-and-outside-th
/*
int main(){
    int t; cin >> t;
    while(t--){
        int matrix[1000][1000];
        memset(matrix, 0, sizeof(matrix));
        string s1, s2;
        cin >> s1 >> s2;
        for (int i = 0; i < s1.size(); i++){
            for (int j = 0; j < s2.size(); j++){
                if (s1[i] == s2[j]){
                    matrix[i+1][j+1] = matrix[i][j] + 1;
                }else{
                    matrix[i+1][j+1] = max(matrix[i+1][j], matrix[i][j+1]);
                }
            }
        }
        cout<<matrix[s1.size()][s2.size()]<<endl;
    }
}
*/
