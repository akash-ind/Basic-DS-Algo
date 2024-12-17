#include<iostream>
#include <vector>
#include <stack>

using namespace std;


vector<vector<int>> create_graph() {
    vector<vector<int>> res(5, vector<int>());

    res[0].push_back(1);
    res[1].push_back(2);
    res[2].push_back(3);
    res[3].push_back(4);
    res[4].push_back(0);
    return res;
}

class TopologicalSort {

    vector<vector<int>> g;
    vector<bool> in_stack;
    vector<bool> marked;
    stack<int> topsort_stack;

public:

    TopologicalSort(vector<vector<int>> g) {
        this->g = g;

        in_stack.resize(g.size(), false);

        marked.resize(g.size(), false);
    }

    bool compute_reverse_topsort(int st) {
        marked[st] = true;

        for(int v: g[st]) {
            if(!marked[v]) {
                compute_reverse_topsort(v);
            }
        }

        topsort_stack.push(st);
        return true;
    }

    vector<int> get_topsort() {
        compute_reverse_topsort(0);
        vector<int> res;
        while(!topsort_stack.empty()) {
            res.push_back(topsort_stack.top());
            topsort_stack.pop();
        }

        return res;
    }

};



class StronglyConnectedComponents
{
private:
    vector<vector<int>> g;
    vector<bool> marked;
public:
    StronglyConnectedComponents(vector<vector<int>> g) {
        this->g = g;
        marked.resize(g.size(), false);
    }

    vector<vector<int>> get_reverse_graph() {
        vector<vector<int>> rev_g(g.size(), vector<int>());
        for(int i = 0; i<g.size(); i++) {
            for(int v: g[i]) {
                rev_g[v].push_back(i);
            }
        }

        return rev_g;

    }

    bool mark_dfs(vector<vector<int>> & rev_g, int st) {
        marked[st] = true;

        for(int v: rev_g[st]) {
            if(!marked[v]) {
                mark_dfs(rev_g, v);
            }
        }

        return true;
    }


    int get_scc_count() { // strongly connected component
        auto topsort = TopologicalSort(g).get_topsort();
        auto rev_g = get_reverse_graph();
        int scc_count = 0;
        for(int v: topsort) {
            if(!marked[v]) {
                scc_count++;
                mark_dfs(rev_g, v);
            }
        }

        return scc_count;
    }
};

int main() {

    auto g = create_graph();

    auto scc = StronglyConnectedComponents(g);
    cout<<scc.get_scc_count()<<endl;
}