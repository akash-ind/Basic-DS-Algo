#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>

using namespace std;


class DSU {

    vector<int> parent;
    vector<int> tree_size;

public:

    DSU(int size) {
        parent.resize(size);
        tree_size.resize(size);
        for(int i = 0; i < size; i++) {
            parent[i] = i;
            tree_size[i] = 1;
        }
    }

    int get_root(int a) {

        if(parent[a] == a) {
            return a;
        }

        return parent[a] = get_root(parent[a]);
    }

    bool make_set(int a, int b) {

        int root_a = get_root(a);
        int root_b = get_root(b);
        if(root_a == root_b) {
            return true;
        }

        if(tree_size[root_a] < tree_size[root_b]) {
            swap(a, b);
        }

        parent[b] = a;
        tree_size[a] += tree_size[b];
        return true;
    }

};