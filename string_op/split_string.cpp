#include<iostream>
#include<algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include<cstring>

using namespace std;

vector<string> split_string(string &s, char delim) {
    int st = 0;
    int en = 0;
    vector<string> ans;

    while((en = s.find(delim, st)) != -1) {
        ans.push_back(s.substr(st, en - st));
        st = en+1;
    }

    return ans;

}


int main() {
    string s = "hello, akash, krish, lifnfj, ffnfn";

    auto val = split_string(s, ',');
    for(string s: val) {
        cout<<s<<endl;
    }
    return 0;

}