typedef pair<int, string> P;

class Solution {
    string addAtOddIdx(string val, int n){
        string s = "";
        for(int i=0; i<val.size(); i++){
            if(i%2 == 0){
                s.push_back(val[i]);
            }
            else{
                int v = (val[i]-'0')+n;
                v %= 10;
                s.push_back(v+'0');
            }
        }
        return s;
    }
    string rotateRight(string val, int n){
        return val.substr(val.size()-n, n) + val.substr(0, val.size()-n);
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        b %= s.size();
        priority_queue<P, vector<P>, greater<P>> pq;
        
        string ans = s;

        unordered_map<string, bool> mp;
        pq.push({0, s});
        mp[s] = true;
        while(pq.size() > 0){
            int cnt = pq.top().first;
            string val = pq.top().second;
            if(ans > val){
                ans = val;
            }
            pq.pop();
            string s1 = addAtOddIdx(val, a);
            if(!mp[s1]){
                mp[s1] = true;
                pq.push({cnt+1, s1});
            }
            string s2 = rotateRight(val, b);
            if(!mp[s2]){
                mp[s2] = true;
                pq.push({cnt+1, s2});
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/
