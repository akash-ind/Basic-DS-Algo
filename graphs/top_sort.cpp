#include<iostream>
#include <vector>
#include<stack>

using namespace std;


vector<vector<int>> create_graph() {
    vector<vector<int>> res(5, vector<int>());

    res[0].push_back(1);
    res[1].push_back(2);
    res[2].push_back(3);
    // res[3].push_back(1);
    res[3].push_back(4);
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

    bool print_topsort() {
        compute_reverse_topsort(0);
        vector<int> res;
        while(!topsort_stack.empty()) {
            res.push_back(topsort_stack.top());
            topsort_stack.pop();
        }

        for(int v: res) {
            cout<<v<<" ";
        }

        cout<<endl;

        return true;
    }

};

int main() {

    auto g = create_graph();

    auto topsort = TopologicalSort(g);

    topsort.print_topsort();
    return 1;
}