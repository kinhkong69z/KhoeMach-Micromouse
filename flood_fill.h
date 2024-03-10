#include <iostream>
#include <vector>
#include <queue>
#include "markwall.h"
using namespace std;


void bfs(vector<vector<int>>& maze, int x, int y){
    queue<pair<int, int>> q;
    int m = maze.size();
    int n = maze[0].size();
    int nx, ny;

    //base case
    if(check_wall(x, y - 1, "e") == false){
        maze[x][y - 1] = 1; q.push({x, y - 1});
    }
    if(check_wall(x - 1, y, "s") == false){
        maze[x - 1][y] = 1;q.push({x - 1, y});
    }
    if(check_wall(x - 1, y + 1, "s") == false){
        maze[x - 1][y + 1] = 1;q.push({x - 1, y + 1});
    }
    if(check_wall(x, y + 2, "w") == false){
        maze[x][y + 2] = 1;q.push({x, y + 2});
    }
    if(check_wall(x + 1, y + 2, "w") == false){
        maze[x + 1][y + 2] = 1;q.push({x + 1, y + 2});
    }
    if(check_wall(x + 2, y + 1, "n") == false){
        maze[x + 2][y + 1] = 1;q.push({x + 2, y + 1});
    }
    if(check_wall(x + 2, y, "n") == false){
        maze[x + 2][y] = 1;q.push({x + 2, y});
    }
    if(check_wall(x + 1, y - 1, "e") == false){
        maze[x + 1][y - 1] = 1;q.push({x + 1, y - 1});
    }
    
    while(q.empty() == false){
        nx = q.front().first;
        ny = q.front().second;
        q.pop();
        if(nx + 1 < m && maze[nx + 1][ny] == 0 && check_wall(nx + 1, ny, "s") == false){ // down
            q.push({nx + 1, ny});
            maze[nx + 1][ny] = maze[nx][ny] + 1;
        }
        if(nx - 1 >= 0 && maze[nx - 1][ny] == 0 && check_wall(nx - 1, ny, "n") == false){ // up
            q.push({nx - 1, ny});
            maze[nx - 1][ny] = maze[nx][ny] + 1;
        }
        if(ny + 1 < n && maze[nx][ny + 1] == 0 && check_wall(nx, ny + 1, "w") == false){ // right
            q.push({nx, ny + 1});
            maze[nx][ny + 1] = maze[nx][ny] + 1;
        }
        if(ny - 1 >= 0 && maze[nx][ny - 1] == 0 && check_wall(nx, ny - 1, "e") == false){ // left
            q.push({nx, ny - 1});
            maze[nx][ny - 1] = maze[nx][ny] + 1;
        }
        
    }maze[x][y] = maze[x + 1][y] = maze[x + 1][y + 1] = maze[x][y + 1] = 0;
}
