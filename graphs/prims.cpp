#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>

using namespace std;


class Edge {
    
public:
    int either, other, weight;
    Edge(int either, int other, int weight) {
        this->either = either;
        this->other = other;
        this->weight = weight;
    }
};

class Comparator {
    public:
    bool operator()(const Edge &e1, const Edge &e2) {
        return e1.weight > e2.weight;
    }

};



class PrimsAlgo {
    vector<vector<Edge>> g;

public:

    PrimsAlgo(vector<vector<Edge>> g) {
        this->g = g;
    }

    vector<Edge> get_mst_edges() {
        int g_size = g.size();

        int st = 0;

        vector<Edge> mst_edges;

        vector<bool> is_marked(g_size, false);
        is_marked[0] = true;

        priority_queue<Edge, vector<Edge>, Comparator> pq;

        for(Edge e: g[0]) {
            pq.push(e);
        }
        // cout<<"PQ contents"<<endl;
        while(!pq.empty() && mst_edges.size() != g_size-1) { 
            auto e = pq.top();
            // cout<<e.either<<" "<<e.other<<" "<<e.weight<<endl;
            pq.pop();
            if(is_marked[e.either] && is_marked[e.other]) {
                continue;
            }
            int unmarked_vertex;
            if (!is_marked[e.either]) {
                unmarked_vertex = e.either;
            }
            else{
                unmarked_vertex = e.other;
            }
            mst_edges.push_back(e);
            is_marked[unmarked_vertex] = true;
            for(auto e: g[unmarked_vertex]) {
                if(is_marked[e.either] && is_marked[e.other]) {
                    continue;
                }
                pq.push(e);
            }
        }
        cout<<"PQ contents end"<<endl;
        return mst_edges;

    }

};


vector<vector<Edge>> create_graph() {
    vector<vector<Edge>> res(5, vector<Edge>());

    res[0].push_back(Edge(0, 1, 4));
    res[1].push_back(Edge(0, 1, 4));
    res[1].push_back(Edge(1, 2, 5));
    res[2].push_back(Edge(1, 2, 5));
    res[2].push_back(Edge(2, 3, 9));
    res[3].push_back(Edge(2, 3, 9));
    res[3].push_back(Edge(3, 4, 8));
    res[4].push_back(Edge(3, 4, 8));
    res[0].push_back(Edge(0, 3, 2));
    res[3].push_back(Edge(0, 3, 2));
    res[1].push_back(Edge(1, 4, 3));
    res[4].push_back(Edge(1, 4, 3));

    return res;
}


int main() {
    auto g = create_graph() ;
    auto prims_algo = PrimsAlgo(g);
    auto edges = prims_algo.get_mst_edges();
    for(Edge e: edges) {
        cout<<e.either<<" "<<e.other<<" "<<e.weight<<endl;
    }

    return 1;
}