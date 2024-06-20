// Một phân số đơn vị nếu tử số của phân số đó là 1. Mọi phân số nguyên dương đều có thể biểu diễn thành tổng các phân số đơn vị. Ví dụ 2/3 = 1/2 + 1/6. Cho phân số nguyên dương P/Q bất kỳ (P < Q), hãy biểu diễn phân số nguyên dương thành tổng phân số đơn vị.
#include <bits/stdc++.h>
using namespace std;

/*
vector<int> temp;
void uocso(int mauso, int tuso){            // ham lấy các ước của mẫu số bé hơn tử số
    for (int i = 1; i < tuso; i++){
        if (mauso % i == 0){
            temp.push_back(i);
        }
    }
}

void check(int tuso, int mauso){
    queue<int>phansodonvi;  // chứa các mẫu số của phân số đơn vị
    uocso(mauso, tuso);
    for (int i = temp.size() - 1; i >= 0; i--){                 // hàm tách thành các phân số đơn vị
        if(tuso >= temp[i]){                                    // vd 13/28 = (2 + 4 + 7)/28 = 1/14 + 1/7 + 1/4;  (trừ dần tử số cho các ước số theo thứ tự giảm dần sao cho tuso = 0, nếu tuso đã trừ < ước số đang xét thì bỏ qua xét ước số tiếp theo vd 10/28 thì 10 - 7 - 2 - 1 do 10 - 7 = 3 < 4 bỏ qua 4)
            tuso -= temp[i];
            phansodonvi.push(mauso / temp[i]);
        }
    }
    while(!phansodonvi.empty()){
        cout<<1<<'/'<<phansodonvi.front();
        phansodonvi.pop();
        if (!phansodonvi.empty()){
            cout<<" ";
            cout<<'+';
        }
        cout<<" ";
        
    }
}


int main(){
    int t; cin >> t;
    while(t--){
        int tuso, mauso;
        cin >> tuso >> mauso;
        if (tuso == 1){
            cout<<tuso<<'/'<<mauso;
        }else if(mauso < 9 && mauso % 2 != 0){ // vd 3 5 7
            mauso *= 2;
            tuso *= 2;
            check(tuso, mauso);
        }else{
            check(tuso, mauso);
        }
        cout<<endl;
    }
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
/*
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}*/

/*
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


void check (int tuso, int mauso){
    if (tuso == 1){
        cout<<tuso<<'/'<<mauso;
        return;
    }
    int temp = (mauso / tuso) + 1;
    cout<<1<<'/'<<temp<<" + ";
    tuso = temp*tuso - mauso;
    mauso = mauso*temp;
    int ucln = gcd(tuso, mauso);
    tuso /= ucln;
    mauso /= ucln;
    check(tuso, mauso);
}


int main(){
    int t; cin >> t;
    while(t--){
        int tuso, mauso;
        cin >> tuso >> mauso;
        check(tuso, mauso);
        cout<<endl;
    }
}
*/
/*
int main(){
    int t;
	cin >> t;
	while(t--){
        long long a, b, n, m, x;
        cin >> a >> b;
        while (b % a != 0){
            n = a;
            m = b;
            x = b / a;
            cout << 1 << "/" << x + 1 << " + ";
            a = (x + 1) * n - m;
            b = (x + 1) * b;
           
        }
        cout << 1 << "/" << b / a;
        cout <<'\n';
	}
}

*/


/*
void check (long long tuso, long long mauso){
    if (mauso % tuso == 0){
        cout << 1 << "/" << mauso / tuso;
        return;
    }
    long long temp = mauso / tuso + 1;
    cout << 1 << "/" << temp << " + ";
    tuso = temp * tuso - mauso;
    mauso = temp * mauso;
    check(tuso, mauso);
}


int main(){
    int t; cin >> t;
    while(t--){
        long long tuso, mauso;
        cin >> tuso >> mauso;
        check(tuso, mauso);
        cout<<endl;
    }
}

*/


/*
void check (int tuso, int mauso){
    if (tuso == 1){
        cout<<tuso<<'/'<<mauso;
        return;
    }
    int temp = mauso / tuso + 1;
    cout << 1 << '/' << temp << " + ";
    tuso = temp*tuso - mauso;
    mauso = mauso*temp;
    if (mauso % tuso == 0){
        cout << 1 << '/' << mauso / tuso;
        return;
    }
    check(tuso, mauso);
}


int main(){
    int t; cin >> t;
    while(t--){
        int tuso, mauso;
        cin >> tuso >> mauso;
        check(tuso, mauso);
        cout<<endl;
    }
}
*/