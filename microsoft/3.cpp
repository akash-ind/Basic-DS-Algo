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

pair<int, int> get_row_inverse(int i, int j, int n, int m) {
    return {i, m - j -1};
}

pair<int, int> get_col_inverse(int i, int j, int n, int m) {
    return {n - i - 1, j};
}



int solve(vector<string> & grid) {

    int n = grid.size(), m = grid[0].size();



    int res = 0;

    for(int i = 0; i<(n+1)/2; i++) {
        for(int j = 0; j<(m+1)/2; j++) {
            set<int> rr = {i, n - i - 1};
            set<int> cc = {j, m - j - 1};
            int b = 0, w = 0;
            for(int r: rr) {
                for(int c: cc) {
                    if(grid[r][c] == 'B') {
                        b++;
                    }
                    else {
                        w++;
                    }
                }
            }

            res += min(b, w);
        }
    }

    return res;

}


int main() {
    vector<string> input = {"BBWWB", "WWWBW", "BWWWW"};

    auto res = solve(input);
    
    cout<<res<<endl;
    // output here

}