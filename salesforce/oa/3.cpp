// https://leetcode.com/discuss/interview-question/4359045/Salesforce-Hackerrank-Questions-OA
#include<iostream>
#include<algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include<cstring>

using namespace std;

/*
max(|x - y|, |x+y|) >= max(|x|, |y|) always true
min(|x - y|, |x + y|) <= min(|x|, |y|)

x>=0 && y>=0(Q)
x-y <= x 

x - y <= y
x <= 2y

x < 0 && y < 0(Q)

|x - y| <= |x|

x - y <= -x
y >= 0  // impossible


x > 0  && y < 0(Q)

x + y <= x // true
x + y <= -y

x <= -2y(eq)

x < 0 && y> 0 (Q)

x + y <= -x

y <= -2x (eq)

*/

void swapChar(char c1, char c2, string &s, unordered_map<char, vector<int>> &mp) {
    for(int i: mp[c1]) {
        s[i] = c2;
    }
    for(int i: mp[c2]) {
        s[i] = c1;
    }

    swap(mp[c1], mp[c2]);

}

string getString(string &s) {
    int n = s.size();

    unordered_map<char, vector<int> > mp;

    int firstIndex[26];
    memset(firstIndex, -1, sizeof(firstIndex));
    for(int i = 0; i<n; i++) {
        mp[s[i]].push_back(i);
        if(firstIndex[s[i] - 'a'] == -1) {
            firstIndex[s[i]-'a'] = i;
        }
    }


    for(int i = 0; i<n; i++) {
        for(int j = 0; j< s[i] - 'a'; j++) {
            if(firstIndex[j] > i) {
                cout<<s[i]<<" swapped with "<<(char)(j+'a')<<endl;
                swap(firstIndex[s[i] - 'a'], firstIndex[j]);
                swapChar(s[i], j+'a', s, mp);
                break;
            }
        }
    }


    return s;
}

int main() {

    string s = "bbcacad";

    cout<<getString(s)<<endl;
    return 0;
}