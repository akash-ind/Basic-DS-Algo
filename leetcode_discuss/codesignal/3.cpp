// https://leetcode.com/discuss/interview-question/1112081/Codesignal-Help


#include<iostream>
#include <algorithm>
#include<vector>
#include <cmath>

using namespace std;

bool is_possible_cut(vector<int> &ribbons, int len, int k) {
    int cnt = 0;

    for(int ribbon: ribbons) {
        cnt += ribbon /len;
    }

    return cnt >= k;

}

int cut_the_ribbons(vector<int> &ribbons, int k) {


    int lo = 0, hi = 0;

    for( auto ribbon: ribbons) {
        hi = max(hi, ribbon);
    }

    while(lo<=hi) {
        int mid = lo + (hi - lo)/2;

        if(is_possible_cut(ribbons, mid, k)) {
            lo = mid+1;
        }
        else {
            hi = mid - 1;
        }

    }

    return hi;
    

}


int main() {

    vector<int> ribbons = {1, 2, 3, 4, 9};

    cout<<cut_the_ribbons(ribbons, 6)<<endl;

    return 0;
}