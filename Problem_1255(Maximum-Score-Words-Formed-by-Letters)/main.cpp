class Solution {
    bool canTake(string word, vector<int> &mp){
        vector<int> v1(26,0);
        for(char &c: word){
            v1[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(mp[i]<v1[i]){
                return false;
            }
        }
        return true;
    }
    int solveR(vector<string> &words, int idx, vector<int> &mp, vector<int> &score){
        if(idx == 0){
            return 0;
        }
        int take = 0;
        if(canTake(words[idx-1], mp)){
            int total=0;
            for(char &c: words[idx-1]){
                mp[c-'a']--;
                total+=score[c-'a'];
            }
            take = total + solveR(words, idx-1, mp, score);
            for(char &c: words[idx-1]){
                mp[c-'a']++;
            }
        }
        int notTake = solveR(words, idx-1, mp, score);
        return max(take, notTake);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> mp(26,0);
        for(char &ch: letters){
            mp[ch-'a']++;
        }

        return solveR(words, words.size(), mp, score);
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/
