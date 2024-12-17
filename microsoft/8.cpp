//https://leetcode.com/discuss/interview-question/5099446/Microsoft-OA-Question

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



string solve(string &num) {
    int n = num.size();
    if(num[0] == '1') {
        return string(num.size() - 1, '9');
    }

    string res;
    res.push_back(num[0] - 1);


    return res + string(num.size() - 1, '9');

}


int main() {
    string input = "98";

    auto res = solve(input);

    cout<<res<<endl;
    
    // output here

}