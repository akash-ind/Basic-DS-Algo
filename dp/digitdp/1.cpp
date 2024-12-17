/*
Round 2: You are tasked with writing a sequence of positive integers starting from 1. 
However, you have a constraint: for each digit (0-9), you can press its corresponding key a maximum of n times, 
where n can be as large as a 64-bit integer.
You need to determine the last number you can write before running out of allowed presses for any digit.


Example:
For n = 5, the last number you can write is 12. You can write numbers from 1 to 12, 
but to write 13, you would need to press the '1' key for the sixth time, which exceeds the limit.


*/

#include<iostream>
#include<algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <set>

using namespace std;

/*
Think more about DP states.

*/

class MaxNumber {

    public:

        int n;

        MaxNumber(int n) : n(n) {}

        long long dp[19][10][2];
        vector<int> digits;
        vector<int> countDigits;
        long long calcTotalDigits(int pos, int digit, bool smaller, bool started, bool takedigit) {
            if(pos == digits.size()) {
                return 0;
            }

            if(dp[pos][digit][smaller] != -1) {
                return dp[pos][digit][smaller];
            }

            int ub = smaller ? 9: digits[pos+1];
            if(started || digit != 0)
                dp[pos][digit][smaller] = 1;
            else 
                dp[pos][digit][smaller] = 0;
            // cout<<digit<<" "<<pos<<" "<<ub<<endl;
            for(int i = 0; i<=ub; i++) {
                long long res = calcTotalDigits(pos + 1, i, smaller || i != ub, started || i != 0, !started && i!=0);
                if(started || digit != 0) {
                    dp[pos][digit][smaller] += res;
                }
            }
            if (takedigit) {
                countDigits[digit] += dp[pos][digit][smaller];
            }

            // cout<<pos<<" "<<digit<<" "<<dp[pos][digit][smaller]<<endl;
            return dp[pos][digit][smaller];
        }


        bool calc(long long x) {
            string num = to_string(x);
            for(int i = 0; i<num.size(); i++) {
                digits.push_back(num[i] - '0');
            }
            countDigits.resize(10, 0);

            memset(dp, -1, sizeof(dp));
            for(int i = 0; i<=digits[0]; i++) {
                // calcTotalDigits(0, i, i != digits[0], i!=0);
                calcTotalDigits(0, i, i != digits[0], i != 0, i!=0);
            }

            for(int i = 0; i<=9; i++) {
                cout<<i<<" "<<countDigits[i]<<endl;
            }
            
            return true;
        }


};



int main() {
    MaxNumber mx(12);
    mx.calc(21);
}