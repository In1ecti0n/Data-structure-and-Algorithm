// đếm số liên thông theo DFS 
#include <bits/stdc++.h>
using namespace std;

// có thể dùng BFS cũng ra, nếu chỉ yêu câù đếm thành phần liên thông
vector<bool> visited;
void DFS(int temp, vector<vector<int>> danhsachke, int count){
    visited[temp] = true;
    for (int i : danhsachke[temp]){
        if (!visited[i]){
            DFS(i, danhsachke, count);
        }
    }
}

int countDFS(vector<vector<int>> danhsachke, int count){
    for (int i = 1; i < danhsachke.size(); i++){
        if(!visited[i]){
            count++;
            DFS(i, danhsachke, count);
        }
    }
    return count;
}

int main(){
    int t; cin >> t;
    while(t--){
        int V, E; cin >> V >> E;
        visited.resize(V + 1);
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> danhsachke(V + 1);
        for (int i = 1; i <= E; i++){
            int a; int b; cin >> a >> b;
            danhsachke[a].push_back(b);
            danhsachke[b].push_back(a);
        }
        cout<<countDFS(danhsachke, 0)<<endl;
    }
}


/*Đỉnh 1: 2 3
Đỉnh 2: 1 3
Đỉnh 3: 1 2 4 5
Đỉnh 4: 3 5
Đỉnh 5: 3 4*/