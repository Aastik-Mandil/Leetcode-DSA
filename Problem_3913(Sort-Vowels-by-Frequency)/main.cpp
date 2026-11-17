typedef pair<int, pair<int, char>> P;

class Solution {
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    string sortVowels(string s) {
        // store the freq and first index for vowel chars
        vector<int> v(26, 0);
        vector<int> index(26, -1);
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(isVowel(ch)){
                v[ch-'a']++;
                if(v[ch-'a'] == 1){
                    index[ch-'a'] = i;
                }
            }
        }

        // store into list
        vector<P> pq; // {freq_count, {idx, char}}
        for(int i=0; i<26; i++){
            if(v[i] == 0){
                continue;
            }
            pq.push_back({v[i], {index[i], i+'a'}});
        }

        // sort on the basis of freq_count, idx
        sort(pq.begin(), pq.end(), [](P &a, P &b){
            if(a.first == b.first){
                return a.second.first < b.second.first;
            }
            return a.first > b.first;
        });

        string ans = "";
        int idx = 0;
        for(char &c: s){
            if(isVowel(c)){
                // get current idx char and count
                int cnt = pq[idx].first;
                char ch = pq[idx].second.second;
                ans.push_back(ch);

                // desc the count
                pq[idx].first--;

                // inc the idx if count is 0
                if(pq[idx].first == 0){
                    idx++;
                }
            }
            else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/sort-vowels-by-frequency/description/
