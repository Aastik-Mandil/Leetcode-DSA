typedef pair<int, char> P;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26, 0);
        for(char &ch: word){
            v[ch-'a']++;
        }

        priority_queue<P, vector<P>> pq;
        for(int i=0; i<26; i++){
            if(v[i] == 0){
                continue;
            }
            pq.push({v[i], i+'a'});
        }

        int cnt = 0, val = 1;
        int ans = 0;
        while(pq.size() > 0){
            cnt++;
            if(cnt == 9){
                cnt = 1;
                val++;
            }
            ans += (val * pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/
