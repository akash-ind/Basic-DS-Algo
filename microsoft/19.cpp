// https://leetcode.com/discuss/interview-experience/5040436/Microsoft-or-L62-or-Brain-cooked

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

bool matched(string &s, int index, const string &m) {
    for(int i = 0; i<m.size(); i++) {
        if(i+index >= s.size()) {
            return false;
        }

        if(s[i+index] != m[i]) {
            return false;
        }
    }
    return true;
}


int solve(string &s) {

    unordered_map<string, int> mp = {
        {"minus", -1}, // handle this
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };


    int n = s.size();
    vector<int> res;
    int temp = 0;
    bool is_minus = false;
    for(int i = 0; i<n; i++) {
        bool is_matched = false;
        for(auto p: mp) {
            if(matched(s, i, p.first)) {
                // cout<<p.second<<" "<<temp<<endl;
                if(p.second == -1) {
                    is_minus = true;
                }
                else {
                    if(temp) {
                        temp *=10;
                        temp += p.second;
                    }
                    else {
                        temp = p.second;
                    }
                }
                is_matched = true;
                i += p.first.size() - 1;
                break;
            }
        }

        if(!is_matched && temp) {
            if(is_minus) { // assuming valid no after minus
                temp *= -1;
            }
            res.push_back(temp);
            temp = 0;
            is_minus = false;
        }
        if(!is_matched) {
            is_minus = false;
        }
    }
    if(temp) {
        if(is_minus) {
            temp *= -1;
        }
        res.push_back(temp);
    }

    int sum = 0;

    for(int num: res) {
        // cout<<num<<" "
        sum += num;
    }

    return sum;

}


int main() {
    string input = "rwffonewominusfnwthreeonefourfrnwnminusonesix";
    // string input = "minusonesix";

    auto res = solve(input);
    cout<<res<<endl;
    
    // output here

}
