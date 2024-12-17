//https://leetcode.com/discuss/interview-question/4986072/Microsoft-or-OA-or-Maximum-Sum-of-Merged-Array-Pairs

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


int merge_int(int a, int b) {
    vector<int> dig;
    if(b == 0) {
        return a*10;
    }
    while(b) {
        dig.push_back(b%10);
        b/=10;
    }
    for(int i = dig.size() - 1; i>=0; i--) {
        a*=10;
        a+=dig[i];
    }

    return a;
}


int solve(vector<int> & arr) {
    int n = arr.size();
    vector<int> dp(n+1, 0);
    for(int i = 1; i<=n; i++) {

        if(i - 2 < 0) {
            dp[i] = max(dp[i-1] + arr[i-1], merge_int(arr[i-2], arr[i-1]));
            continue;
        }
        dp[i] = max(dp[i-1] + arr[i-1], dp[i-2] + merge_int(arr[i-2], arr[i-1]));
    }

    return dp[n];
}


int main() {
    vector<int> input = {12, 6, 18, 10, 1, 0};

    auto res = solve(input);
    cout<<res<<endl;
    
    // output here

}