#include <bits/stdc++.h>
using namespace std;

void check(string s1, string s2){
    deque <char> temp1, temp2;
    stack <char> ans;
    temp1.push_back(s1[0]);
    temp2.push_back(s2[0]);
    for (char c : s1){
        if (c == temp1.back()){
            continue;
        }else{
            temp1.push_back(c);
        }
    }
    for (char c : s2){
        if (c == temp2.back()){
            continue;
        }else{
            temp2.push_back(c);
        }
    }
    while(!temp1.empty() && !temp2.empty()){
        if (temp1.front() == temp2.front()){
            ans.push(temp1.front());
        }
        temp1.pop_front();
        temp2.pop_front();
    }
    cout<<ans.size();
}


int main(){
    int t; cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        check(s1, s2);
        cout<<endl;
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

void check(string s1, string s2){
    deque <char> temp1, temp2;
    stack <char> ans;
    temp1.push_back(s1[0]);
    temp2.push_back(s2[0]);
    for (char c : s1){
        if (c == temp1.back()){
            continue;
        }else{
            temp1.push_back(c);
        }
    }
    for (char c : s2){
        if (c == temp2.back()){
            continue;
        }else{
            temp2.push_back(c);
        }
    }
    s1.clear();
    s2.clear();
    while(!temp1.empty()){
        s1 += temp1.front();
        temp1.pop_front();
    }
    while(!temp2.empty()){
        s2 += temp2.front();
        temp2.pop_front();
    }
    for (int i = 0; i < s1.size(); i++){
        for (int j = 0; j < s2.size(); j++){
            if (s2[j] == s1[i]){
                ans.push(s2[j]);
            }
        }
    }
    cout<<ans.size();
}


int main(){
    int t; cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        check(s1, s2);
        cout<<endl;
    }
}
*/