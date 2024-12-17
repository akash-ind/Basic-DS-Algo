#include<iostream>
#include <algorithm>
#include<vector>
#include <cmath>
#include <climits>

using namespace std;

string calculate_lcs(string &a, string &b) {
    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {

            if(a[i] == b[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else {
                dp[i+1][j+1] = max(dp[i][j], max(dp[i][j+1], dp[i+1][j]));
            }
        }
    }

    string s ="";

    for(int i = n, j = m; i>0 && j>0;) {
        if(a[i-1] == b[j-1]) {
            s.push_back(a[i-1]);
            i--, j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            }
            else{
                j--;
            }
        }
    }

    reverse(s.begin(), s.end());

    return s;

}


int main() {
    string a = "hellow";
    string b = "hellew";

    auto s = calculate_lcs(a, b);

    cout<<s<<endl;
    return 0;
}