// Problem Link: https://leetcode.com/problems/robot-room-cleaner/

int row[4] = {1, 0, -1, 0};
int col[4] = {0, 1, 0, -1};

class Solution {
    void clean(Robot& robot, int direction, int x, int y, set<pair<int, int>> &visited)
    {
        robot.clean();
        visited.insert(make_pair(x, y));
        for(int i=direction; i<direction+4; i++)
        {
            int new_x = x+row[i%4], new_y = y+col[i%4];
            if(visited.find(make_pair(new_x, new_y))==visited.end() && robot.move())
                clean(robot, i%4, new_x, new_y, visited);
            robot.turnRight();

        }
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
        return;
    }
public:
    void cleanRoom(Robot& robot) {
        set<pair<int, int>> visited;
        clean(robot, 0, 0, 0, visited);
        return;
    }
};
