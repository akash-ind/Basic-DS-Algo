// https://leetcode.com/discuss/interview-question/3583115/returns-the-string-representing-the-palindromic-number

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



string solve(string &s) {
    deque<char> q;
    map<char, int> mp;
    char middle_char = '-';

    for(char c: s) {
        mp[c]++;
    }

    while(true) {
        bool added = false;
        for(auto it= mp.rbegin(); it != mp.rend();it++) {
            if(q.empty() && it->first == '0') {
                break;
            }
            if(it->second >= 2) {
                q.push_back(it->first);
                q.push_front(it->first);
                it->second -= 2;
                added = true;
            }
        }

        if (!added) {
            for(auto it= mp.rbegin(); it != mp.rend(); it++) {
                if(it->second) {
                    middle_char = it->first;
                    it->second--;
                    break;
                }
            }
            break;
        }
    }

    string res = "";
    // if(middle_char != '-') {
    //     res = middle_char;
    // }
    deque<char> temp;

    while (!q.empty())
    {
        temp.push_back(q.back());
        q.pop_back();
        temp.push_front(q.front());
        q.pop_front();
    }

    while(!temp.empty()) {
        res.push_back(temp.front());
        temp.pop_front();
    }
    if(middle_char != '-') {
        res.insert(res.begin() + res.size()/2, middle_char);
    }

    return res;


}


int main() {
    string input = "9999991";

    auto res = solve(input);
    
    cout<<res<<endl;

}