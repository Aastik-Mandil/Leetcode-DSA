typedef pair<int, pair<int, char>> P;

// sort in the asc order of time
struct Comp{
    bool operator()(P &a, P &b){
        return a.first > b.first;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // store the frequency of each character
        vector<int> v(26, 0);
        for(int i=0; i<tasks.size(); i++){
            v[tasks[i]-'A']++;
        }

        // store into min-heap
        priority_queue<P, vector<P>, Comp> pq; // {nextTime, {count, character}}
        for(int i=0; i<26; i++){
            if(v[i] == 0){
                continue;
            }
            pq.push({0, {v[i], i+'A'}});
        }

        int last = 0;
        while(pq.size() > 0){
            int prev = pq.top().first;
            int cnt = pq.top().second.first;
            char ch = pq.top().second.second;
            pq.pop();

            // idle time for the CPU
            while(last < prev){
                last++;
            }
            last++;
            if(cnt-1 > 0){
                pq.push({prev + n + 1, {cnt - 1, ch}});
            }
        }
        return last;
    }
};
// PROBLEM:- https://leetcode.com/problems/task-scheduler/description/
