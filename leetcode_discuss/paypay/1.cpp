//https://leetcode.com/discuss/interview-question/5055867/Pay2DC-or-OA-Round-or-SDE-2


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

pair<int, int> get_direction_coord(int dir) {
  if(dir == 0) {
    return {-1, -1};
  }
  if(dir == 1) {
    return {-1, 1};
  }
  if(dir == 2) {
    return {1, -1};
  }
  return {1, 1};
}


int get_max_diagonal_len(vector<vector<int>> & matrix, vector<vector<vector<int>>> &dp, int dir, int i, int j, int exp){
 
  auto [dx, dy] = get_direction_coord(dir); 

  if(i < 0 || j< 0 || i>= matrix.size() || j>= matrix[0].size() || matrix[i][j] != exp) {
    return 0;
  }
  
  if(dp[i][j][dir] != -1) {
    return dp[i][j][dir];
  }
  
  int cur_exp = exp == 2 ? 0 : 2;
  
  return dp[i][j][dir] = 1 + get_max_diagonal_len(matrix, dp, dir, i+dx, j+dy, cur_exp);
  
}

int get_max_diagonal_len(vector<vector<int>> & matrix) {
  int n = matrix.size(), m = matrix[0].size();

  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(4, -1)));
  
  
  int res = 0;
  
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<m; j++) {
      for(int dir = 0; dir < 4; dir++) {
        if(matrix[i][j] != 1) {
          break;
        } 
        
        auto [dx, dy] = get_direction_coord(dir);
        
        res = max(res, 1+get_max_diagonal_len(matrix, dp, dir, i+dx, j+dy, 2));
        
    
      }   
    }
  }
  
  return res;
  
}


int main() {
  
  vector<vector<int>> mat = {
    {2, 1, 2, 2, 1},
    {0, 2, 0, 2, 0},
    {0, 0, 0, 0, 0},
    {0, 2, 2, 2, 2},
    {2, 1, 2, 2, 1},
    {0, 2, 0, 0, 2}
  };
  cout<< get_max_diagonal_len(mat)<<endl;
  return 0;
}
