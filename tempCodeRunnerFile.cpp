#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
	cin >> t;
	while(t--){
        int n;
        cin >>n;
        queue<ll> q;
        int count = 1;
        q.push(9);
        while(q.size()){
            ll k = q.front(); q.pop();
            if(k % n == 0) {cout <<k <<" "<<count<<'\n'; break;}
            q.push(k*10);
            q.push(k*10+9);
            count += 2;
        }
	}

   return 0;
}