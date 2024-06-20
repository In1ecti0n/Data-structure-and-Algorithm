//Ta biết rằng một số là số may mắn nếu biểu diễn thập phân của nó chỉ chứa các chữ số may mắn là 4 và 7. Ví dụ, các số 47, 744, 4 là số may mắn và 5, 17, 467 không phải. Hoàng muốn tìm số may mắn bé nhất có tổng các chữ số bằng n.
#include <bits/stdc++.h>
using namespace std;
// n = 4x + 7y;
void check(int sum){
	int x = 0, y = 0;
	while (sum > 0){
		if (sum % 7 == 0){
			y++;
			sum -= 7;           // ko dùng n = n chia cho 7 được vì nếu chia n sẽ về 1, thành 1+4x+7y (sai do số n chứa 4,7 và 1)
		}
		else if (sum % 4 == 0){
			x++;
			sum -= 4;
		}else{
			x++;
			sum -= 4;
		}
	}
	if (sum < 0){
		cout<<-1;
		return;
	}
	for (int i=0; i<x; i++){
        cout<<4;
    }
	for (int i=0; i<y; i++){
        cout<<7;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        check(n);
        cout<<endl;
    }
}


/*
int main(){
    int t;
    cin >>t;
    while(t--){
        int n, ok=0;
        cin >>n;
        for(int i = 0; i < n/4; ++i){
            if((n - i*4)%7 == 0) {
                ok = 1;
                for(int j = 0; j < i; ++j) cout <<4;
                for(int j = 0; j < (n-i*4)/7; ++j) cout <<7;
                break;
            }
        }
        if(!ok) cout <<-1;
        cout <<'\n';
    }
}
*/