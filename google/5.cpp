// https://leetcode.com/discuss/interview-question/4380970/Google-or-Onsite-or-Count-users-per-each-session

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



void solve(vector<vector<int>> & sessions, int n) {
    unordered_map<int, int> start, end;

    for (auto & s: sessions) {
        start[s[0]]++;
        end[s[1]]++;
    }
    int cur_active_user = 0;
    for(int i = 0; i<n; i++) {
        cur_active_user += start[i];
        cout<<i<<"-> "<<cur_active_user<<endl;
        cur_active_user -= end[i];
    }


}


int main() {
    vector<vector<int>> input ={{0,3}, {1,4}};

    solve(input, 7);
    // auto res = solve(input);
    
    // output here

}