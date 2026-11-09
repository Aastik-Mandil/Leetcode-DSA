typedef pair<char, int> P;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> v(26, 0);
        for(char &ch: s){
            v[ch-'a']++;
        }

        priority_queue<P, vector<P>> pq;
        for(int i=0; i<26; i++){
            if(v[i] == 0){
                continue;
            }
            pq.push({i+'a', v[i]});
        }

        P p = {'#', 0};
        string ans="";
        while(pq.size() > 0){
            char ch = pq.top().first;
            int cnt = pq.top().second;
            pq.pop();

            if(p.second > 0){
                ans.push_back(ch);
                pq.push(p);
                if(cnt-1 > 0){
                    pq.push({ch, cnt-1});
                }
                p = {'#', 0};
            }
            else{
                for(int i=0; i<repeatLimit && i<cnt; i++){
                    ans.push_back(ch);
                }
                if(cnt > repeatLimit){
                    p = {ch, cnt-repeatLimit};
                    cout<<ch<<" line 45 "<<cnt-repeatLimit<<endl;
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/construct-string-with-repeat-limit/description/
