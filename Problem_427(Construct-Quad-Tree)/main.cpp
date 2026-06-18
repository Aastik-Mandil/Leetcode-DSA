/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    vector<int> allSame(vector<vector<int>> &grid, int stR, int stC, int edR, int edC){
        int val = grid[stR][stC];
        for(int i=stR; i<edR; i++){
            for(int j=stC; j<edC; j++){
                if(grid[i][j] != val){
                    cout<<i<<" "<<j<<" "<<val<<endl;
                    return {0, 1};
                }
            }
        }
        return {1, val};
    }
    Node* solve(vector<vector<int>> &grid, int stR, int stC, int edR, int edC){
        if(stR >= edR || stC >= edC || stR>=grid.size() || stC>=grid[0].size() || edR<0 || edC<0){
            return NULL;
        }
        vector<int> v = allSame(grid, stR, stC, edR, edC);
        Node *node = new Node(v[1], v[0]);
        if(v[0] == 1){
            return node;
        }
        int midR = stR+((edR-stR)/2);
        int midC = stC+((edC-stC)/2);
        node->topLeft = solve(grid, stR, stC, midR, midC);
        node->topRight = solve(grid, stR, midC, midR, edC);
        node->bottomLeft = solve(grid, midR, stC, edR, midC);
        node->bottomRight = solve(grid, midR, midC, edR, edC);
        return node;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        return solve(grid, 0, 0, n, m);
    }
};
// PROBLEM:- https://leetcode.com/problems/construct-quad-tree/description
