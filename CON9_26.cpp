// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Sử dụng Disjoin Set,hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?
//  Dòng đầu tiên đưavào hai số |V|, |E| tương ứng với số đỉnh, số cạnh của đồ thị; Dòng tiếp theo đưa vàocác bộ đôi u∈V, v∈V tương ứng với một cạnh của đồ thị.
/*
1
6 9 // 6 đỉnh 9 cạnh
1 2
1 3 
2 3 
2 5 
3 4 
3 5 
4 5 
4 6 
5 6

YES
*/
// Dùng DFS, BFS cũng được, điều kiện tồn tại chu trình là "nếu gặp một đỉnh đã được thăm và không phải là cha của đỉnh hiện tại, có nghĩa là tồn tại chu trình"
// VD DFS
#include <bits/stdc++.h>
using namespace std;


vector<bool> visited;
vector<int> parent;
bool Chutrinh(vector<vector<int>> danhsachke, int u){
    visited[u] = true;
    for (int i : danhsachke[u]){
        if(!visited[i]){
            parent[i] = u;
            Chutrinh(danhsachke, i);
        }else if(parent[u] != i || parent[u] == -1){               // nếu đồ thị có hướng thì chỉ cần visited[i] == true là return true luôn.
            return true;
        }
    }
    return false;
}


int main(){
    int t; cin >> t;
    while(t--){
        int V, E; cin >> V >> E;
        visited.resize(V + 1);
        fill(visited.begin(), visited.end(), false);
        parent.resize(V + 1);
        fill(parent.begin(), parent.end(), -1);
        vector<vector<int>> danhsachke(V + 1);
        for (int i = 1; i <= E; i++){
            int a, b; cin >> a >> b;
            danhsachke[a].push_back(b);
            danhsachke[b].push_back(a);
        }
        bool check = false;
        for (int i = 1; i <= V; i++){             // đảm bảo duyệt bắt đầu từ mọi đỉnh, nếu chỉ đi thì 1 đỉnh thì có khả năng ko phát hiện ra chu trình đang có
            if (Chutrinh(danhsachke, i)){
                check = true;
                break;
            }
        }
        if (check){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
/*Copilot
// Khai báo thư viện
#include <iostream>
#include <vector>

// Sử dụng không gian tên std
using namespace std;

// Hàm tìm kiếm
int Find(int parent[], int i) {
    if (parent[i] == -1)
        return i; // Nếu đỉnh i là gốc, trả về chính nó
    return Find(parent, parent[i]); // Đệ quy tìm gốc của i
}

// Hàm gộp hai tập hợp lại với nhau
void Union(int parent[], int x, int y) {
    int xset = Find(parent, x);
    int yset = Find(parent, y);
    if(xset != yset){
       parent[xset] = yset; // Gán gốc của xset là yset để gộp hai tập hợp
    }
}

// Hàm kiểm tra chu trình
bool isCycle(vector<pair<int, int>> &edges, int V) {
    // Khởi tạo mảng parent
    int *parent = new int[V];
    fill_n(parent, V, -1); // Đặt tất cả các đỉnh là gốc của chính chúng

    // Duyệt qua từng cạnh của đồ thị
    for (auto &edge : edges) {
        int x = Find(parent, edge.first);
        int y = Find(parent, edge.second);

        if (x == y)
            return true; // Nếu x và y cùng gốc, tồn tại chu trình

        Union(parent, x, y); // Gộp hai tập hợp nếu không cùng gốc
    }
    return false; // Không tồn tại chu trình
}

int main() {
    // Số lượng đỉnh và cạnh
    int V = 3, E = 3;
    vector<pair<int, int>> edges;

    // Thêm cạnh vào danh sách cạnh
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({0, 2});

    // Kiểm tra chu trình
    if (isCycle(edges, V))
        cout << "Graph contains cycle";
    else
        cout << "Graph does not contain cycle";

    return 0;
}

*/



