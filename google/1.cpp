// https://leetcode.com/discuss/interview-question/4511536/Google-coding-round-question

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


vector<vector<int>> rotate(vector<vector<int>> &grid) {
    int n= grid.size(), m = grid[0].size();
    vector<vector<int>> res(m, vector<int>(n));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            res[j][i] = grid[i][j];
        }
    }
    return res;
}

int solve(vector<vector<int>> &grid) {
    grid = rotate(grid);
    // cout<<"here"<<endl;

    int n = grid.size(), m = grid[0].size();
    for(int i = 0; i<n; i++) {
        sort(grid[i].begin(), grid[i].end());
    }

    int min_cost = INT_MAX;
    for(int j = 0; j<m; j++) {
        int cur_val = grid[0][j];
        int min_val = cur_val, max_val = cur_val;
        for(int i = 1; i<n; i++) {
            int mx_ind = upper_bound(grid[i].begin(), grid[i].end(), max_val) - grid[i].begin();
            if(mx_ind != 0) {
                mx_ind --;
            }

            int mn_ind = lower_bound(grid[i].begin(), grid[i].end(), min_val) - grid[i].begin(); 

            if(mn_ind == n) {
                mn_ind --;
            }

            int mx_res = max(max_val, grid[i][mx_ind]) - min(min_val, grid[i][mx_ind]);

            int mn_res = max(max_val, grid[i][mn_ind]) - min(min_val, grid[i][mn_ind]);

            if(mx_res < mn_res) {
                min_val = min(min_val, grid[i][mx_ind]);
                max_val = max(max_val, grid[i][mx_ind]);
            }
            else {
                min_val = min(min_val, grid[i][mn_ind]);
                max_val = max(max_val, grid[i][mn_ind]);
            }
        }
        min_cost = min(min_cost, max_val - min_val);
    }
    // cout<<min_cost<<endl;
    return min_cost;

}


int main() {
    vector<vector<int>> input = {
        {1, 5, 5},
        {1, 2, 5},
        {4, 1, 5}
    };

    auto res = solve(input);

    cout<<res<<endl;
    // output here

    return 0;

}