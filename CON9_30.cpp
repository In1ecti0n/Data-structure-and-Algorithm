/* Cho đồ thị có hướng liên thông yếu G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãykiểm tra xem đồ thị có chu trình Euler hay không?
2
6 10
1 2 2 4 2 5 3 1 3 2 4 3 4 5 5 3 5 6 6 4
3 3
1 2 2 3 1 3


1
0
*/

#include <bits/stdc++.h>
using namespace std;

/*Hệ quả: Một đồ thị có hướng liên thông yếu G=(V,E) có chu trình Euler thì mọi đỉnh của nó có bán bậc ra bằng bán bậc vào deg+(v) = deg−(v),∀v∈V*. Ngược lại, nếu 𝐺 liên thông yếu và mọi đỉnh của nó có bán bậc ra bằng bán bậc vào, thì có chu trình Euler (đồng nghĩa với việc là đồ thị liên thông mạnh)*/
bool euler(vector<pair<int, int>> danhsachcanh, int V){
    vector<int> bacra(V + 1);
    vector<int> bacvao(V + 1);
    for (int i = 0; i < danhsachcanh.size(); i++){
        bacra[danhsachcanh[i].first]++;
        bacvao[danhsachcanh[i].second]++;
    }
    for (int i = 1; i <= V; i++){
        if(bacra[i] != bacvao[i]){
            return false;
        }
    }
    return true;

}

int main(){
    int t; cin >> t;
    while(t--){
        int V, E; cin >> V >> E;
        vector<pair<int, int>> danhsachcanh;    // nếu khởi tạo kích thước (E + 1) thì đổi push_back bằng toán tử gán '='
        for (int i = 1; i <= E; i++){
            int a, b; cin >> a >> b;
            danhsachcanh.push_back({a, b});
        }
        if (euler(danhsachcanh, V)){
            cout << 1 <<endl;
        }else{
            cout<< 0 << endl;
        }
    }
}