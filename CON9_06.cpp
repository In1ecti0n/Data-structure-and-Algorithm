// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toánduyệt theo chiều sâu bắt đầu tại đỉnh u∈V (DFS(u)=?)
/*
1
6 9 5
1 2
1 3
2 3
2 4
3 4
3 5
4 5
4 6
5 6


5 3 1 2 4 6
*/
#include <bits/stdc++.h>
using namespace std;


vector<bool> visited;
void DFS(vector<vector<int>> danhsachke, int u){
    visited[u] = true;
    cout<<u<<" ";
    for (int i : danhsachke[u]){
        if(!visited[i]){
            DFS(danhsachke, i);
        }   
    }
}


int main(){
    int t; cin >> t;
    while(t--){
        int V, E, u; cin >> V >> E >> u;
        visited.resize(V + 1);
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> danhsachke(V + 1);
        for (int i = 1; i <= E; i++){
            int a, b; cin >> a >> b;
            danhsachke[a].push_back(b);
            danhsachke[b].push_back(a);
        }
        DFS(danhsachke, u);
    }
}