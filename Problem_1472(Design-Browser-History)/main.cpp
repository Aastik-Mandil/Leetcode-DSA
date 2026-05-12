class BrowserHistory {
    stack<string> undo, redo;
public:
    BrowserHistory(string homepage) {
        undo.push(homepage);
    }
    
    void visit(string url) {
        undo.push(url);
        while(redo.size() > 0){
            redo.pop();
        }
    }
    
    string back(int steps) {
        for(int i=0; i<(steps) && undo.size()>1; i++){
            redo.push(undo.top());
            undo.pop();
        }
        if(undo.size() == 0){
            return "";
        }
        return undo.top();
    }
    
    string forward(int steps) {
        for(int i=0; i<(steps) && redo.size()>0; i++){
            undo.push(redo.top());
            redo.pop();
        }
        if(undo.size() == 0){
            return "";
        }
        return undo.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// PROBLEM:- https://leetcode.com/problems/design-browser-history/description/
