// https://leetcode.com/discuss/interview-question/5092485/Microsoft-Interview-Questions-SE2-L61-Bangalore-or-Offer
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;



string solve(string &s, int k) {
    int  n = s.size();
    stack<pair<char, int>> st;

    for(int i = 0; i<n; i++) {
        if(st.empty()) {
            st.push({s[i], 1});
            continue;
        }

        if(st.top().first == s[i]) {
            int count = st.top().second + 1;
            st.push({s[i], count});
            if(count == k) {
               while (st.top().first == s[i])
               {
                st.pop();
               }
            }
        }
        else {
            st.push({s[i], 1});
        }
    }

    string res = "";
    while(!st.empty()) {
        res.push_back(st.top().first);
        st.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}


int main() {
    string input = "bbaaabc";

    auto res = solve(input, 3);
    
    cout<<res<<endl;
    // output here

}