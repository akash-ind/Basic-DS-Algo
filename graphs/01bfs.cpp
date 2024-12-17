#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>

using namespace std;


class Edge {
    
public:
    int from, to, weight;
    Edge(int from, int to, int weight) { // weight = 0/1
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};



class BFSAlgo {

    vector<vector<Edge>> g;

public:

    BFSAlgo(vector<vector<Edge>> g) {
        this-> g = g;

    }

    vector<int> bfs01(int source) {

        int g_size = g.size();

        deque<int> q;

        vector<int> dist(g_size, INT_MAX);
        vector<int> marked(g_size, false);

        dist[source] = 0;

        q.push_back(source);

        while(!q.empty()) {

            int vertex = q.front();
            q.pop_front();
            if(marked[vertex]) {
                continue;
            }
            marked[vertex] = true;

            for(auto e: g[vertex]) {
                if(dist[e.to] > dist[e.from] + e.weight) {
                    dist[e.to] = dist[e.from] + e.weight;
                    if(e.weight == 0) {
                        q.push_front(e.to);
                    }
                    else{
                        q.push_back(e.to);
                    }
                }
            }
        }

        return dist;

    }
};




vector<vector<Edge>> create_graph() {
    vector<vector<Edge>> res(5, vector<Edge>());

    res[0].push_back(Edge(0, 1, 0));
    res[1].push_back(Edge(1, 0, 1));
    res[1].push_back(Edge(1, 2, 1));
    // res[2].push_back(Edge(1, 2, 5));
    res[2].push_back(Edge(2, 3, 0));
    // res[3].push_back(Edge(2, 3, 9));
    res[3].push_back(Edge(3, 4, 1));
    // res[4].push_back(Edge(3, 4, 8));
    res[0].push_back(Edge(0, 3, 0));
    // res[3].push_back(Edge(0, 3, 2));
    // res[1].push_back(Edge(1, 4, 3));
    // res[4].push_back(Edge(1, 4, 3));

    return res;
}


int main() {
    auto g = create_graph() ;
    auto bfs_algo = BFSAlgo(g);

    auto dist = bfs_algo.bfs01(0);

    for(int i = 0; i< g.size(); i++) {
        cout<<i<<" "<<dist[i]<<endl;
    }

    return 1;
}