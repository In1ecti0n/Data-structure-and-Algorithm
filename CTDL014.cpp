#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

using namespace std;
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
    int j = A.size() - 1;
    for (int i = 0; i < A.size(); i++) {
        trace = (trace + X[i][j]) % MOD;
        j--;
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