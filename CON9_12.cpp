// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường đi từđỉnh s∈V đến đỉnh t∈V trên đồ thị bằng thuật toán BFS
/*
1
6 9 1 6
1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6


1 2 5 6
*/
#include <bits/stdc++.h>
using namespace std;



void BFS(vector<vector<int>> danhsachke, int s, int t){
	queue<int>temp;
	vector<bool> visited(danhsachke.size(), false);
	vector<int> parent(danhsachke.size(), 0);
	visited[s] = true;
	temp.push(s);
	while(!temp.empty()){
		int x = temp.front();
		temp.pop();
		for (int i: danhsachke[x]){
			if (!visited[i]){
				visited[i] = true;
				parent[i] = x;
				temp.push(i);
			}
		}
	}
	stack<int> ans;
	for (int i = t; i != 0; i = parent[i]){
		ans.push(i);
	}
	while(!ans.empty()){
		cout<<ans.top()<<" ";
		ans.pop();
	}

}



int main(){
	int t; cin >> t;
	while(t--){
		int V, E, s, t; cin >> V >> E >> s >> t;
		vector<vector<int>> danhsachke(V + 1);
		for (int i = 1; i <= E; i++){
			int a, b; cin >> a >> b;
			danhsachke[a].push_back(b);
			danhsachke[b].push_back(a);
		}
		BFS(danhsachke, s, t);
		cout<<endl;
	}
}
