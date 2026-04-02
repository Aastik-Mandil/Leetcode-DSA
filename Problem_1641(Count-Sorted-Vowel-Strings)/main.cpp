class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> vow(5, 1);
        for(int i=2;i<=n;i++){
            vow[1]+=vow[0];
            vow[2]+=vow[1];
            vow[3]+=vow[2];
            vow[4]+=vow[3];
        }
        return vow[0]+vow[1]+vow[2]+vow[3]+vow[4];
    }
};
// PROBLEM:- https://leetcode.com/problems/count-sorted-vowel-strings/
// a:1, e:1. i:1, o:1, u:1 = 5
// a:1, e:2, i:3, o:4, u:5 = 15
// a:1, e:3, i:6, o:10, u:15 = 35
// a:1, e:4, i:10. o:20, u:35 = 70
// a:1, e:5, i:15, o:35, u:70 = 126
// a:1, e:6, i:21, o:56, u:126 = 210
// a:1, e:7/1, i:7*8/2*1, o: 7*8*9/3*2*1, u:7*8*9*10/4*3*2*1
