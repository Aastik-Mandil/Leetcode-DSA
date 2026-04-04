class Solution {
public:
    bool isNbr(string s,string t){
        int diff=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                diff++;
            }
            if(diff>1){
                return false;
            }
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        // wordList.push_back(endWord);

        int n=wordList.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isNbr(wordList[i],wordList[j])){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }

        queue<pair<int,int>> q;
        vector<int> visited(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(beginWord == wordList[i]){
                q.push({i, 1});
                visited[i]=0;
                break;
            }
        }

        while(q.size()>0){
            int idx=q.front().first;
            int count=q.front().second;
            string u = wordList[idx];
            q.pop();
            for(int nbr: mp[idx]){
                string v=wordList[nbr];
                if(visited[nbr]>(count+1)){
                    q.push({nbr, count+1});
                    visited[nbr]=count+1;
                    if(v==endWord){
                        return count+1;
                    }
                }
            }
        }
        return 0;
    }
};
// PROBLEM:- https://leetcode.com/problems/word-ladder/
