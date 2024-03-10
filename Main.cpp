#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "API.h"


using namespace std;

void log(const std::string& text) {
    cerr << text << endl;
}

pair<int, int> west_wall[100];
pair<int, int> east_wall[100];
pair<int, int> north_wall[100];
pair<int, int> south_wall[100];
int w = 0, e = 0, n = 0, s = 0;
string direct_mouse[10];
string wall_l, wall_r, wall_f;

void mouse_way(int d){
    
    direct_mouse[1] = "n";
    direct_mouse[2] = "e";
    direct_mouse[3] = "s";
    direct_mouse[4] = "w";
    
    if(d == 1)
    {
        wall_f = "n";
        wall_l = "w";
        wall_r = "e";
    }
    else if(d == 2){
        wall_f = "e";
        wall_l = "n";
        wall_r = "s";
    }
    else if(d == 3){
        wall_f = "s";
        wall_l = "e";
        wall_r = "w";
    }
    else if(d == 4){
        wall_f = "w";
        wall_l = "s";
        wall_r = "n";
    }
}
void mark_wall(int x, int y, string direct){
    if(direct == "w"){
        west_wall[w].first = x;
        west_wall[w].second = y;
        w++;
    }
    else if(direct == "e"){
        east_wall[e].first = x;
        east_wall[e].second = y;
        e++;
    }
    else if(direct == "n"){
        north_wall[n].first = x;
        north_wall[n].second = y;
        n++;
    }
    else if(direct == "s"){
        south_wall[s].first = x;
        south_wall[s].second = y;
        s++;
    }
}

bool check_wall(int x, int y, string direct){
    int c;
    if(direct == "w"){
        c = w;
    }
    else if(direct == "e"){
        c = e;
    }
    else if(direct == "n"){
        c = n;
    }
    else{
        c = s;
    }
    for(int i = 0; i < c; i++){
        if(direct == "w" && west_wall[i].first == x && west_wall[i].second == y){
            return true;
        }
        else if(direct == "e" && east_wall[i].first == x && east_wall[i].second == y){
            return true;
        }
        else if(direct == "n" && north_wall[i].first == x && north_wall[i].second == y){
            return true;
        }
        else if(direct == "s" && south_wall[i].first == x && south_wall[i].second == y){
            return true;
        }
    }
    return false;
}
void bfs(vector<vector<int>>& maze, int x, int y){
    queue<pair<int, int>> q;
    int m = maze.size();
    int n = maze[0].size();
    int nx, ny;

    //base case
    
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
    if(check_wall(x, y - 1, "e") == false){
        maze[x][y - 1] = 1; q.push({x, y - 1});
    }
    while(q.empty() == false){
        nx = q.front().first;
        ny = q.front().second;
        q.pop();
        if(nx + 1 < m && maze[nx + 1][ny] == 0 && check_wall(nx + 1, ny, "n") == false){ // down
            q.push({nx + 1, ny});
            maze[nx + 1][ny] = maze[nx][ny] + 1;
        }
        if(nx - 1 >= 0 && maze[nx - 1][ny] == 0 && check_wall(nx - 1, ny, "s") == false){ // up
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

int main(int argc, char* argv[]) {
    log("Running...");
    API::setColor(0, 0, 'G');
    API::setText(0, 0, "abc");
    int d = 1;
    vector<vector<int>> maze(16,vector<int>(16, 0));
    int mx = 15, my = 0;
    while (true) {
        if(d < 1)
            d = 4;
        else if(d > 4)
            d = 1;
        mouse_way(d);
        if(API::wallFront) mark_wall(mx, my, wall_f);
        if(API::wallLeft)  mark_wall(mx, my, wall_l);
        if(API::wallRight) mark_wall(mx, my, wall_r);
        bfs(maze, 7, 7);
        if(wall_f == "n"){
            if(maze[mx - 1][my] <= maze[mx][my] && mx - 1 >= 0 && check_wall(mx, my, "n") == false){
                API::moveForward();
                mx--;
            }
            /* else if(maze[mx][my + 1] <= maze[mx][my] && my < 16 && (check_wall(mx, my, "e"))){
                API::turnRight();
                d++;
            }
            else if(maze[mx][my - 1] <= maze[mx][my] && my - 1 >= 0 && check_wall(mx, my, "w")){
                API::turnLeft();
                d--;
            } */
        }
        /* else if(wall_f == "e"){
            if(maze[mx][my + 1] <= maze[mx][my] && my + 1 < 16 && (check_wall(mx, my, "e"))){
                API::moveForward();
                my++;
            }
            else if(maze[mx + 1][my] <= maze[mx][my] && mx + 1 < 16 && (check_wall(mx, my, "s")))
            {
                API::turnRight();
                d++;
            }
            else if(maze[mx - 1][my] <= maze[mx][my] && mx - 1 >= 0 && check_wall(mx, my, "n")){
                API::turnLeft();
                d--;
            }
        } */
        
    }
}
