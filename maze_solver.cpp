#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROW = 10, COL = 10;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isValid(int x, int y, const vector<vector<int>> &maze, const vector<vector<bool>> &visited) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 0 && !visited[x][y]);
}

bool dfs(int x, int y, const vector<vector<int>> &maze, vector<vector<bool>> &visited, vector<pair<int,int>> &path) {
    if (x == ROW-1 && y == COL-1) {
        path.push_back({x, y});
        return true;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, maze, visited)) {
            if (dfs(nx, ny, maze, visited, path)) {
                path.push_back({x, y});
                return true;
            }
        }
    }
    return false;
}

void bfs(const vector<vector<int>> &maze) {
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
    vector<vector<pair<int, int>>> parent(ROW, vector<pair<int, int>>(COL, {-1, -1}));
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == ROW-1 && y == COL-1) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny, maze, visited)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    vector<pair<int,int>> path;
    int x = ROW-1, y = COL-1;
    while (x != -1 && y != -1) {
        path.push_back({x, y});
        tie(x, y) = parent[x][y];
    }

    if (path.back() != make_pair(0,0)) {
        cout << "❌ No path found via BFS\n";
        return;
    }

    cout << "✅ Shortest path (BFS):\n";
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
}

vector<vector<int>> generateRandomMaze() {
    vector<vector<int>> maze(ROW, vector<int>(COL));
    srand(time(0));

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            maze[i][j] = (rand() % 100 < 70) ? 0 : 1;  // 70% chance path, 30% wall
        }
    }
    maze[0][0] = 0;
    maze[ROW-1][COL-1] = 0;
    return maze;
}

void printMaze(const vector<vector<int>>& maze) {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            cout << (maze[i][j] == 0 ? "." : "#") << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> maze = generateRandomMaze();
    cout << "🧩 Generated Maze (0 = path, 1 = wall):\n";
    printMaze(maze);

    cout << "\nSolving maze using DFS...\n";
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
    vector<pair<int,int>> path;
    if (dfs(0, 0, maze, visited, path)) {
        cout << "✅ Path found (DFS):\n";
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            cout << "(" << it->first << "," << it->second << ") ";
        }
        cout << endl;
    } else {
        cout << "❌ No path found using DFS.\n";
    }

    cout << "\nSolving maze using BFS...\n";
    bfs(maze);

    return 0;
}
