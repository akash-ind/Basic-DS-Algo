// https://leetcode.com/discuss/interview-question/4370956/Google-Interview-question

#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

int calculate_chain(unordered_map<char, char> & mp, unordered_map<char, int> &chain, char c) {

    if(!c) {
        return 0;
    }

    if(chain[c]) {
        return chain[c];
    }

    return chain[c] = 1 + calculate_chain(mp, chain, mp[c]);
}



string solve(vector<vector<string>> mat) {

    int n = mat.size();

    unordered_map<char, char> mp;

    for(int i = 0; i<n; i++) {
        string &ini = mat[i][0], &final = mat[i][1];

        for(int j = 0; j<ini.size(); j++) {
            if(ini[j] != final[j]) {
                mp[ini[j]] = final[j];
            }
        }
    }

    unordered_map<char, int> longest_chain;

    for(auto it: mp) {
        calculate_chain(mp, longest_chain, it.first);
    }
    char c = '-';
    for(auto it: longest_chain) {
        if(it.second > longest_chain[c]) {
            c = it.first;
        }
    }

    string res = "";
    res.push_back(c);

    while(mp[res.back()]) {
        res.push_back(mp[res.back()]);
    }


    return res;

}


int main() {
    vector<vector<string>> input = {
        {"abb", "abc"},
        {"xyz", "xxz"},
        {"eee", "eee"},
        {"aaaaac", "aabaag"},
        {"g", "h"}
    };

    auto res = solve(input);

    for(char c: res) {
        cout<<c<<" ";
    }

    cout<<endl;
    
    // output here

}