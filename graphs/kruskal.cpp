#include<iostream>
#include<algorithm>
#include <vector>


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

bool operator<(const Edge e1, const Edge &e2) {
    return e1.weight < e2.weight;
}

class DSU {
    public:
    int sz;
    vector<int> parent, tree_size;
    DSU(int sz) {
        this->sz = sz;
        parent.resize(sz);
        tree_size.resize(sz);
        for(int i = 0; i<sz; i++) {
            parent[i] = i;
            tree_size[i] = 1;
        }
    }
    int getRoot(int v) {
        if(parent[v] == v) {
            return v;
        }

        return parent[v] = getRoot(parent[v]);
    }

    bool unite(int a, int b) {
        cout<<a<<" "<<b<<endl;
        int r1 = getRoot(a);
        int r2 = getRoot(b);
        if(r1 == r2) {
            return true;
        }

        if(tree_size[r1] < tree_size[r2]) {
            swap(r1, r2);
        }

        parent[r2] = r1;
        tree_size[r1] += tree_size[r2];
        return true;
    }
};


class KruskalAlgo {
    vector<Edge> edges;
    int vertex_count;

public:
    KruskalAlgo(vector<Edge> edges, int vertex_count) {
        this->edges = edges;
        this->vertex_count = vertex_count;
    }

    vector<Edge> get_mst_edge() {
        sort(edges.begin(), edges.end());

        // vector<int> tree_id(vertex_count);
        DSU tree_id(vertex_count);
        // for(int i = 0; i< vertex_count; i++) {
        //     tree_id[i] = i;
        // }
        vector<Edge> mst_edges;
        for (Edge e: edges) {
            if(mst_edges.size() == vertex_count - 1) {  // Already a tree - valid in case of connected graph only.
                break;
            }
            // cout<<e.either<<" "<<e.other<<endl;
            if(tree_id.getRoot(e.either) == tree_id.getRoot(e.other)) {
                continue;
            }
            else{
                mst_edges.push_back(e);
                // cout<<e.either<<" "<<e.other<<endl;
                tree_id.unite(e.either, e.other);
            }
        }
        cout<<"here"<<endl;

        return mst_edges;

    }
};



vector<Edge> create_graph() {
    vector<Edge> res;

    res.push_back(Edge(0, 1, 4));
    res.push_back(Edge(1, 2, 5));
    res.push_back(Edge(2, 3, 9));
    res.push_back(Edge(3, 4, 8));
    res.push_back(Edge(0, 3, 2));
    res.push_back(Edge(1, 4, 3));

    return res;
}



int main() {
    auto g = create_graph() ;
    auto kruskal_algo = KruskalAlgo(g, 5);
    auto edges = kruskal_algo.get_mst_edge();
    for(Edge e: edges) {
        cout<<e.either<<" "<<e.other<<" "<<e.weight<<endl;
    }

    return 1;
}