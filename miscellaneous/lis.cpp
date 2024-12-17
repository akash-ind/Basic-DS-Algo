#include<iostream>
#include <algorithm>
#include<vector>
#include <cmath>
#include <climits>

using namespace std;

vector<int> get_lis_path(vector<int> &arr) {
    int n = arr.size();

    vector<int> dp(n + 1, INT_MAX);
    vector<int> par(n, -1);
    vector<int> ind(n+1, -1);

    dp[0] = -1;

    for(int i = 0; i<n; i++) {
        int l = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

        if(arr[i] < dp[l]) {
            dp[l] = arr[i];
            ind[l] = i;
            par[i] = ind[l-1];
        }
    }

    vector<int> seq;
    int len = 1;
    int cur_ind = -1;
    for(int i = n; i>0; i--) {
        if(dp[i] < INT_MAX) {
            len = i;
            cur_ind = ind[len];
            break;
        }
    }

    while(cur_ind != -1) {
        seq.push_back(arr[cur_ind]);
        cur_ind = par[cur_ind];
    }
    reverse(seq.begin(), seq.end());

    return seq;
}


int main() {

    vector<int> arr = {10, 5 ,6, 7, 1, 2, 4};
    auto lis_path = get_lis_path(arr);

    for(int i: lis_path) {
        cout<<i <<" ";
    }

    cout<<endl;

    return 0;

}