// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường đi từđỉnh s∈V đến đỉnh t∈V trên đồ thị bằng thuật toán DFS.
#include <bits/stdc++.h>
using namespace std;

bool none = false;
vector<bool> visited;
string ans;
void test(vector<vector<int>> danhsachke, int s, int t, string temp){
    visited[s] = true;
    for (int i : danhsachke[s]){
        if (!visited[i]){
            if (i == t){
                none = true;
                ans = temp + " " + to_string(i);
            }
            test(danhsachke, i, t, temp + " " + to_string(i));
        }
    }   
}


int main(){
    int t; cin >> t;
    while(t--){
        int V, E, s, t;
        cin >> V >> E >> s >> t;
        visited.resize(V + 1);
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> danhsachke(V + 1);
        
        while(E--){
            int u, v; cin >> u >> v;
            danhsachke[u].push_back(v);
            danhsachke[v].push_back(u);
        }
        test(danhsachke, s, t, to_string(s));
        if(!none){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
}

/*#include<iostream>
#include<string.h>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<map>
using namespace std;


vector<int> A[1001];
bool check[1001];
bool ok;


string res;
int m, n, u, v;
void DFS(int a, string temp) {
	check[a] = true;
	for (auto b : A[a]) {
		if (!check[b]) {
			if (b == v) {
				ok = true;
                res = temp;
				res = res + " " + to_string(b);
			}
            string s = temp;                     // nếu thay s, sử dụng temp = temp + " " + to_string(b) thì đúng 8/10 test ???
            s = s + " " + to_string(b);
			DFS(b, s);
		}
	}
}
int main() {
	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < 1001; i++)A[i].clear();
		memset(check, false, sizeof(check));
		ok = false;
		res = "";
		cin >> m >> n >> u >> v;
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			A[a].push_back(b);
			A[b].push_back(a);
		}
		DFS(u,to_string(u));
		if (!ok)cout << -1 << endl;
		else cout << res << endl;
	}
}*/
/*
#include <bits/stdc++.h>
using namespace std;

bool found;
vector<bool> visited;
queue<int> ans;
void test(vector<vector<int>> danhsachke, int s, int t, queue<int> temp){
    visited[s] = true;
    for (auto i : danhsachke[s]){
        if (!visited[i]){
            if (i == t){
                found = true;
                ans = temp;
                ans.push(i);
            }
            queue<int> temp1 = temp;                   // nếu ko dùng queue temp1 tạm thời mà dùng luôn temp.push(i) thì chỉ đúng 8/10 test ???
            temp1.push(i);
            test(danhsachke, i, t, temp1);
        }
    }   
    return;
}


int main(){
    int t; cin >> t;
    while(t--){
        int V, E, s, t;
        cin >> V >> E >> s >> t;
        visited.resize(V + 1);
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> danhsachke(V + 1);
        found = false;
        while(E--){
            int u, v; cin >> u >> v;
            danhsachke[u].push_back(v);
            danhsachke[v].push_back(u);
        }
        while(!ans.empty()){
            ans.pop();
        }
        queue<int> temp;         //  đường đi
        test(danhsachke, s, t, temp);
        if(!found){
            cout<<-1<<endl;
        }else{
            cout<<s<<" ";
            while(!ans.empty()){
                cout<<ans.front()<<" ";
                ans.pop();
            }
            cout<<endl;
        }
    }
}
*/