// https://leetcode.com/discuss/interview-question/4359045/Salesforce-Hackerrank-Questions-OA
#include<iostream>
#include<algorithm>
#include <vector>


using namespace std;


bool cmp(const string &s1, const string &s2) {
    int n1 = s1.size(), n2 = s2.size();
    for(int i = 0; i<min(n1, n2); i++) {
        if(s1[i] < s2[i]) {
            return true;
        }
        else if(s1[i] > s2[i]) {
            return false;
        }
    }
    return n1 < n2;
}

bool is_substring(string &s, string &substring) {
    if(s.size() < substring.size()) {
        return false;
    }
    int j = 0;

    for(int i = 0; i< s.size(); i++) {
        if(j == substring.size()) {
            return true;
        }

        if(s[i] == substring[j]) {
            j++;
        }
    }
    return j == substring.size();

}

string getValidWord(string &s, vector<string> & dictionary) {
    sort(dictionary.begin(), dictionary.end(), cmp);

    for(string &d: dictionary) {
        if(is_substring(s, d)) {
            return d;
        }
    }
    return "";
}


int main() {

    string s = "hgferyjkllkop";
    vector<string> dict = {
        "coffee", "coding", "happy", "hello", "hop"
    };
    cout<<getValidWord(s, dict)<<endl;
    return 0;
}