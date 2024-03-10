#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/* void dfs(vector<vector<int>>& maze, int x, int y, int new_num) {
    int m = maze.size();
    int n = maze[0].size();
    // Kiểm tra xem có vượt quá giới hạn của ma trận hay không hoặc giá trị mới đã lớn hơn giá trị hiện tại
    if (x < 0 || x >= m || y < 0 || y >= n || (maze[x][y] != 0 && maze[x][y] <= new_num)) {
    return;
    }
    // Cập nhật giá trị mới
    maze[x][y] = new_num;
    // Tiếp tục lan truyền đệ quy
    dfs(maze, x + 1, y, new_num + 1);
    dfs(maze, x - 1, y, new_num + 1);
    dfs(maze, x, y + 1, new_num + 1);
    dfs(maze, x, y - 1, new_num + 1);
} */
/* void flood_fill(vector<vector<int>>& maze, int x, int y, int new_num) {
    dfs(maze, x, y, new_num);
} */
void bfs(vector<vector<int>>& maze, int x, int y){
    queue<pair<int, int>> q;
    int m = maze.size();
    int n = maze[0].size();
    int nx, ny;
    //base case
    maze[x][y - 1] = 1; maze[x - 1][y] = 1;
    q.push({x, y - 1});
    q.push({x - 1, y});

    maze[x - 1][y + 1] = 1; maze[x][y + 2] = 1;
    q.push({x - 1, y + 1});
    q.push({x, y + 2});

    maze[x + 1][y + 2] = 1; maze[x + 2][y + 1] = 1;
    q.push({x + 1, y + 2});
    q.push({x + 2, y + 1});

    maze[x + 2][y] = 1; maze[x + 1][y - 1] = 1;
    q.push({x + 2, y});
    q.push({x + 1, y - 1});
    
    while(q.empty() == false){
        nx = q.front().first;
        ny = q.front().second;
        q.pop();
        if(nx + 1 < m && maze[nx + 1][ny] == 0 && nx + 1 != x - 1){ // down
            q.push({nx + 1, ny});
            maze[nx + 1][ny] = maze[nx][ny] + 1;
        }
        if(nx - 1 >= 0 && maze[nx - 1][ny] == 0 && nx - 1 != x){ // up
            q.push({nx - 1, ny});
            maze[nx - 1][ny] = maze[nx][ny] + 1;
        }
        if(ny + 1 < n && maze[nx][ny + 1] == 0  && ny + 1 != y){ // right
            q.push({nx, ny + 1});
            maze[nx][ny + 1] = maze[nx][ny] + 1;
        }
        if(ny - 1 >= 0 && maze[nx][ny - 1] == 0  && ny - 1 != y + 1){ // left
            q.push({nx, ny - 1});
            maze[nx][ny - 1] = maze[nx][ny] + 1;
        }
        
    }
}


int main() {
    vector<vector<int>> maze(16, vector<int>(16, 0)); 
    //flood_fill(maze, 1, 1, 0);
    bfs(maze, 7, 7);
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
