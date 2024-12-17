// https://leetcode.com/discuss/interview-question/4766971/Microsoft-OA-or-3-Questions-or-75-Minutes
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

#define u_map unordered_map
using namespace std;


vector<char> get_vector(string s) {
    vector<char> res;

    for(char c: s) {
        if(c == ',') {
            continue;
        }
        res.push_back(c);
    }

    return res;

}

string solve(vector<char> &a, vector<string> &b, vector<int> &c) {
    u_map<char, vector<char>> mp;

    u_map<char, int> risk;

    for(int i = 0; i<a.size(); i++) {
        mp[a[i]] = get_vector(b[i]);
        risk[a[i]] = c[i];
    }


    u_map<char, int> dist;

    dist[a[0]] = risk[c[0]];

    set<pair<int, char>> q;
    q.insert({dist[a[0]], a[0]});

    u_map<char, char> par;

    while(!q.empty()) {
        auto [_, c] = *q.begin();
        q.erase(q.begin());

        for(char to: mp[c]) {
            if(dist.find(to) == dist.end()) {
                dist[to] = INT_MAX;
            }

            if(dist[to] > dist[c] + 1 + risk[to]) {
                q.erase({dist[to], to});
                dist[to] = dist[c] + 1 + risk[to];
                par[to] = c;
                q.insert({dist[to], to});
            }
        }
    }

    if(dist.find('E') == dist.end() || dist['E'] == INT_MAX) {
        return "";
    }

    string res = "";

    res.push_back('E');
    res.push_back(',');

    char last_char = 'E';

    while(par.find(last_char) != par.end()) {

        res.push_back(par[last_char]);
        res.push_back(',');
        last_char = par[last_char];
    }
    res.pop_back();

    reverse(res.begin(), res.end());

    return res;



}


int main() {
    vector<char> a = {'S', 'A', 'B', 'C'};
    vector<string> b = {"A,B", "C", "E", ""};
    vector<int> c = {0, 3, 4, 6};

    auto res = solve(a, b, c);

    cout<<res<<endl;
    
    // output here

}