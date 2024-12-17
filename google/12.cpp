// https://leetcode.com/discuss/interview-question/5254599/Google-L3-interview-question
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



int solve(vector<int> transactions, int funds) {

    int res = 0, n = transactions.size();
    int cur_sum = 0;
    for(int i =0, j = 0; j<n; j++) {
        cur_sum += transactions[j];
        while(cur_sum < -funds) {
            cur_sum -= transactions[i];
            i++;
        }

        res = max(res, j - i + 1);
    }

    return res;

}


int main() {
    vector<int> input = {-1,2,-5,3,1,1,1,1,1};

    auto res = solve(input, 2);
    
    cout<<res<<endl;
    // output here

}