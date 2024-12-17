// https://leetcode.com/discuss/interview-question/4366540/Google-or-Onsite-or-Insert-and-query-ranges

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

class Range {
    map<int, int> mp; // {st, en}

    public:

    bool insert(int st, int en) {
        if(mp.empty()) {
            mp[st] = en;
            return true;
        }
        auto it = mp.upper_bound(st);
        if(it != mp.begin()) {
            it--;
            if(it->second >= st) {
                st = it->first;
            }
            else{
                it++;
            }
        }

        auto end_it = mp.upper_bound(en);

        mp.erase(it, end_it);
        mp[st] = en;
        return true;
    }

    bool query(int st) {
        auto it = mp.upper_bound(st);
        if(it == mp.begin()) {
            return false;
        }

        it --;
        if(it->second >= st) {
            return true;
        }
        return false;
    }
    void iterate() {
        for(auto p: mp) {
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
};



int solve(vector<vector<int>> &queries) {

    Range r = Range();
    for(auto q: queries) {
        if(q[0] == 0){
            r.insert(q[1], q[2]);
        } // insert 
        else{
            cout<<r.query(q[1])<<" ";
        }
        r.iterate();
        cout<<"--------"<<endl;
    }

    return 0;



}


int main() {
    vector<vector<int>> queries = {
        {0, 2, 3},
        {0, 9, 15},
        {0, 3, 8},
        {1, 0},
        {1, 3},
        {1, 5}
    };

    auto res = solve(queries);
    
    // output here

}