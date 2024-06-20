// Cho 2 số nguyên n, k. Bạn hãy tính C(n, k) modulo 
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
/*
// Với n va r nhỏ
int main() {
        int t; cin >> t;
        while(t--){
            int n, r;
            double sum = 1;
            cin >> n >> r;
            for(int i = 1; i <= r; i++){      // Công thức hệ thức Newton: (1 + x)^bn = sigma(k = 0, n){nCk * x^k}
                sum = sum * (n - r + i) / i;
            }
            cout<<(int)sum<<endl;
        }
}
*/

/*
int binomialCoeff(int n, int k)
{
	int C[n + 1][k + 1];
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= min(i, k); j++) {    // min để kiểm soát sao cho j ko > i (hay k ko lớn hơn n của nCk)
			if (j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	return C[n][k];
}
*/

/*
int arr[1001][1001];
void check(){
    arr[0][0] = 1;
    for (int i = 1; i < 1001; i++){
        arr[i][0] = 1;
        for (int j = 1; j < 1001; j++){
            arr[i][j] = (arr[i - 1][j - 1] % mod + arr[i - 1][j] % mod) % mod;
        }
    }
}
*/
int arr[1001][1001];
void check(){
    for (int i = 0; i <= 1000; i++){
        for (int j = 0; j <= 1000; j++){
            if (j > i) arr[i][j] = 0;    // dòng này có hoặc không cx đc, vì lúc khởi tạo mảng toàn cục arr, các giá trị trong mảng đã toàn = 0 rồi.
            if (j == 0 || j == i){
                arr[i][j] = 1;
            }else{
                arr[i][j] = (arr[i - 1][j - 1] % mod + arr[i - 1][j] % mod) % mod;
            }
        }
    }
}

int main(){
    int t; cin >> t;
    check();
    while(t--){
        int n, k;
        cin >> n >> k;
        cout<<arr[n][k];    //arr[i][j]
        cout<<endl;
    }
}


