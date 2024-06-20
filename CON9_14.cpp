// Cho đồ thị vô hướng có N đỉnh và M cạnh. Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2đỉnh x và y có tồn tại đường đi tới nhau hay không?
#include <bits/stdc++.h>
using namespace std;
/*
vector<bool> visited;
bool connect(vector<pair<int,int>> danhsachcanh, int u, int v){
    for (int i = 0; i < danhsachcanh.size(); i++){
        if(u == danhsachcanh[i].first && v == danhsachcanh[i].second){
            return true;
        }
        if (u == danhsachcanh[i].first && !visited[u]){
            visited[u] = true;
            return connect(danhsachcanh, danhsachcanh[i].second, v);             //xem lại ví dụ xét từ đỉnh 4 đến 5 danh sách cạnh có {4 10} {4 9} thì nó xét mỗi 4 10(đỉnh 4 đến đỉnh 10 và ko đến được đỉnh 5) ko xét 4 9(đỉnh 4 đến đỉnh 9 đến đỉnh 5)
        }
        if (u == danhsachcanh[i].second && !visited[u]){
            visited[u] = true;
            return connect(danhsachcanh, danhsachcanh[i].first, v);

        }
    }
    fill(visited.begin(), visited.end(), false);
    return false;
}


int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;    // n đỉnh, m cạnh
        visited.resize(n + 1);
        vector<pair<int, int>> danhsachcanh;
        for (int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            danhsachcanh.push_back({x, y});   // dinh x, y;
        }  
        int Q; cin >> Q;
        for (int i = 0; i < Q; i++){
            int u, v; cin >> u >> v;
            if(connect(danhsachcanh, u, v)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}
*/
/*
// cách này đúng
vector<vector<int>> adj; // Danh sách kề
vector<bool> visited;

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

bool isConnected(int u, int v) {
    fill(visited.begin(), visited.end(), false);
    DFS(u);
    return visited[v];
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        adj.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x); // Vì đồ thị vô hướng
        }
        int Q; cin >> Q;
        while (Q--) {
            int u, v; cin >> u >> v;
            cout << (isConnected(u, v) ? "YES" : "NO") << endl;
        }
    }
}

*/
// đã đúng
vector<bool> visited;
bool check(vector<vector<int>> danhsachke, int u, int v){
    if (v == u) return true;
    visited[u] = true;
    for (int i : danhsachke[u]){
        if (!visited[i]){
            if(check(danhsachke, i, v)){
                return true;
            }

        }
    }
    return false;
}


int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        visited.resize(n + 1, false);
        vector<vector<int>> danhsachke(n + 1);
        for (int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            danhsachke[u].push_back(v);
            danhsachke[v].push_back(u);
        }
        int Q; cin >> Q;
        while(Q--){
            fill(visited.begin(), visited.end(), false);
            int x, y; cin >> x >> y;
            if (check(danhsachke, x, y)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}

