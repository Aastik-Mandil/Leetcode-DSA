class Solution {
    bool canEat(vector<int> &piles, int num, int &h){
        long long count = 0;
        for(int &pile: piles){
            count += (pile / num);
            if(pile%num > 0){
                count++;
            }
        }
        return count <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int n = piles.size();
        int st = 1, ed = piles[n-1];
        int ans;
        while(st <= ed){
            int mid = st + ((ed-st)/2);
            if(canEat(piles, mid, h)){
                ans = mid;
                ed = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/koko-eating-bananas/description
