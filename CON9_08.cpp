// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toánduyệt theo chiều rộng bắt đầu tại đỉnh u∈V (BFS(u)=?)
/*1
6 9 1
1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6*/
#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> danhsachke, int u){
    vector<bool> visited(danhsachke.size(), false);
    queue<int> temp;
    visited[u] = true;
    temp.push(u);
    while(!temp.empty()){
        int x = temp.front();
        temp.pop();
        cout << x << " ";
        for (int i : danhsachke[x]){
            if (!visited[i]){
                visited[i] = true;
                temp.push(i);
            }
        }
    }
}



int main(){
    int t; cin >> t;
    while(t--){
        int V, E, u; cin >> V >> E >> u;
        vector<vector<int>> danhsachke(V + 1);
        for (int i = 1; i <= E; i++){
            int a, b; cin >> a >> b;
            danhsachke[a].push_back(b);
            danhsachke[b].push_back(a);                        // đồ thị có hướng thì bỏ dòng này
        }
        BFS(danhsachke, u);
        cout<<endl;
    }
}