// https://leetcode.com/discuss/interview-question/4422524/Google-Onsite-interview
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
    dp = []
    coins = [] -> 10

    start from 0 - n
    for i = 1 .. n
        if dp[i] > 0:
            int sum = 0;
            for coin in coins: 
                sum += dp[i - coin];
            if(sum < dp[i]) {
                coins.push_back(i);
            }

*/


vector<int> solve(vector<int> &sum_dp) {

    vector<int> coins;

    for(int i = 1; i<sum_dp.size(); i++) {
        if(sum_dp[i]> 0) {
            int sum = 0;
            for(int coin : coins) {
                sum += sum_dp[i - coin];
            }

            if(sum < sum_dp[i]) {
                coins.push_back(i);
            }
        }
    }

    return coins;

}


int main() {
    vector<int> input = {1, 0, 1, 0, 1, 1, 2, 1, 2, 1, 3};

    auto res = solve(input);

    for(int i: res){
        cout<<i<<" ";
    }
    
    // output here

}