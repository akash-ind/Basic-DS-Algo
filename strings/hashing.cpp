#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


class HashingAlgo {
    string s;
    vector<long long> p_pow;

    int hash_prime = 31;
    int mod = 1e9;

public:

    HashingAlgo(string s) {
        this->s = s;
        compute_p_pow(s.size());
    }

    bool compute_p_pow(int size) {
        p_pow.resize(size, 0);

        p_pow[0] = 1;

        for(int i = 1; i < size; i++) {
            p_pow[i] = (p_pow[i-1] * hash_prime)%mod;
        }

        return true;
    }

    vector<long long> compute_hash() {
        
        vector<long long> hash;
        hash.push_back(0);

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            hash.push_back((hash.back() + (c - 'a' + 1)*p_pow[i])%mod);
        }

        return hash;
    }


    int get_unique_substring_count() {
        auto hash = compute_hash();
        unordered_set<int> mp;
        for(int l = 1; l <= s.size(); l ++) {
            for(int i = 0; i<=s.size() - l; i++) {
                long long hash_val = (hash[i + l] - hash[i] + mod) % mod;
                hash_val = (hash_val * p_pow[s.size() - i - 1]) % mod;
                mp.insert(hash_val);
            }
        }

        return mp.size();
    }

};

int main() {
    string s = "krishakash";
    auto hash_algo = HashingAlgo(s);

    cout<<hash_algo.get_unique_substring_count()<<endl;

    return 1;
}