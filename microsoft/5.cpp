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

vector<int> tree;

void add(int l, int n, int delta) {
    for(int i = l; i<=n; i+= i& -i) {
        tree[i] += delta;
    }
}

int get_value(int l) {
    int sum = 0;
    for(int i = l; i>0; i-= i&-i) {
        sum += tree[i];
    }
    return sum;
}

void range_add(int l, int r, int n, int delta) {
    add(l, n, delta);
    add(r, n, -delta);
}

int solve(vector<int> &arr) {
    int n = arr.size();

    tree.resize(n+1, 0);
    set<pair<int, int>> s;
    for(int i =0; i<n; i++) {
        s.insert({arr[i], i});
    }

    int res = 0;
    int cur_size = n;
    int cur_index = 0;
    int total_iter = 0;
    vector<int> t;
    int wait_time = 0;
    for(auto p: s) {
        // cout<<wait_time<<" ";
        auto [_, index] = p;
        // cout<<cur_index<<endl;

        for(int i = cur_index; i!= index; i = (i+1)%n) {
            if(arr[i] > 0) {
                arr[i] -= 1;
                wait_time++;
            }
        }

        // cout<<arr[index]<<" "<<index<<" "<<wait_time<<" ";
        arr[index] -= total_iter;

        if(arr[index] <= 0) {
            cur_size -= 1;
            continue;
        }
        wait_time++;

        total_iter += arr[index] - 1;
        wait_time += (cur_size)*(arr[index] - 1);
        cur_size -= 1;
        res += wait_time;
        // cout<<wait_time<<endl;
        cur_index = (index + 1)%n;
    }

    return res;

}


int main() {
    vector<int> input = {3, 1, 2};

    auto res = solve(input);
    
    cout<<res<<endl;
    // output here

}