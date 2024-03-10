#include <bits/stdc++.h>

using namespace std;

pair<int, int> west_wall[10000];
pair<int, int> east_wall[10000];
pair<int, int> north_wall[10000];
pair<int, int> south_wall[10000];
int w = 0, e = 0, n = 0, s = 0;
string direct_mouse[10];
string wall_l, wall_r, wall_f;

void mouse_way(int d){
    direct_mouse[1] = "n";
    direct_mouse[2] = "e";
    direct_mouse[3] = "s";
    direct_mouse[4] = "w";
    if(d < 1)
        d = 4;
    else if(d > 4)
        d = d % 4;
    if(direct_mouse[d] == "n")
    {
        wall_f = "s";
        wall_l = "e";
        wall_r = "w";
    }
    else if(direct_mouse[d] == "e"){
        wall_f = "w";
        wall_l = "s";
        wall_r = "n";
    }
    else if(direct_mouse[d] == "s"){
        wall_f = "n";
        wall_l = "w";
        wall_r = "e";
    }
    else if(direct_mouse[d] == "w"){
        wall_f = "e";
        wall_l = "n";
        wall_r = "s";
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
    else if(direct == "s"){
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