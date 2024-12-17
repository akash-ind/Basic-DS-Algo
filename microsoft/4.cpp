// https://leetcode.com/discuss/interview-question/5102949/Microsoft-OA-May-2024-Question-3

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

bool is_valid(vector<int> &arr, int len) {
    
    int index = upper_bound(arr.begin(), arr.end(), arr[0]+len) - arr.begin();
    int n = arr.size();
    if(index >= arr.size()) {
        return true;
    }

    return (arr[n-1] - arr[index]) <= len;

}



int solve(vector<int> & arr) {
    if(arr.size() == 0) {
        return 0;
    }
    sort(arr.begin(), arr.end());
    int n = arr.size();

    int len = arr[n-1] - arr[0];

    int lo = 1, hi = len+1;


    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;

        if(is_valid(arr, mid)) {
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    return lo;


}


int main() {
    vector<int> input = {0, 44, 32, 30 , 42, 18, 34, 16, 35};

    auto res = solve(input);
    cout<<res<<endl;
    
    // output here

    return 0;

}