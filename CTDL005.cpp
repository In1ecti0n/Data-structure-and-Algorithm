#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    int n;
    while (t--){
        vector<int> temp;
        cin >> n;
        for (int i = 1; i <= n; i++){
            temp.push_back(i);
        }
        do {
            for (int i = 0; i < temp.size(); i++){
                cout<<temp[i]; 
            }
            cout<<" ";
        }while (next_permutation(temp.begin(), temp.end()));
        cout<<endl;
    }
}


/*  Hàm next_permutation được định nghĩa trong gnu gcc lib
template<typename It>
bool next_permutation(It begin, It end)
{
        if (begin == end)
                return false;

        It i = begin;
        ++i;
        if (i == end)
                return false;

        i = end;
        --i;

        while (true)
        {
                It j = i;
                --i;

                if (*i < *j)
                {
                        It k = end;

                        while (!(*i < *--k)) // pass
                        iter_swap(i, k);
                        reverse(j, end);
                        return true;
                }

                if (i == begin)
                {
                        reverse(begin, end);
                        return false;
                }
        }
}
*/