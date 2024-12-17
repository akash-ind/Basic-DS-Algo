#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <set>

using namespace std;

class Edge {
    
public:
    int either, other, weight;
    Edge(int either, int other, int weight) {
        this->either = either;
        this->other = other;
        this->weight = weight;
    }

    int get_other(int v) {
        return either == v? other: either;
    }
};


class Dijkstra {

    vector<vector<Edge>> g;

public:
    Dijkstra(vector<vector<Edge>> g) {
        this->g = g;
    }


    vector<int> get_shortest_path(int source, int dest) {

        int g_size = g.size();

        vector<int> dist(g_size, INT_MAX);
        // try with marked
        dist[source] = 0;

        set<pair<int, int>> pq;
        pq.insert({0, source});
        vector<int> parent(g_size);
        parent[source] = source;

        while (!pq.empty())
        {
            auto [_, vertex] = *pq.begin();
            pq.erase(pq.begin());

            for(auto e: g[vertex]) {
                int to = e.get_other(vertex);
                if(dist[to] > dist[vertex] + e.weight) {
                    pq.erase({dist[to], to});
                    dist[to] = dist[vertex] +e.weight;
                    parent[to] = vertex;
                    pq.insert({dist[to], to});
                }
            }
        }

        if (dist[dest] == INT_MAX) {
            return {};
        }
        vector<int> path;
        int temp = dest;
        while(parent[temp] != temp) {
            path.push_back(temp);
            temp = parent[temp];
        }
        path.push_back(temp);
        reverse(path.begin(), path.end());

        return path;

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
    // res[3].push_back(Edge(0, 3, 2));
    // res[1].push_back(Edge(1, 4, 3));
    // res[4].push_back(Edge(1, 4, 3));

    return res;
}


int main() {
    auto g = create_graph() ;
    auto dijkstra = Dijkstra(g);

    auto path = dijkstra.get_shortest_path(0, 4);

    for(int v: path) {
        cout<<v<<"->";
    }

    return 1;
}