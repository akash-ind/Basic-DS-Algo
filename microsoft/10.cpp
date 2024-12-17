// https://leetcode.com/discuss/interview-question/4884549/Microsoft-OA
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

bool is_valid(int i, int j, int n, int m) {
    return i>=0 && j>=0 && i<n && j<m;
}

int solve(vector<string> & grid) {
    int n = grid.size(), m = grid[0].size();

    vector<vector<set<int>>> vis(n, vector<set<int>>(m));
    int ans = 0;

    unordered_map<int, pair<int, int>> mp = {
        {0, {0, 1}}, {1, {1, 0}}, {2, {0, -1}}, {3, {-1, 0}}
    };

    int dir = 0;
    int r = 0, c = 0;
    while(true) {
        // cout<<r<<" "<<c<<endl;
        if(vis[r][c].find(dir) != vis[r][c].end()) {
            break;
        }
        // cout<<r<<" "<<c<<endl;
        vis[r][c].insert(dir);
        int temp_dir = dir;
        while(true) {
            auto [dr, dc] = mp[temp_dir];
            int x = r+dr, y = c+dc;
            // cout<<x<<" "<<y<<endl;
            if(is_valid(x, y, n, m) && grid[x][y] == '.') {
                r = x, c = y;
                dir = temp_dir;
                // cout<<"here"<<endl;
                break;
            }
            else {
                temp_dir += 1;
                temp_dir %= 4;
                if(temp_dir == dir) {
                    break;
                }
            }
        }
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            ans += (!vis[i][j].empty());
        }
    }

    return ans;


}


int main() {
    vector<string> input = {"...Χ..", "....XX", "....."};

    auto res = solve(input);
    
    cout<<res<<endl;
    // output here

}