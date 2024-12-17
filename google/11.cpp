// https://leetcode.com/discuss/interview-question/5304104/Google-or-Interview-Question
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
/*
brute force:
start with all pair of the bombs, remove the pair and the bombs in radii and then backtrack.

maximum radius we want right - 

consider radius r1 at i1

bomb with 0 value is of no value - 

for maximum radius, we want maximum overlapping, 


So this question was of range dp
*/

int calc_max_radii(vector<int> &bombs, int start, int end, vector<vector<int>> & dp) { // implement it in bottoms up dp
    if(end <= start) {
        return 0;
    }

    if(dp[start][end] != -1) {
        return dp[start][end];
    }

    int mx = 0;

    for(int i = start; i<=end; i++) {
        if(bombs[i] == 0) {
            continue;
        }
        for(int j = i+1; j<=end; j++) {
            if(bombs[j] == 0) {
                continue;
            }

            int ri = bombs[i], rj = bombs[j];

            if(i + ri >= j || j - rj <= i) {
                continue;
            }

            mx = max(mx, calc_max_radii(bombs, start, i - ri, dp) + calc_max_radii(bombs, j + rj, end, dp) + ri+rj);
        }
    }

    return dp[start][end] = mx;
}


int solve(vector<int> bombs) {

    int n = bombs.size();
    vector<vector<int>> max_radii(n, vector<int>(n, -1));

    return calc_max_radii(bombs, 0, n-1, max_radii);

}


int main() {
    vector<int> input = {1, 1, 1, 1};

    auto res = solve(input);
    cout<<res<<endl;
    // output here

}