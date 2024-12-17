// https://leetcode.com/discuss/interview-question/5021797/Microsoft-OA

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



int solve(string &s) {

    unordered_map<char, int> mp;
    int res = 1, n = s.size();

    for(int i = 0, j = 0; j<n; j++) {
        if(mp[s[j]]) {
            res++;
        }
        while(mp[s[j]]) {
            mp[s[i]]--;
            i++;
        }

        mp[s[j]]++;

    }

    return res;

}


int main() {
    string input = "cycle";

    auto res = solve(input);

    cout<<res<<endl;
    
    // output here

}