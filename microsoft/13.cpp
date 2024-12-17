// https://leetcode.com/discuss/interview-question/5115457/Reconstruct-a-string

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

int get_dist(pair<int, int> a, pair<int, int> b) {
    auto [r, c] = a;
    auto [x, y] = b;

    if(r == -1 || x == -1) {
        return 0;
    }

    return abs(r - x) + abs(y - c);
}



int solve(vector<string> &grid, string &s) {
    if(s.size() == 0) {
        return 0;
    }
    int n = grid.size(), m = 0;
    if(n) {
        m = grid[0].size();
    }
    else {
        return -1;
    }


    unordered_map<char, vector<pair<int, int>>> mp;

    for(int i = 0; i< n; i++) {
        for(int j = 0; j<m; j++) {
            if(grid[i][j] != '.') {
                mp[grid[i][j]].push_back({i, j});
            }
        }
    }

    int k = s.size();
    
    vector<vector<int>> min_moves(k+1, vector<int>(2, 0));
    vector<pair<int, int>> prev_pos(2, {-1, -1});

    for(int i = 1; i<=k; i++) {
        if(mp[s[i-1]].empty()) {
            return -1;
        }
        vector<pair<int, int>> temp;
        int index = 0;
        for(auto p: mp[s[i-1]]) {

            int dist1 = get_dist(p, prev_pos[0]), dist2 = get_dist(p, prev_pos[1]);
            if(dist1 < dist2) {
                min_moves[i][index] = min_moves[i-1][0] + dist1;
            }
            else {
                min_moves[i][index] = min_moves[i-1][1] + dist2;
            }
            index++;
            temp.push_back(p);
        }

        if(mp[s[i-1]].size() == 1) {
            min_moves[i][1] = min_moves[i][0];
            temp.push_back(temp.back());
        }

        prev_pos = temp;
    }

    return min(min_moves[n][0], min_moves[n][1]);


}


int main() {
    vector<string> input = {"K....","S...L","....R","LX...","XM..S"};
    string s = "KLLRMS";
    auto res = solve(input, s);

    cout<<res<<endl;
    
    // output here

}