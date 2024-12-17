// https://leetcode.com/discuss/interview-question/5092485/Microsoft-Interview-Questions-SE2-L61-Bangalore-or-Offer
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

vector<int> get_digits(int a) {
    vector<int> dig;

    if(a == 0) {
        return {0};
    }
    while(a) {
        dig.push_back(a%10);
        a/=10;
    }

    reverse(dig.begin(), dig.end());

    return dig;
}

bool cmp(int a, int b) {
    auto a_dig = get_digits(a);
    auto b_dig = get_digits(b);

    int n = a_dig.size(), m = b_dig.size();
    for(int i = 0; i< min(n, m); i++) {
        if(a_dig[i] > b_dig[i]) {
            return true;
        }
        if(a_dig[i] < b_dig[i]) {
            return false;
        }
    }

    if(a_dig.size() < b_dig.size()) {
        swap(a_dig, b_dig);
    }

    return a_dig[0] < a_dig[b_dig.size()];
}

string solve(vector<int> &nums) {

    sort(nums.begin(), nums.end(), cmp);

    string res = "";

    for(int num: nums) {
        auto dig = get_digits(num);
        for(int d: dig) {
            res.push_back('0' + d);
        }
    }

    return res;

}


int main() {
    vector<int> input = {3, 30, 34, 5, 8888, 888883};

    auto res = solve(input);

    cout<<res<<endl;
    
    // output here

}