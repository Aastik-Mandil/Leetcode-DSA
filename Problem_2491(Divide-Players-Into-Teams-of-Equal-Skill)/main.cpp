class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int i = 0, j = skill.size() - 1;
        int val = skill[0] + skill.back();
        long long total = 0;
        while(i<j){
            if(skill[i] + skill[j] != val){
                return -1;
            }
            total += (skill[i] * skill[j]);
            i++;
            j--;
        }
        return total;
    }
};
// PROBLEM:- https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/
