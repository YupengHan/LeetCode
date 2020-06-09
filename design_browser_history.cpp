class BrowserHistory {
private:
    string logs[5000];
    int top, cur;
public:
    BrowserHistory(string homepage) {
        top = 0;
        cur = 0;
        logs[0] = homepage;
    }
    
    void visit(string url) {
        top = ++cur;
        logs[top] = url;
    }
    
    string back(int steps) {
        cur = max(0, cur-steps);
        return logs[cur];
    }
    
    string forward(int steps) {
        cur = min(top, cur+steps);
        return logs[cur];
    }
};