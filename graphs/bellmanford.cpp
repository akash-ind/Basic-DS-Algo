#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <set>

using namespace std;

class Edge {
    
public:
    int from, to, weight;
    Edge(int from, int to, int weight) {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};


class BellmanFord {
    vector<vector<Edge>> g;

public:
    BellmanFord(vector<vector<Edge>> g) {
        this->g = g;
    }

    vector<Edge> get_edge_list() {
        int g_size = g.size();
        vector<Edge> res;
        for(int i = 0; i < g_size; i++) {
            for (auto e: g[i]) {
                res.push_back(e);
            }
        }

        return res;
    }

    bool print_cycle(vector<int> parent, int last_relaxed) {
        int g_size = g.size();

        int cycle_head = last_relaxed;
        for(int i = 0; i<g_size; i++) {
            cycle_head = parent[cycle_head]; 
            /* 
            Used to - reach the actual head as the graph might be
            a - b
            |   |
            c - d - e 
            and the last_relaxed can be e
            */
        }

        int temp = cycle_head;
        vector<int> path;

        for(; ;) {
            path.push_back(temp);
            if(path.size() > 1  && temp == cycle_head) {
                break;
            }
            temp = parent[temp];
        }
        reverse(path.begin(), path.end());
        for(int v: path) {
            cout<< v << "->";
        }
        cout<<endl;
        return true;
    }


    vector<int> get_minimum_path_single_source(int source) {
        int g_size = g.size();

        vector<int> dist(g_size, INT_MAX);
        
        dist[source] = 0;

        auto edges = get_edge_list();


        vector<int> parent(g_size, -1);
        int last_relaxed;

        for(int i = 0; i<g_size; i++) { 
            last_relaxed = -1;
            for(Edge e: edges) {
                if(dist[e.from] != INT_MAX) {
                    if(dist[e.to] > dist[e.from] + e.weight) {
                        dist[e.to] = dist[e.from] + e.weight;
                        last_relaxed = e.to;
                        parent[e.to] = e.from;
                    }
                }
            }
        }

        if(last_relaxed != -1) {
            cout<<"Cycle exists"<<endl;
            print_cycle(parent, last_relaxed);
        }
        
        return dist;

    }

    vector<int> get_minimum_path_single_source_spfa(int source) {
        int g_size = g.size();

        vector<int> dist(g_size, INT_MAX);
        vector<bool> in_queue(g_size, false);
        vector<int> relaxed_count(g_size, 0);
        queue<int> q;
        dist[source] = 0;
        in_queue[source] = true;
        relaxed_count[source] = 1;
        q.push(source);
        int cycle_vertex = -1;
        vector<int> parent(g_size, -1);
        while (!q.empty())
        {
            int v = q.front();
            in_queue[v] = false;
            q.pop();

            for(Edge e: g[v]) {
                if(dist[e.to] > dist[v] + e.weight) {
                    dist[e.to] = dist[v] + e.weight;
                    parent[e.to] = e.from;
                    if(!in_queue[e.to]) {
                        q.push(e.to);
                    }
                    in_queue[e.to] = true;
                    relaxed_count[e.to]++;
                    if(relaxed_count[e.to] >= g_size) {
                        cycle_vertex = e.to;
                        break;
                    }
                }
            }
            if(cycle_vertex != -1) {
                break;
            }
        }

        if (cycle_vertex != -1) {
            cout<<"Cycle exists"<<endl;
            print_cycle(parent, cycle_vertex);
        }
        return dist;
    }

};




vector<vector<Edge>> create_graph() {
    vector<vector<Edge>> res(5, vector<Edge>());

    res[0].push_back(Edge(0, 1, 4));
    res[1].push_back(Edge(1, 0, -3));
    res[1].push_back(Edge(1, 2, 5));
    res[2].push_back(Edge(2, 1, 5));
    res[2].push_back(Edge(2, 3, -9));
    res[3].push_back(Edge(3, 2, 9));
    res[3].push_back(Edge(3, 4, 8));
    res[4].push_back(Edge(4, 3, 8));
    res[0].push_back(Edge(0, 3, 2));
    // res[3].push_back(Edge(0, 3, 2));
    // res[1].push_back(Edge(1, 4, 3));
    // res[4].push_back(Edge(1, 4, 3));

    return res;
}


int main() {
    auto g = create_graph() ;
    auto bellman_ford = BellmanFord(g);

    auto dist = bellman_ford.get_minimum_path_single_source_spfa(0);

    for(int i = 0; i< g.size() ; i++) {
        cout<<i<<" "<<dist[i]<<endl;
    }

    return 1;
}