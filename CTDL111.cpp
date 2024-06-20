// Cho trước một số nguyên n , nhiệm vụ là in ra số quân tượng lớn nhất có thể đặt trên một bàn cờ nxn sao cho không có hai quân tượng tấn công lẫn nhau.
#include <bits/stdc++.h>
using namespace std;


/* n nhỏ
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if (n < 1){
            cout<<0<<endl;
        }else if(n == 1){
            cout<<1<<endl;
        }else{
            int ans = 2 *(n - 1);
            cout<<ans<<endl;
        }
    }
}
*/
// n rất lớn
string subtract(string str1, string str2)
{
	string res = "";
	int n1 = str1.length();
	int n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	for (int i = 0; i < n2; i++) {

		int subst = ((str1[i] - '0')
					- (str2[i] - '0') - carry);

		if (subst < 0) {
			subst = subst + 10;
			carry = 1;
		}
		else
			carry = 0;
		res.push_back(subst + '0');
	}

	for (int i = n2; i < n1; i++) {
		int subst = ((str1[i] - '0') - carry);

		if (subst < 0) {
			subst = subst + 10;
			carry = 1;
		}
		else
			carry = 0;

		res.push_back(subst + '0');
	}

	reverse(res.begin(), res.end());

	return res;
}

string NumberOfBishops(string a)
{
	if (a == "1")
		return a;
	else {

		a = subtract(a, "1");

		reverse(a.begin(), a.end());

		int carry = 0;

		for (int i = 0; i < a.size(); i++) {
			int tmp = a[i] - '0';
			tmp *= 2;
			tmp += carry;
			a[i] = '0' + (tmp % 10);
			carry = tmp / 10;
		}
		if (carry > 0)
			a += ('0' + carry);

		reverse(a.begin(), a.end());

		return a;
	}
}

int main()
{
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        string a = to_string(n);
        cout << NumberOfBishops(a) << endl;
    }
}
