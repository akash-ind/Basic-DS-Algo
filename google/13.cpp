// https://leetcode.com/discuss/interview-question/5230887/Google-or-L4-or-Phone-Screening-or-Round-1
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

class CMP {
  public:

    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if(b.second == a.second) {
            return b.first > a.first;
        }

        return a.second > b.second;
    }
};


int solve(vector<vector<int>> &intervals) {

    sort(intervals.begin(), intervals.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, CMP> pq;

    for(auto interval: intervals) {
        int start = interval[0], end = interval[1];
        if(pq.empty()) {
            pq.push({interval[0], interval[1]});
            continue;
        }

        if(start > pq.top().second) {
            pq.pop();
        }

        pq.push({start, end});
    }

    return pq.size();

}


int main() {
    vector<vector<int>> input =  {{1,7}, {2,7},{6,7},{7,10},{7,10}};

    auto res = solve(input);

    cout<<res<<endl;
    
    // output here

}