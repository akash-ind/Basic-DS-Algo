// https://leetcode.com/discuss/interview-question/4400176/Google-Onsite
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
a[i] - a[j] = i - j

a[i] - i = a[j] - j;

*/


int solve(vector<int> &arr) {
    
    unordered_map<int, int> mp;
    int res = 0;
    for(int i = 0; i<arr.size(); i++) {
        int val  = arr[i] - i;
        res += mp[val];

        mp[val]++;
    }

    return res;
}


int main() {
    // vector<int> input = { 2, 4, 6, 5, 9, 9, 11};
    vector<int> input = { 2, 2, 2};

    auto res = solve(input);

    cout<<res<<endl;
    
    // output here

}