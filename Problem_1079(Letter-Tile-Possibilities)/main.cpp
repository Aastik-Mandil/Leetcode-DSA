class Solution {
    vector<string> st;
    int factorial(int n){
        if(n==1){
            return 1;
        }
        return n * factorial(n-1);
    }
    int perm(string z){
        unordered_map<char,int> mp;
        for(char &ch: z){
            mp[ch]++;
        }
        int ans = factorial(z.size());
        for(auto itr: mp){
            ans/=factorial(itr.second);
        }
        // cout<<z<<endl;
        // cout<<ans<<endl;
        return ans;
    }
    void solve(string &tiles, int idx, string z){
        if(z.size()>0){
            st.push_back(z);
        }
        if(idx==tiles.size()){
            return;
        }
        unordered_set<char> st;
        for(int i=idx;i<tiles.size();i++){
            if(st.find(tiles[i]) == st.end()){
                st.insert(tiles[i]);
                z.push_back(tiles[i]);
                solve(tiles, i+1, z);
                z.pop_back();
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());

        string z = "";
        solve(tiles, 0, z);

        int res = 0;
        for(int i=0;i<st.size();i++){
            res+=perm(st[i]);
        }
        return res;
    }
};
// PROBLEM:- https://leetcode.com/problems/letter-tile-possibilities/description/
