#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
Simple function calculating the max length of prefix that is also suffix of the strings 
(except perfect prefix i.e prefix is whole string)

*/


class KMPAlgo {
    string s;

    public:
    KMPAlgo(string s) {
        this->s = s;
    }

    vector<int> get_prefix_fn() {
        int n = s.size();
        vector<int> res(n, 0);

        for(int i = 1; i < n; i++) {
            int len = res[i-1];

            while(len > 0 && s[len] != s[i]) {
                len = res[len - 1];
            }

            if(s[len] == s[i]) {
                len++;
            }

            res[i] = len;
        }

        return res;
    }
};

int main() {
    string s = "hehehehhhh";

    auto kmp_algo = KMPAlgo(s);
    auto res = kmp_algo.get_prefix_fn();
    for(int i: res) {
        cout<<i<< " ";
    }
    cout<<endl;
    return 0;
}