#include <bits/stdc++.h>
using namespace std;

int tich2so(int x, int y){
    return x * y;
}

int power(int A, int K) {
    if (K == 1) {
        return A;
    }
    int B = power(A, K / 2);
    B = tich2so(B, B);
    if (K % 2 == 1) {
        B = tich2so(B, A);
    }
    return B;
}