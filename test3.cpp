class Solution {
private:
    int ans = 0;
    bool isValid(pair<int, int> b, pair<int, int> a, vector<vector<bool>>& visited) {
        if (visited[b.first][b.second]) {
            return false;
        }

        int dist = abs(b.first - a.first) + abs(b.second - a.second);

        if (dist == 1) {
            // direct neighbor in same row/col
            return true;
        } else if (dist == 2) {
            if (a.first == b.first) {
                // horizontal move
                return visited[a.first][1];
            } else if (a.second == b.second) {
                // vertical move
                return visited[1][a.second];
            } else {
                // diagonal move
                return true;
            }
        } else if (dist == 3) {
            // this is a knight move -> all are valid
            return true;
        } else if (dist == 4) {
            // this is a long diagonal move
            return visited[1][1];
        }

        cout << dist << endl;
        return false;
    }



    void backtracking(pair<int, int> key, vector<vector<bool>>& visited, int visitedCount, int m, int n) {
        if (visitedCount > n) {
            return;
        }
        if (visitedCount >= m) {
            ans++;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (isValid({i, j}, key, visited)) {
                    visited[i][j] = true;
                    backtracking({i, j}, visited, visitedCount + 1, m, n);
                    visited[i][j] = false;
                }
            }
        }
    }

public:
    int numberOfPatterns(int m, int n) {
        vector<vector<bool>> visited = vector(3, vector(3, false));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                visited[i][j] = true;
                backtracking({i, j}, visited, 1, m, n);
                visited[i][j] = false;
            }
        }

        return ans;
    }
};
