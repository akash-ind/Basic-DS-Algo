#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool fn(int x) {
    return true;
}


int get_maximum() {
    int lo = 0, hi = 1e5;


    while(lo < hi) {

        int m1 = lo + (hi - lo)/3;
        int m2 = hi - (hi - lo)/3;

        if(fn(m1) > fn(m2)) {
            hi = m2;
        }
        else{
            lo = m1;
        }
    }

    return lo;
}