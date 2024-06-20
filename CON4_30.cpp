// Dãy số Fibonacci được xác định bằng công thức như sau:F[0] = 0, F[1] = 1;F[n] = F[n-1] + F[n-2] với mọi n >= 2.Các phần tử đầu tiên của dãy số là 0, 1, 1, 2, 3, 5, 8, ...Nhiệm vụ của bạn là hãy xác định số Fibonaci thứ n. Do đáp số có thể rất lớn, in ra kết quả theo modulo. Lưu ý 1<=n<= 10^18
// https://codeforces.com/blog/entry/14516
#include <bits/stdc++.h>
using namespace std;
const long M = 1000000007; 

map<long long, long long> F;

long long f(long long n) {
	if (F.count(n)) return F[n];
	long long k = n / 2;
	if (n % 2 == 0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	}else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}

main(){
    int t ; cin >> t;
    long long n;
    F[0]=F[1]=1;
    while(t--){
        cin >> n;
        cout << (n==0 ? 0 : f(n-1)) << endl;
    }
}

/* //  mất nhiều thời gian do ko dùng hàm map, các số đã tính phải tính lại 1 lần nx gây mất thời gian
#include <bits/stdc++.h>
using namespace std;
const long long mod = 100000007;
long long check(long long n){
    if (n == 0){
        return 1;
    }
    if (n == 1){
        return 1;
    }
    long long k = n / 2;
    if (n % 2 == 0){
        return (check(k) * check(k) + check(k - 1) * check (k - 1)) % mod;
    }else{
        return (check(k) * check(k + 1) + check(k - 1) * check(k)) % mod;
    }
}


int main(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        cout<<check(n - 1)<<endl;
    }
}
*/


/* ko bt đúng ko nhưng cực tốn bộ nhớ,  dùng vector để lưu giá trị đã tính để tránh tính lại. 
#include <bits/stdc++.h>
using namespace std;
const long long mod = 100000007;
vector<long long> fibonaci(100000007);
long long check(long long n){
    if (n == 0 || n == 1){
        return fibonaci[n];
    }
    if (fibonaci[n] != 0){
        return fibonaci[n];
    }
    
    long long k = n / 2;
    if (n % 2 == 0){
        fibonaci[k] = check(k);
        fibonaci[k - 1] = check(k - 1);
        return (check(k) * check(k) + check(k - 1) * check (k - 1)) % mod;
    }else{
        fibonaci[k] = check(k);
        fibonaci[k - 1] = check(k - 1);
        fibonaci[k + 1] = check(k + 1);
        return (check(k) * check(k + 1) + check(k - 1) * check(k)) % mod;
    }
}


int main(){
    int t; cin >> t;
    fibonaci[0] = fibonaci[1] = 1;
    while(t--){
        long long n; cin >> n;
        cout<<check(n - 1)<<endl;
    }
}
*/