class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        for(int i=n-2;i>=0;i-=2){
            reverse(board[i].begin(), board[i].end());
        }

        int idx = 1;
        map<int,int> mp;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(board[i][j] != -1){
                    mp[idx] = board[i][j];
                }
                idx++;
            }
        }

        queue<pair<int,int>> q;
        q.push({0, 1});
        vector<int> dist((n*n)+1, INT_MAX);
        dist[1] = 0;
        int ans = INT_MAX;
        while(q.size()>0){
            int step = q.front().first;
            int node = q.front().second;
            if(node == n*n){
                return step;
            }
            q.pop();
            for(int i=min(node+6, n*n); i>=(node+1); i--){
                int val = i;
                if(mp[val]>0){
                    val = mp[val];
                }
                if(dist[val] > step+1){
                    q.push({step+1, val});
                    dist[val] = step+1;
                }
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/snakes-and-ladders/description
