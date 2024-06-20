// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy tìm số thành phầnliên thông của đồ thị bằng thuật toán BFS.
/*
1
6 6
1 2 1 3 2 3 3 4 3 5 4 5

2 
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
int BFS(vector<vector<int>> danhsachke, int count){
	for (int i = 1; i < danhsachke.size(); i++){          // từ đỉnh 1 đến đỉnh size() - 1
		if (!visited[i]){
			count++;
			visited[i] = true;
			stack<int> temp;
			temp.push(i);
			while(!temp.empty()){
				int x = temp.top();
				temp.pop();
				for (int j : danhsachke[x]){
					if (!visited[j]){
						visited[j] = true; 
						temp.push(j);
					}
				}

			}
		}
	}
	return count;
}



int main(){
	int t; cin >> t;
	while(t--){
		int v, e; cin >> v >> e;
		vector<vector<int>> danhsachke(v + 1);      //Tính cả đỉnh 0 đến đỉnh v - 1 (thực chất ko có đỉnh 0)
		visited.resize(v + 1);
		fill(visited.begin(), visited.end(), false);
		for (int i = 1; i <= e; i++){
			int a, b; cin >> a >> b;
			danhsachke[a].push_back(b);
			danhsachke[b].push_back(a);
		}
		cout<<BFS(danhsachke, 0)<<endl;
	}
}
