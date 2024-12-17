//https://www.spoj.com/problems/SEQ/

#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

const int mod = 1e9;

vector<vector<long long>> get_t_matrix(vector<int> &c) {
    int k = c.size();

    vector<vector<long long>> res(k, vector<long long>(k, 0));

    for(int i = 0; i<k; i++) {
        if(i != k-1) {
            res[i][i+1] = 1;
            continue;
        }
        for(int j = 0; j<k; j++) {
            res[i][j] = c[k - j - 1];
        }
    }

    return res;
}

vector<vector<long long>> get_m_matrix(vector<int> &b) {
    int k = b.size();
    vector<vector<long long>> res(k, vector<long long>(1, 0));

    for(int i = 0; i<k; i++) {
        res[i][0] = b[i];
    }

    return res;

}

vector<vector<long long>> multiply_mat(vector<vector<long long>> & mat1, vector<vector<long long>> &mat2) {
    int n1 = mat1.size(), m1 = mat1[0].size(); // bug in case of empty matrix
    int n2 = mat2.size(), m2 = mat2[0].size();

    if(m1 != n2) {
        return {};
    }
    vector<vector<long long>> res(n1, vector<long long>(m2, 0));
    for(int i = 0; i< n1; i++) {
        for(int j = 0; j<m2; j++) {
            long long val = 0;
            for(int k = 0; k< n2; k++) {
                val += mat1[i][k] * mat2[k][j];
                val = val % mod;
            }
            res[i][j] = val;
        }
    }

    return res;

}

vector<vector<long long>> p_pow(vector<vector<long long>> &mat, int n) {
    if(n == 1) {
        return mat;
    }
    auto val = p_pow(mat, n/2);
    val = multiply_mat(val, val);
    if(n % 2) {
        
        return multiply_mat(val, mat);
    }

    return val;

}


bool solve() {
    int k;
    cin>>k;

    vector<int> b(k);
    vector<int> c(k);

    for(int i = 0; i< k; i++) {
        cin>>b[i];
    }
    for(int i = 0; i<k; i++) {
        cin>> c[i];
    }


    int n;
    cin>> n;


    if(n <= k) {
        cout<<b[n-1]<<endl;
        return true;
    }


    auto t_mat = get_t_matrix(c);
    auto m_mat = get_m_matrix(b);

    t_mat = p_pow(t_mat, n-1);

    auto res = multiply_mat(t_mat, m_mat);

    cout<<res[0][0] % mod<<endl;

    return true;

}


int main() {
    int t;
    cin>> t;
    while(t -- ) {
        solve();
    }

    return 0;
}