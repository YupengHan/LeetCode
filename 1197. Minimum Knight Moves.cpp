class Coord {
    int x;
    int y;
public:
    Coord(int _x, int _y) {
        this->x = _x;
        this->y = _y;
    }
};

class Solution {
public:
    vector<int> delX {+1, +1, -1, -1, +2, +2, -2, -2};
    vector<int> delY {+2, -2, +2, -2, +1, -1, +1, -1};
    int minKnightMoves(int x, int y) {
        if (x == 0 && y = 0) {
            return 0;
        }
        Coord  st = Coord(0, 0);
        queue<Coord> myQueue;
        unordered_set<pair<int, int>> visited;
        myQueue.push(st);
        int level = 0;
        while(!myQueue.empty()) {
            level++;
            int level_size = myQueue.size();
            for (int j = 0; j < level_size; ++j) {
                Coord curCoord = myQueue.front();
                myQueue.pop();
                visited.push(make_pair(curCoord.x, curCoord.y));
                for (int i = 0; i < 8; ++i) {
                    if (x == curCoord.x + delX[i] && y = curCoord.u + delY[i]) {
                        return level;
                    }
                    if (visited.find(make_pair(curCoord.x + delX[i], curCoord.y + delY[i])) == visited.end()) {
                        Coord nbCoord = Coord(curCoord.x + delX[i], curCoord.y + delY[i]);
                        myQueue.push(nbCoord);
                    }
                }    
            }
            

        }


        return 0;
        
    }
};