#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>
#include <numeric>
#include <cmath>
using namespace std;

class Coord {
    public:
    int x, y;
    int tree_idx;

    Coord(int x, int y, int tree_idx): x(x), y(y), tree_idx(tree_idx){}
};

class SegmentTree2d {



    vector<vector<int>> tree;
    vector<vector<int>> arr;
    int n, m;
    
    public:

    int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        if(a == 0) {
            return b;
        }
        if(a == b) {
            return b;
        }

        if(a > b) {
            return gcd(a - b, b);
        }
        return gcd(a, b - a);

    }

    SegmentTree2d(vector<vector<int>> arr) {
        this->arr = arr;
        int n = arr.size(), m =0;
        if(n) {
            m = arr[0].size();
        }
        this->n = n, this->m = m;
        tree.resize(4*n, vector<int>(4*m));
        buildx(1, 0, n-1);
    }

    int buildy(int vx, int lx, int rx, int vy, int ly, int ry) {
        if(ly == ry) {
            if(lx == rx) {
                tree[vx][vy] = arr[lx][ly];
            }
            else {
                tree[vx][vy] = gcd(tree[vx*2][vy], tree[vx*2+1][vy]);
            }
        }
        else{
            int mid = ly + (ry - ly)/2;
            buildy(vx, lx, rx, vy*2, ly, mid);
            buildy(vx, lx, rx, vy*2+1, mid+1, ry);
            tree[vx][vy] = gcd(tree[vx][vy*2], tree[vx][vy*2+1]);
        }
        return tree[vx][vy];
    }

    int buildx(int vx, int l, int r) {
        if(l != r) {
            int mid = l + (r - l) /2;
            buildx(vx*2, l, mid);
            buildx(vx*2+1, mid +1, r);
        }

        return buildy(vx, l, r, 1, 0, m-1);

    }
    // use coordinates for indexes
    int update_y(int vx, int lx, int rx, int vy, int ly, int ry, int ix, int iy, int val)  {
        if(ly == ry) {
            if(lx == rx) {
                tree[vx][vy] = val;
            }
            else{
                tree[vx][vy] = gcd(tree[vx*2][vy], tree[vx*2+1][vy]); // should not reach here
            }
        }
        else{
            int mid = ly + (ry - ly)/2;
            if(iy <= mid) {
                update_y(vx, lx, rx, vy*2, ly, mid, ix, iy, val);
            }
            else {
                update_y(vx, lx, rx, vy*2+1, ly, ry, ix, iy, val);
            }
            tree[vx][vy] = gcd(tree[vx][vy*2], tree[vx][vy+2+1]);
        }
        return tree[vx][vy];

    }

    bool update_x(int vx, int l, int r, int ix, int iy, int val) {
        if(l == r) {
            update_y(vx, l, r, 1, 0, m-1, ix, iy, val);
        }
        else {
            int mid = l + (r - l)/2;

            if(ix <= mid) {
                update_x(vx*2, l, mid, ix, iy, val);
            }
            else {
                update_x(vx*2+1, mid+1, r, ix, iy, val);
            }
        }
        return true;
    }
    
    int get_gcd_y(int vx, int vy, int tly, int ty, int ly, int ry) {
        // cout<<tly<<" "<<ty<<" "<<vy<<endl; 
        if(ry < ly) {
            return 0;
        }
        if(tly == ly && ty == ry) {
            return tree[vx][vy];
        }
        int mid = tly + (ty - tly)/2;
        return gcd(get_gcd_y(vx, vy*2, tly, mid, ly, min(mid, ry)),
            get_gcd_y(vx, vy*2+1, mid+1, ty, max(mid+1, ly), ry)
        );

    }

    int get_gcd_x(int vx, int tl, int tr, int lx, int ly, int rx, int ry) {
        // cout<<tl<<" "<<tr<<" "<<vx<<endl;
        if(rx < lx) {
            return 0;
        }
        if(tl == lx && tr == rx) {
            return get_gcd_y(vx, 1, 0, m-1, ly, ry);
        }
        int mid = tl + (tr - tl)/2;

        return gcd(get_gcd_x(vx*2, tl, mid, lx, ly, min(rx, mid), ry), get_gcd_x(vx*2+1, mid+1, tr, max(mid+1, lx), ly, rx, ry));

    }

};


int main() {
    vector<vector<int>> arr = {
        {5, 10, 20}, {30, 50, 100}
    };


    SegmentTree2d st(arr);

    cout<<st.get_gcd_x(1, 0, arr.size() - 1, 1, 2, arr.size() - 1, arr[0].size() - 1)<<endl;

    return 0;
}