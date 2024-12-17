#include<iostream>
#include <vector>

using namespace std;


class Cycles {
    vector<bool> marked;
    vector<vector<int>> g; // undirected graph

    public:

    Cycles(vector<vector<int>> g)  {
        this->g = g;
        marked = *new vector<bool>(g.size());
    }

    // int get_cycle_vertex(int st, int p) {

    //     marked[st] = true;
    //     for(int v: g[st]) {
    //         if (v == p) {
    //             continue;
    //         }
    //         if (marked[v]) {
    //             return v;
    //         }
    //     }

    // }

    // static bool print_cycles(vector<vector<int>> & g) { // adjacency list


    //     return true;
    // }

    bool is_cycle(int st, int p) {
        
        marked[st] = true;

        bool cycle = false;

        for(int v: g[st]) {
            if (v == p) {
                continue;
            }

            if (marked[v]) {
                return true;
            }
            else{
                cycle = cycle || this->is_cycle(v, st);
            }
        }

        return cycle;

    }

    bool is_cycle() {

        return is_cycle(0, -1);
    }



};



vector<vector<int>> create_graph() {
    vector<vector<int>> res(5, vector<int>());

    res[0].push_back(1);
    res[1].push_back(2);
    res[2].push_back(3);
    // res[3].push_back(1);
    res[3].push_back(4);
    return res;
}



int main() {

    auto g = create_graph();
    Cycles cycles = Cycles(g);
    cout<< cycles.is_cycle()<<endl;


    return 0;
}