// https://leetcode.com/discuss/interview-question/5194349/Microsoft-Codility-OA-2024-May

#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;



int solve(vector<int> &arr) {
    

    int res = 0;
    for(int diff = 0; diff<1001; diff ++) {
        unordered_map<int, int> mp;
        for(int i = 0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }

        for(int i = 0; i < arr.size(); i++) {
            int temp = 0;
            int next = arr[i];
            while(true) {
                if(mp[next]) {
                    mp[next]--;
                    temp++;
                }
                else {
                    break;
                }
                next = next + diff;
            }
            res = max(res, temp);
        }
    }

    return res;


}


int main() {
    vector<int> input = {12,12,12,15,13,14};

    auto res = solve(input);
    cout<<res<<endl;
    
    // output here

}