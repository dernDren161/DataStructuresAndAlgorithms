// Problem Link: https://leetcode.com/problems/robot-bounded-in-circle/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;// co-ordinates
        int direction = 0; // 0 - North, 1 - East, 2 - South, 3 - West
        for (auto instruction : instructions) {
            switch (instruction) {
                case 'G': {
                    switch (direction) {
                        case 0: {
                            y+= 1;
                            break;
                        }
                        case 1: {
                            x+=1;
                            break;
                        }
                        case 2: {
                            y-=1;
                            break;
                        }
                        case 3: {
                            x-=1;
                            break;
                        }
                    };
                    break;
                }
                case 'L': {
                  if(direction==0) {direction = 3; break;}
                   else{
                       direction--;
                       break;
                   }
                }
                case 'R': {
                  if(direction==3){direction = 0; break;}
                 else{
                     direction++;
                     break;
                 }
                }
            };
        }
        if ((x==0 && y==0) || (direction)) return true; // NOTE: If the final ending direction is North then it is going in an infinite loop, Weird logic
        return false;
    }
};
