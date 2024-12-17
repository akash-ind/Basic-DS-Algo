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



string solve(string &msg, int k) {

    string res = "";

    vector<string> words;

    string word = "";
    for(char c: msg) {
        if(c == ' ') {
            words.push_back(word);
            word = "";
        }
        else {
            word.push_back(c);
        }
    }
    if(word != "") {
        words.push_back(word);
    }

    int len = 0, final_words = 0;

    if(k == 3 || words[0].size() + 4 > k) {
        return "...";
    }

    res = words[0];


    for(int i = 1; i < words.size(); i++) {
        if(res.size() + words[i].size() + 1 > k) {
            if(res.size() + 4 > k) {
                while(res.back() != ' ') {
                    res.pop_back();
                }
                res.pop_back();
            }
            
            res += " ...";
            break;
        }
        res += " " + words[i];
    }

    return res;


}


int main() {
    string input = "difhjdf ncsdhsd cdsjbhcdh dbhd scicj";

    auto res = solve(input, 25);
    cout<<res<<endl;
    
    // output here

}