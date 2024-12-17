// binary search in 2D array

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



pair<int, int> solve(vector<vector<int>> & grid, int target) {

    int n = grid.size(), m = 0;
    if(n) {
        m = grid[0].size();
    }

    int lo = 0, hi = n - 1;

    int final_row = -1;

    while (lo <= hi) 
    {
        int mid = lo + (hi - lo)/2;

        if(grid[mid][0] <= target && grid[mid][m-1] >= target) {

            final_row = mid;
            hi = mid - 1;
            
        }
        else if(grid[mid][m-1] < target) {
            lo = mid+1;
        }
        else if(grid[mid][0] > target) { // All the conditions covered
            hi = mid - 1;
        }

    }

    if(final_row == -1) {
        return {-1, -1};
    }


    int col_lo = 0, col_hi = m-1;
    int final_col = -1;

    while (col_lo <= col_hi)
    {
        int col_mid = col_lo + (col_hi - col_lo)/2;

        if(grid[final_row][col_mid] == target) {
            final_col = col_mid;
            col_hi = col_mid - 1;
        }
        else if(grid[final_row][col_mid] > target) {
            col_hi = col_mid - 1;
        }
        else {
            col_lo = col_mid + 1;
        }
    }

    if(final_col == -1) {
        return {-1, -1};
    }

    return {final_row, final_col};

}


int main() {
    vector<vector<int>> input = {
        {1, 2, 3}, {3, 3, 3}, {3, 3, 3}
    };

    auto res = solve(input, 3);
    
    cout<<res.first<<" "<<res.second<<endl;
    // output here

}