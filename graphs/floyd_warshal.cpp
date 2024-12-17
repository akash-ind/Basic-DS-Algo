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



class FloydWarshalAlgo {
    vector<Edge> edges;

public:

    FloydWarshalAlgo(vector<Edge> edges) {
        this->edges = edges;
    }


    vector<vector<int>> get_all_pairs_shortest_path(int vertex_size) {
        vector<vector<int>> dist(vertex_size, vector<int>(vertex_size, INT_MAX));

        for(Edge e: edges) {
            dist[e.from][e.to] = e.weight;
        }

        for(int i = 0; i< vertex_size; i++) {
            dist[i][i] = 0;
        }

        for(int k = 0; k< vertex_size; k++) {
            
            for(int i = 0; i<vertex_size; i++) {
                
                for(int j = 0; j<vertex_size; j++) {
                    
                    if(dist[i][k] < INT_MAX && dist[k][j] < INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }

            }
        }

        return dist;

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
    auto g = create_graph(); // ideally should be able to return vertex size too

    auto floyd_warshal_algo = FloydWarshalAlgo(g);


    int vertex_size = 5;

    auto dist = floyd_warshal_algo.get_all_pairs_shortest_path(vertex_size);

    for(int i = 0; i< vertex_size; i++) {
        for(int j = 0; j< vertex_size; j++) {
            cout<<i<<" -> "<<j<<" = "<<dist[i][j]<<endl;
        }
    }
    return 1;

}