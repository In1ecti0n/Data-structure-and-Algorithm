// Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết chương trìnhthực hiện chuyển đổi biểu diễn đồ thị dưới dạng danh sách kề.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int V, E; cin >> V >> E;
        vector<pair<int, int>> danhsachcanh;   
        for (int i = 1; i <= E; i++){              // hoặc chuyển đổi trực tiếp sang danh sách kề rồi in ra vector<vector<int>> danhsachke
            int a, b; cin >> a >> b;
            danhsachcanh.push_back({a, b});
        }
        for (int i = 1; i <= V; i++){
            cout<<i<<':'<<" ";
            for (int j = 0; j < danhsachcanh.size(); j++){
                if (danhsachcanh[j].first == i){
                    cout<<danhsachcanh[j].second<<" ";
                }
            }
            cout<<endl;
        }
    }
}


