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

class Trie {

    bool end = false;
    Trie *next[26];
    // int max_dist = 0;

    public:

    Trie() {
        for(int i = 0; i<26; i++) {
            this->next[i] = nullptr;
        }
    }

    // void set_max_dist(int dist) {
    //     this->max_dist = dist;
    // }

    bool add_word(Trie *root, string &s, int index) {


        if(index == s.size()) {
            root->end = true;
            return true;
        }

        if(root->next[s[index] - 'a'] == nullptr) {
            root->next[s[index] - 'a'] = new Trie();    
        }

        return add_word(root->next[s[index] - 'a'], s, index+1);
    }

    bool add_word(string &s) {
        for(int index = 0; index< s.size(); index++) {
            if(s[index] - 'a' >= 26 || s[index] - 'a' < 0) {
                return false;
            }
        }
        return add_word(this, s, 0);
    }

    bool is_present(Trie* root, const string &s, int index) {
        if(index == s.size()) {
            return root->end;
        }

        if(root->next[s[index] - 'a'] == nullptr) {
            return false;
        }

        return is_present(root->next[s[index] - 'a'], s, index +1);
    }

    bool is_present(const string &s) {
        return is_present(this, s, 0);
    }

    void edit_dist(Trie *root, const string &s, int cur_dist, int &max_dist, int index, string &temp, vector<string> &res) {

        if(root->end == true) {
            int dist = cur_dist + s.size() - index;

            if(dist <= max_dist) {
                res.push_back(temp);
            }
        }

        if (index == s.size() || cur_dist > max_dist) {
            return ;
        }

        for(int i = 0; i<26; i++) {
            if(root->next[i] != nullptr && cur_dist + (s[index] -'a' != i) <= max_dist) {
                temp.push_back('a'+i);
                edit_dist(root->next[i], s, cur_dist+(s[index] - 'a' != i), max_dist, index+1, temp, res);
                temp.pop_back();
            }
        }
    }

    vector<string> edit_dist(const string &s, int dist) {
        string temp = "";
        vector<string> res;
        edit_dist(this, s, 0, dist, 0, temp, res);
        return res;
    }

};

class SpellChecker {

    vector<string> words;
    Trie *root = nullptr;

public:
    SpellChecker(vector<string> & words) {
        this->words = words; // Use copy constructor
        this->root = new Trie();
        init();
    }

    bool init() {
        for(string word: words) {
            root->add_word(word);
        }

        return true;
    }

    bool is_correct_spelling(const string &word) {
        return root->is_present(word);
    }

    vector<string> suggest_words(const string &word) {
        return root->edit_dist(word, 2);
    }

};



int main() {
    vector<string> words = {
        "akash", "hey", "hello", "welcome", "heo", "hoo", "mey", "tey"
    };
    // output here

    SpellChecker s(words);

    cout<<s.is_correct_spelling("hello")<<endl;
    cout<<s.is_correct_spelling("akash")<<endl;

    auto res = s.suggest_words("hel");
    for(string s: res) {
        cout<<s<<" ";
    }

    return 0;
}