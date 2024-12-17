// https://leetcode.com/discuss/interview-question/4846899/Microsoft-Codility-OA-(SWE-II)
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

vector<vector<int>> dp;

int get_maximal_val(vector<vector<int>> &grid, int i, int j) {
    int n = grid.size(), m = grid[0].size();
    if(i<0 || j<0 || i>=n || j>=m) {
        return INT_MAX;
    }

    if(i == n-1 && j == m-1) {
        return grid[i][j];
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int val = grid[i][j];

    return dp[i][j] = max(val, min(get_maximal_val(grid, i, j+1), get_maximal_val(grid, i+1, j)));

}


int solve(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();

    dp.resize(n, vector<int>(m, -1));
    return get_maximal_val(grid, 0, 0);

}


int main() {
    vector<vector<int>> input = {
        {1, 2, 1, 1, 1, 4}, {1, 1, 1, 3, 1, 1, 1}
    };

    auto res = solve(input);
    cout<<res<<endl;
    // output here

}