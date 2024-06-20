
/*
typedef vector<vector<long long>> matrix;

matrix multiply(matrix A, matrix B) {
    int N = A.size();
    matrix result(N, vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return result;
}

matrix power(matrix A, int K) {
    int N = A.size();
    if (K == 0) {
        matrix identity(N, vector<long long>(N));
        for (int i = 0; i < N; i++) {
            identity[i][i] = 1;
        }
        return identity;
    }
    if (K == 1) {
        return A;
    }
    matrix B = power(A, K / 2);
    B = multiply(B, B);
    if (K % 2) {
        B = multiply(B, A);
    }
    return B;
}

long long solve(matrix A, int K) {
    matrix X = power(A, K);
    long long trace = 0;
    for (int i = 0; i < A.size(); i++) {
        trace = (trace + X[i][i]) % MOD;
    }
    return trace;
}


int main(){
    int t; cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        vector<vector<long long>> A(n, vector<long long>(n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> A[i][j];
            }
        }
        cout<<solve(A, k)<<endl;

    }    
        
}
*/

#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

vector<vector<long long>> nhan2vector (vector<vector<long long>> x, vector<vector<long long>> y, long long n){    // hàm tính tích 2 ma trận
    vector<vector<long long>> ans(n, vector<long long>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int p = 0; p < n; p++){
                ans[i][j] = (ans[i][j] + x[i][p] * y[p][j]) % mod;
            }
        }
    }    
    return ans;
}
//


vector<vector<long long>> luythua (vector<vector<long long>> matrix, long long n, long long k){
    vector<vector<long long>> ans(n, vector<long long>(n));
    if (k == 1){
        return matrix;
    }
    ans = luythua(matrix, n, k / 2);
    ans = nhan2vector(ans, ans, n);
    if (k % 2){
        ans = nhan2vector(ans, matrix, n);
    }
    return ans;
}
/* // vẫn đúng nhưng quá lâu
vector<vector<long long>> luythua (vector<vector<long long>> matrix, long long n, long long k){
    vector<vector<long long>> ans(n, vector<long long>(n));
    if (k == 1){
        return matrix;
    }
    if (k % 2 == 0){
        return ans = nhan2vector(luythua(matrix, n, k / 2), luythua(matrix, n, k/2), n);
    }else{
        return ans = nhan2vector(nhan2vector(luythua(matrix, n, k / 2), luythua(matrix, n, k/2), n), matrix, n);
    }
    return ans;
}
*/
/* nhanh tương tự cách đầu tiên
vector<vector<long long>> luythua (vector<vector<long long>> matrix, long long n, long long k){
    vector<vector<long long>> ans(n, vector<long long>(n));
    ans = nhan2vector(matrix, matrix, n);
    k -= 2;
    while(k > 0){
        if (k % 2 == 1){
            ans = nhan2vector(ans, matrix, n);
        }
        matrix = nhan2vector(matrix, matrix, n);
        k /= 2;
    }
    return ans;
}
*/


void count(vector<vector<long long>> matrix, long long n, long long k){ // in kết quả tổng của đường chéo chính.
    vector<vector<long long>> ans = luythua(matrix, n, k);
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum = (sum + ans[i][i]) % mod;
    }
    cout<<sum;
}


int main(){
    int t; cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        vector<vector<long long>> matrix(n, vector<long long>(n));  // tạo ma trận 2 chiều với n hàng, mỗi hàng là 1 vector kích thước n
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> matrix[i][j];
            }
        }
        count(matrix, n, k);   
        cout<<endl; 
    }    
}