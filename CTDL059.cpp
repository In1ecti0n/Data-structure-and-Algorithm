// Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N-1 phần tử. Các phần tử của mảng A[] chỉ khác mảng B[] một phần tử duy nhất. Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[].
#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        bool check = 0;
        long long arr1[n], arr2[n-1];
        for (long long i = 0; i < n; i++){
            cin >> arr1[i];
        }
        for (long long i = 0; i < n - 1; i++){
            cin >> arr2[i];
        }
        for (long long i = 0; i < n - 1; i++){
            if (arr1[i] != arr2[i]){
                cout<< i + 1<<endl;
                check = 1;
                break;
            }
        }
        if (!check){
            cout<<n<<endl;
        }
    }
}