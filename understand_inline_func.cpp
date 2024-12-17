#include<bits/stdc++.h>
using namespace std;


int main() {

    vector<int> v = {1, 2, 3};

    sort(v.begin(), v.end(), [](const int &a, const int &b) {
        return a > b;
    });

    for_each(v.begin(), v.end(), [&](int i) {
        cout<<i<<" ";
    });

}