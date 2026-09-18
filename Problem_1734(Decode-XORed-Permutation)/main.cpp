class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size()+1;
        unordered_map<int, int> mp;
        for(int i=2; i<=n; i++){
            mp[1^i] = 1;
        }

        vector<int> ans(n);
        int idx = -1;
        if(mp[encoded[0] ^ 1] == 1){
            idx = 0;
            ans[idx] = 1;
            bool flag = true;
            for(int i=idx+1; i<n; i++){
                ans[i] = ans[i-1] ^ encoded[i-1];
                if(ans[i] > n || ans[i] <= 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return ans;
            }
        }

        for(int j=1; j<encoded.size(); j++){
            if(mp[encoded[j] ^ 1] == 1 && mp[encoded[j-1] ^ 1] == 1){
                idx = j;
                bool flag = true;
                ans[idx] = 1;
                for(int i=idx-1; i>=0; i--){
                    ans[i] = ans[i+1] ^ encoded[i];
                    if(ans[i] > n || ans[i] <= 0){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    for(int i=idx+1; i<n; i++){
                        ans[i] = ans[i-1] ^ encoded[i-1];
                        if(ans[i] > n || ans[i] <= 0){
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag){
                    return ans;
                }
            }
        }

        idx = n-1;
        ans[idx] = 1;
        for(int i=idx-1; i>=0; i--){
            ans[i] = ans[i+1] ^ encoded[i];
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/decode-xored-permutation/description/
