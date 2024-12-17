#include<iostream>
#include <vector>

using namespace std;

int farthest = -1, dist = -1;

void calcFarthest(vector<vector<int>> &g, int st, vector<bool> &vis, int d = 0) {
    if(d > dist) {
        dist = d;
        farthest = st;
    }
    vis[st] = true;

    for(auto v: g[st]) {
        if( !vis[v] ) {
            calcFarthest(g, v, vis, d+1);
        }
    }

}

int get_diameter(vector<vector<int>> edges, int n) {
    vector<vector<int>> g(n, vector<int>());
    for(auto e: edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }

    vector<bool> vis(n, false);
    calcFarthest(g, 1, vis, 0);
    cout<<farthest<<" ";
    dist = -1;
    vis.assign(n, false);
    calcFarthest(g, farthest, vis, 0);
    cout<<farthest<<endl;

    return dist;


}


// vector<vector<int>> create_graph() {
//     vector<vector<int>> res(5, vector<int>());

//     res[0].push_back(1);
//     res[1].push_back(2);
//     res[2].push_back(3);
//     // res[3].push_back(1);
//     res[3].push_back(4);
//     return res;
// }



int main() {

    vector<vector<int>> edges  = {
        {1, 2}, {2, 3}, {3, 7}, {2, 4}, {4, 5}, {4, 6}
    };

    cout<<get_diameter(edges, 8);

    return 0;
}