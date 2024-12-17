// https://leetcode.com/discuss/interview-question/5293722/Phone-Screen
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
#include <stack>

using namespace std;


class CMP {
    public:

    bool operator ()(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }

        return a.first < b.first;
    }

};

int solve(vector<int> &arr, int k) {
    stack<int> st;

    for(int i = 0; i< arr.size(); i++) {
        int val = arr[i];
        if(val == 0 && st.empty()) {
            continue;
        }

        if(!st.empty() && st.top() < val && st.size() + arr.size() - i - 1 >= k ) {
            st.pop();
        }

        st.push(arr[i]);
    }
    vector<int> dig;
    while(!st.empty() && k) {
        dig.push_back(st.top());
        st.pop();
        k--;
    }

    reverse(dig.begin(), dig.end());

    int ans = 0;

    for(int i = 0; i<dig.size(); i++) {
        ans *=10;
        ans += dig[i];
    }

    return ans;

}


int main() {
    vector<int> input = {1,1,0, 1};

    auto res = solve(input, 3);
    cout<<res<<endl;
    
    // output here

}