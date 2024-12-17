// https://leetcode.com/discuss/interview-question/859126/Codesignal-Problem-maxKoccurences

#include<iostream>
#include <algorithm>
#include<vector>
#include <cmath>

using namespace std;
long long prime = 31;
int mod = 1e9+7;


vector<long long> get_hash(string &s) {


    vector<long long> hash;

    hash.push_back(0);

    long long cur_power = 1;

    for(int i = 0; i< s.size(); i++) {

        long long h = (hash.back() + (s[i] - 'a' + 1)*cur_power)%mod;
        cur_power *= prime;
        cur_power = cur_power%mod;
        hash.push_back(h);

    }

    return hash;

}


vector<int> max_occurent(string &seq, vector<string> &words) { // Wrong

    vector<long long>seq_hash = get_hash(seq);

    vector<vector<long long>> word_hash;

    for(auto word: words) {
        word_hash.push_back(get_hash(word));
    }


    vector<int> res;


    for(int i = 0; i<words.size(); i++) { // solve using a better algo
        auto hash = word_hash[i].back();
        int ans = 0;

        for(int j = 0; j< seq.size(); j++) {
            
            auto cur_hash = (seq_hash[j+words[i].size()] - seq_hash[j] + mod) %mod;

            auto modified_hash = (hash*(long long)pow(prime, j))%mod;

            if(modified_hash == cur_hash) {
                ans++;
            }
        }

        res.push_back(ans);
    }

    return res;
}

int main() {
    string seq = "ababcbabc";
    vector<string> words = {"ab", "babc", "bca"};
    auto res = max_occurent(seq, words);
    for(int i: res) {
        cout<<i<<" ";
    }

    cout<<endl;

    return 0;
}