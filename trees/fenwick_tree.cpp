#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>

using namespace std;

class FenwickTree {

    vector<vector<int>> bit;

public:

    FenwickTree(vector<vector<int>> arr) {
        bit.resize(arr.size()+1, vector<int>(arr[0].size()+1, 0));

        for(int i = 0; i< arr.size(); i++) {
            for(int j = 0; j<arr[0].size(); j++) {
                update(i, j, arr[i][j]);
            }
        }
    }


    bool update(int x, int y, int delta) {
        for(int i = ++x; i< bit.size(); i += i&-i) {
            for(int j = ++y; j< bit[0].size(); j+= j&-j) {
                bit[i][j] += delta;
            }
        }

        return true;
    }

    int get_sum(int x, int y) {
        int sum = 0;

        for(int i = ++x; i>0; i-= i&-i) {
            for(int j = ++y; j>0; j -= j&-j) {
                sum += bit[i][j];
            }
        }

        return sum;
        
    }

    int get_sum(int x1, int y1, int x2, int y2) {
        return get_sum(x2, y2) - get_sum(x1-1, y1-1);
    }

};

class RangeFenwickTree {
    vector<int> bit1, bit2;

public:
    RangeFenwickTree(vector<int> &arr) {
        bit1.resize(arr.size()+1, 0);
        bit2.resize(arr.size()+1, 0);

        for(int i = 0; i<arr.size(); i++) {
            update(i, i, arr[i]);
        }
    }

    bool update_bit1(int ind, int delta) {

        for(int i = ++ind; i<bit1.size(); i += i&-i) {
            bit1[i] += delta;
        }
        return true;
    }

    bool update_bit2(int ind, int delta) {
        for(int i = ++ind; i<bit2.size(); i += i&-i) {
            bit2[i] += delta;
        }
        return true;
    }

    bool update(int l, int r, int delta) {

        update_bit1(l, delta);
        update_bit1(r+1, -delta);

        update_bit2(l, delta*(l-1));
        update_bit2(r+1, -delta*r);
        return true;
    }

    int get_bit1_sum(int ind) {
        int sum = 0;
        for(int i = ++ind; i>0 ; i -= i&-i) {
            sum += bit1[i];
        }

        return sum;
    }

    int get_bit2_sum(int ind) {
        int sum = 0;

        for(int i = ++ind; i>0; i-= i&-i) {
            sum += bit2[i];
        }
        return sum;
    }

    int get_sum(int ind) {
        return ind * get_bit1_sum(ind) - get_bit2_sum(ind);
    }

    int get_sum(int l, int r) {
        return get_sum(r) - get_sum(l-1);
    }

};

int main() {

    vector<vector<int>> val = {
        {1, 2, 3},
        {2, 3, 4}
    };

    vector<int> val2 = {4, 5, 6, 7};

    auto f1 = FenwickTree(val);

    cout<<0<<" "<<1<<" "<<1<<" 1 "<< f1.get_sum(0, 1, 1, 1)<<endl;
    cout<<"1 1 update + 5 "<<f1.update(1, 1, 5)<<endl;
    cout<<0<<" "<<1<<" "<<1<<" 1 "<< f1.get_sum(0, 1, 1, 1)<<endl;

    auto f2 = RangeFenwickTree(val2);  //possible but not learning it now

    cout<<"Range sum 1, 3 "<<f2.get_sum(1, 3)<<endl;
    cout<<"update 2, 3 -4 "<<f2.update(2, 3, -4)<<endl;
    cout<<"Range sum 1, 3 "<<f2.get_sum(1, 3)<<endl;

    return 1;
}