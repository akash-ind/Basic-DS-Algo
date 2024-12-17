/*
 How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

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
dp[pos][cnt][smaller] -> the count of numbers where the no is of size pos + 1 having cnt of digit = cnt


dp[pos][cnt] = dp[pos-1][cnt(a)] + dp[pos-1][cnt(b)] + dp[pos-1][cnt(c)] ..

*/

class MaxNumber {

    public:

        int d, k;

        MaxNumber(int d, int k) : d(d), k(k) {}

        long long dp[19][10][2];
        vector<int> digits;
        long long calcNumbers(int pos, int cnt, bool smaller) {
            if(cnt > k) {
                return 0;
            }
            if(pos == digits.size()) {
                if(cnt == k) {
                    return 1;
                }
                return 0;
            }


            if(dp[pos][cnt][smaller] != -1) {
                return dp[pos][cnt][smaller];
            }

            int ub = smaller ? 9: digits[pos];
            long long res = 0;
            for(int i = 0; i<=ub; i++) {
                int fcnt = cnt + (d == i);
                int fsmaller = smaller || i != ub;
                res += calcNumbers(pos+1, fcnt, fsmaller);
            }

            return dp[pos][cnt][smaller] = res;

        }


        bool calc(long long x) {
            string num = to_string(x);
            for(int i = 0; i<num.size(); i++) {
                digits.push_back(num[i] - '0');
            }

            memset(dp, -1, sizeof(dp));
            cout<<calcNumbers(0, 0, false)<<endl;
            
            return true;
        }


};



int main() {
    MaxNumber mx(0, 2);
    mx.calc(20);
}