#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


class SegmentTree {

    vector<int> tree;

    public:

    SegmentTree(vector<int> arr) {
        int n = arr.size();
        tree.resize(4*n+1, 0);

        build(arr, 1, 0, n-1);
    }

    int merge(int a, int b) {
        return a+b;
    }

    int build(vector<int> & arr, int v, int l, int r) {
        if(l == r) {
            tree[v] = arr[l];
            return arr[l];
        }

        int mid = l + (r - l)/2;

        return tree[v] = merge(build(arr, v*2, l, mid), build(arr, v*2+1, mid+1, r));
    }

    bool update(int index, int val, int l, int r, int v) {
        if(l == r) {
            tree[v] = val;
            return true;
        }
        int mid = l + (r - l)/2;

        if(index <= mid) {
            update(index, val, l, mid, v*2);
        }
        else {
            update(index, val, mid+1, r, v*2+1);
        }

        tree[v] = merge(tree[v*2], tree[v*2]+1);

        return true;

    }


    int get_sum(int l, int r, int tl, int tr, int v) {
        // cout<<"tl "<<tl<<" "<<tr<<endl;
        // cout<<"l "<<l<<" "<<r<<endl;
        if(l > r) {
            return 0;
        }
        if(tl == l && tr == r) {
            return tree[v];
        }

        int mid = tl + (tr - tl)/2;

        return merge(
            get_sum(l, min(r, mid), tl, mid, v*2), get_sum(max(l, mid+1), r, mid+1, tr, v*2+1)
        );
    }

};


int main() {
    vector<int> arr = {
        1, 2, 3, 4, 5, 6, 7, 8
    };

    auto st= SegmentTree(arr);
    // cout<<"here"<<endl;
    int n = arr.size();

    cout<<st.get_sum(5, 7, 0, n - 1, 1)<<endl;
    cout<<st.update(5, 10, 0, n-1, 1)<<endl;
    cout<<st.get_sum(5, 7, 0, n - 1, 1)<<endl;
    return 0;
}