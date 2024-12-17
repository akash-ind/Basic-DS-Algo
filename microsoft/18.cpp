// https://leetcode.com/discuss/interview-experience/5040436/Microsoft-or-L62-or-Brain-cooked - 2

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



void solve(vector<vector<int>> &grid) {

    int n = grid.size(), m = 0;
    if(n) {
        m = grid[0].size();
    }

    for(int i = 0, j = 0, a = 0, b = 0; a<n && b<m && i<n && j< m; ) { // a, b represent 1 | i, j represent 0;
        if(grid[a][b] == 0) {
            b++;
            if(b == m) {
                a++;
                b = 0;
            }
            continue;
        }

        if(grid[i][j] == 1) {
            j++;
            if(j == m) {
                i++;
                j = 0;
            }
            continue;
        }

        if(i > a || (i== a && j > b)) {
            // cout<<"swapping "<<i<<" "<<j<<" "<<a<<" "<<b<<endl;
            swap(grid[i][j], grid[a][b]);
        }
        else {
            j++;
            if(j == m) {
                i++;
                j = 0;
            }
        }
    }

}


int main() {
    vector<vector<int>> input = {{1,1,1},
{1,1,1},
{1,1,1}};

    solve(input);

    for(auto e: input) {
        for(auto k: e) {
            cout<<k<<" ";
        }
        cout<<endl;
    }
    
    return 0;
    // output here

}