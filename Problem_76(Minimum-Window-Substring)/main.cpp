class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }

        if(s==t){
            return s;
        }

        vector<long long int> v1(256,0);
        for(char &ch: t){
            v1[ch]++;
        }

        int l=0,r=0;
        int stIdx=-1,minLen=INT_MAX;
        int cnt = 0;
        while(r<s.size()){
            if(v1[s[r]]>0){
                cnt++;
            }
            v1[s[r]]--;
            while(cnt == t.size()){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    stIdx = l;
                }
                v1[s[l]]++;
                if(v1[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(stIdx == -1){
            return "";
        }
        return s.substr(stIdx, minLen);
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-window-substring/description/
