// https://leetcode.com/discuss/interview-question/4434504/Google-or-Phone-Screen-or-Replace-files-with-directories-if-all-files-in-directory-are-specified

#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

class Directory {


public:
    string name;
    unordered_map<string, Directory *> children;
    bool marked;
    Directory(string name) {
        this->name = name;
        marked = false;
    }



};

bool mark_upwards(Directory *root) {
    if(root->children.size() == 0) {
        return root->marked;
    }

    bool can_mark = true;

    for(auto child: root ->children) {
        // cout<<"bef "<<child.first<<" "<<child.second->marked<<endl;
        mark_upwards(child.second);

        if(!child.second->marked) {
            can_mark = false;
        }
    }

    // cout<<root->name<<" "<<can_mark<<endl;
    return root -> marked = can_mark;

}



vector<string> solve(vector<string> &dir, vector<string> &subset) {

    auto root = new Directory("/");

    for(string &s: dir) {
        string temp = "";
        auto cur_dir = root;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '/') {
                if(cur_dir->children[temp] == nullptr) {
                    cur_dir->children[temp] = new Directory(temp);
                }

                cur_dir = cur_dir->children[temp];
                temp = "";
                continue;
            }
            temp.push_back(s[i]);
        }

        if(temp != "") {
            if(cur_dir ->children[temp] == nullptr) {
                cur_dir -> children[temp] = new Directory(temp);
            }

            cur_dir = cur_dir->children[temp];
        }
    }



    for(string &s: subset) {
        auto cur_dir = root;
        string temp = "";

        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '/') {
                cur_dir = cur_dir -> children[temp];
                temp = "";
                continue;
            }
            temp.push_back(s[i]);
        }

        if(temp != "") {
            cur_dir->children[temp]->marked = true;
        }
    }


    mark_upwards(root);

    set<string> ans;

    for(string &s: subset) {
        auto cur_root = root;
        string res = "";
        string temp = "";
        for(int i = 0; i<s.size(); i++) {
            res.push_back(s[i]);
            if(s[i] == '/') {
                cur_root = cur_root->children[temp];
                if(cur_root ->marked) {
                    res.pop_back();
                    break;
                }
                temp = "";
                continue;
            }
            temp.push_back(s[i]);
        }
        ans.insert(res);
    }
    vector<string> res;
    for(auto &s: ans) {
        res.push_back(s);
    }

    return res;

}


int main() {
    vector<string> dir = {"a/b/c/d.txt",
"a/b/c/e.txt",
"a/b/b.txt",
"a/b/e.txt",
"b/c/d.txt"};
    vector<string> subset = {
        "a/b/c/d.txt",
"a/b/c/e.txt",
"a/b/b.txt",
"b/c/d.txt"
    };

    auto res = solve(dir, subset);

    for(auto t: res) {
        cout<<t<<endl;
    }
    
    // output here

    return 0;

}