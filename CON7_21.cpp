/*
Cho mảng A[] gồm n phần tử. Hãy đưa ra các phần tử nhỏ hơn tiếp theo của phần tử lớn hơn

đầu tiên phần tử hiện tại. Nếu phần tử hiện tại không có phần tử lớn hơn tiếp theo ta xem là -1.

Nếu phần tử không có phần tử nhỏ hơn tiếp theo ta cũng xem là -1. Ví dụ với mảng A[] = {5, 1,

9, 2, 5, 1, 7} ta có kết quả là ans = {2, 2, -1, 1, -1, -1, -1} vì:

Next Greater Right Smaller

5 -> 9            9 -> 2

1 -> 9            9 -> 2

9 -> -1           -1 -> -1

2 -> 5             5 -> 1

5 -> 7             7 -> -1

1 -> 7             7 -> -1

7 -> -1            7 -> -1
*/
#include <bits/stdc++.h>
using namespace std;

/*void test(string s){
    stack<string> ans;
    vector<int> max;
    vector<int> min;
    bool check = false;
    for(int i = 0; i < s.size() - 1; i++){
        for (int j = i + 1; j < s.size(); j++){
            if (s[j] >= s[i]){
                max.push_back(j);
                check = true;
                break;
            }
        }
        if (!check){
            max.push_back(-1);
        }
    }
    for (int i = 0; i < max.size(); i++){
        if (max[i] == -1){
            min.push_back(-1);
            continue;
        }
        if (i == max.size() - 1){
            min.push_back(-1);
            break;
        }
        for (int j = max[i]; j < s.size(); j++){
            if (s[j] < s[i]){
                min.push_back(s[j] - '0');
                check = true;
                break;
            }
        }
        if (!check){
            max.push_back(-1);
        }
    }
    for (int i : min){
        cout<<i;
    }
}
*/

void test(vector<int>s){
    stack<int> temp;
    vector<int> max;
    vector<int> min;
    temp.push(s[0]);
    bool check = false;
    for (int i = 0; i < s.size();i++){
        check = false;
        if (i == s.size() - 1){
            max.push_back(-1);
            break;
        }
        for (int j = i+1; j < s.size(); j ++ ){
            if (s[j] > s[i]){
                max.push_back(s[j]);
                check = true;
                break;
            }
        }
        if (!check){
            max.push_back(-1);
        }
    }
    for (int i = 0; i < max.size(); i++){
        if (max[i] == -1){
            min.push_back(-1);
            continue;
        }
        for (int j = max[i]; j < s.size(); j++){
            if (s[j + 1] < s[j]){
                min.push_back(s[j+1]);
                break;
            }
        }
    }
    for (int i : min){
        cout<<i<<" ";
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> input;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            input.push_back(a);
        }
        test(input);
        cout<<endl;
    }
}


/*
#include <bits/stdc++.h>
using namespace std;

void test(vector<int>s){
    stack<int> temp;
    vector<int> max;
    vector<int> min;
    temp.push(s[0]);
    for (int i = 1; i < s.size(); i++){
        if (temp.empty()){
            temp.push(s[i]);
            continue;
        }
        while(!temp.empty() && temp.top() < s[i]){
            max.push_back(i);
            temp.pop();
        }
        temp.push(s[i]);   
    }
    while(!temp.empty()){
        max.push_back(-1);
        temp.pop();
    }
    for (int i = 0; i < max.size(); i++){
        if (max[i] == -1){
            min.push_back(-1);
            continue;
        }
        for (int j = max[i]; j < s.size(); j++){
            if (s[j + 1] < s[j]){
                min.push_back(s[j+1]);
                break;
            }
        }
    }
    for (int i : min){
        cout<<i<<" ";
    }
}


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> input;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            input.push_back(a);
        }
        test(input);
        cout<<endl;
    }
}
*/