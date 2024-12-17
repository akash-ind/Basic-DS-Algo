//https://leetcode.com/discuss/interview-question/4807845/Microsoft-Interview - 1

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
#include <fstream>

using namespace std;


int get_lines(string filepath) {
    fstream in(filepath, ios::in);
    if(!in.is_open()) {
        return 0;
    }
    string line;
    int count = 0;
    while(getline(in, line)) {
        count++;
    }
    in.close();
    return count;
}

string sort_line(fstream &in, int line_no) {
    string s;

    for(int i = 0; i<line_no; i++) {
        getline(in, s);
    }

    vector<int> nums;
    string temp;
    for(int i = 0; i<s.size(); i++) {
        if(s[i] == ' ') {
            nums.push_back(stoi(temp));
            temp.clear();
        }
        else {
            temp.push_back(s[i]);
        }
    }

    if(!temp.empty()){
        nums.push_back(stoi(temp));
    }

    sort(nums.begin(), nums.end());

    string res;
    for(int num: nums) {
        string temp = to_string(num);
        res.append(temp);
        res.push_back(' ');
    }

    if(res != "") {
        res.pop_back();
    }

    return res;

}

void readfile(string file) {
    fstream in(file, ios::in);
    string s;
    in >> s;
    int iter = 0;
    while(s.length()  && iter < 18)  {
        cout<<s<<" ";
        s.clear();
        in>>s;   
        iter++;
    }
    
}

string merge_files(string file_a, string file_b) {
    string out_file_name = "merged"+file_a+file_b;
    fstream out(out_file_name, ios::out);

    fstream in_a;
    in_a.open(file_a, ios::in);
    fstream in_b;
    in_b.open(file_b, ios::in);
    string word_a = "", word_b = "";
    in_a >> word_a;
    in_b >> word_b;

    while(word_a.length() || word_b.length()) {
        int a = INT_MAX, b = INT_MAX; // Assuming int max won't be in file;
        if(word_a.length()) {
            a = stoi(word_a);
        }

        if(word_b.length()) {
            b = stoi(word_b);
        }

        cout<<word_a<<" "<<word_b<<endl;

        if(a < b) {
            out<<to_string(a)<<" ";
            word_a.clear();
            in_a >> word_a;
        }
        else {
            out<<to_string(b)<<" ";
            word_b.clear();
            in_b >> word_b;
        }
    }

    in_a.close();
    in_b.close();
    out.close();

    return out_file_name;
}

string sort_file(string filename, int start, int end) {
    if(start == end) { // only one line
        fstream out("temp" + to_string(start), ios::out);
        fstream in(filename, ios::in);

        string res = sort_line(in, start);
        out<<res;
        in.close();
        out.close();
        return "temp" + to_string(start);
    }


    int mid = start + (end - start)/2;

    string file_a = sort_file(filename, start, mid);
    string file_b = sort_file(filename, mid+1, end);

    return merge_files(file_a, file_b);
}


string solve(string filepath) {

    int lines = get_lines(filepath);
    cout<<"lines "<<lines<<endl;
    return sort_file(filepath, 1, lines);
}


int main() {
    string input = "/Users/pfm/Projects/cpp/microsoft/file.txt";
    // readfile(input);

    auto res = solve(input);
    cout<<res<<endl;

    // output here

}