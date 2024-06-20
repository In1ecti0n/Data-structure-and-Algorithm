// Cho đơn đồ thị G= (V, E) vô hướng liên thông được mô tả bởi danh sách cạnh. Hãy inra danh sách kề tương ứng của G
/*
1               
6 9 
1 2
1 3
2 3
2 5
3 4
3 5
4 5
4 6
5 6

D1: 2 3
D2: 1 3 5
D3: 1 2 4 5
D4: 3 5 6
D5: 2 3 4 6
D6: 4 5
*/
#include <bits/stdc++.h>
using namespace std;
// https://viblo.asia/p/bieu-dien-do-thi-tren-may-tinh-XL6lABrD5ek#_ii-danh-sach-canh-edge-list-1
void check(vector<pair<int, int>> temp1, vector<int> temp2[], int V){   
    for (int i = 0; i < temp1.size(); i++){   // duyệt từng cặp 
        int a = temp1[i].first;               // giá trị đầu của cặp
        int b = temp1[i].second;              // giá trị sau của cặp
        temp2[a].push_back(b);                // tại index của đỉnh a thì push đỉnh kề b 
        temp2[b].push_back(a);                // tại index của đỉnh b thì push đỉnh kề a. Néu vector có hướng thì ko có 1 trong 2 dòng trên
    }
    for (int i = 1; i <= V; i++){             // vòng lặp in số đỉnh danh sách kề
        cout<<'D'<<i<<':'<<" ";               // đỉnh i
        for (int j = 0; j <temp2[i].size(); j++){     // duyệt và in các đỉnh kề với i trong vector có index i thuộc vector temp2.
            cout<<temp2[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int t; cin >> t;
    while(t--){
        int V, E;                            // số đỉnh V, số cạnh E
        cin >> V >> E;
        vector<pair<int, int>> danhsachcanh; // chèn (V, E) theo từng cặp
        vector<int> danhsachke[V+1];         // chèn các vector con trong vector ({1,2},{2,3,4},...) tương ứng với các đỉnh liền kề với đỉnh index vd index 0 thì liên kết với 1, 2
        for (int i = 1; i <= E; i++){
            int u, v;                        // đỉnh u và đỉnh kề với u là v
            cin >> u >> v;
            danhsachcanh.push_back({u, v});
        }
        check(danhsachcanh, danhsachke, V);
    }
}