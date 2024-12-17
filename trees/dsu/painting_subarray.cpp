#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class DSU {
    vector<int> par;
    vector<int> sz;

public:
    DSU(int len) {
        par.resize(len, 0);
        sz.resize(len, 1);

        for(int i = 0; i<len; i++) {
            par[i] = i;
        }
    }


    int get_root(int v) {
        if(par[v] == v) {
            return v;
        }

        return par[v] = get_root(par[v]);
    }


    bool unite(int a, int b) {
        int r1 = get_root(a);
        int r2 = get_root(b);
        if(r1 == r2) {
            return true;
        }

        if(sz[r1] < sz[r2]) {
            swap(r1, r2);
        }

        par[r2] = r1;
        return true;
    }

};


vector<int> get_final_color(int len, vector<vector<int>> queries) {
    auto dsu = DSU(len);

    vector<int> color(len, 0);

    for(int i = queries.size() - 1; i>=0; i--) {
        int l = queries[i][0], r = queries[i][1], c = queries[i][2];


        for(int j = dsu.get_root(l); j<=r; j = dsu.get_root(j)) {
            color[j] = c;
            dsu.unite(j, j+1);
        }
    }

    return color;

}