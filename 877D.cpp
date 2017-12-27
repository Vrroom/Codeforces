#include <bits/stdc++.h>

using namespace std;

struct pos{
    int i,j,moves;
    pos(int r, int c){
        i = r;
        j = c;
        moves = 0;
    }
};

struct posetComp{
    bool operator()(const pos &p1, const pos &p2) const{
        if(p1.i > p2.i){
            return true;
        }else if(p1.i < p2.i){
            return false;
        }else{
            if(p1.j > p2.j){
                return true;
            }else{
                return false;
            }
        }
    }
};

int minimumMoves(vector <string> grid, int sX, int sY, int gX, int gY){
    if(sX == gX && sY == gY) return 0;
    set<pos,posetComp> S;
    queue<pos> q;
    pos start(sX,sY);
    S.insert(start);   
    q.push(start);
    while(!q.empty()){
        pos current = q.front();
        q.pop();
        if(current.i == gX && current.j == gY){
            return current.moves;
        }else{
            for(int ind = current.i+1;ind < grid.size() && grid[ind][current.j] != '#'; ind++){
                pos next(ind,current.j);
                if(S.count(next) == 0){
                    next.moves = current.moves+1;
                    q.push(next);
                    S.insert(next);
                }
            }
            for(int ind = current.i-1;ind >= 0 && grid[ind][current.j] != '#'; ind--){
                pos next(ind,current.j);
                if(S.count(next) == 0){
                    next.moves = current.moves+1;
                    q.push(next);
                    S.insert(next);
                }
            } 
            for(int ind = current.j+1;ind < grid[current.i].size() && grid[current.i][ind] != '#';ind++){
                pos next(current.i,ind);
                if(S.count(next) == 0){
                    next.moves = current.moves+1;
                    q.push(next);
                    S.insert(next);
                }
            }
            for(int ind = current.j-1;ind >= 0 && grid[current.i][ind] != '#'; ind++){
                pos next(current.i,ind);
                if(S.count(next) == 0){
                    next.moves = current.moves+1;
                    q.push(next);
                    S.insert(next);
                }
            }    
        } 
    }
    return -999;
}

int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
        cin >> grid[grid_i];
    }
    int sX,sY,gX,gY;
    cin >> sX >> sY >> gX >> gY;
    int result = minimumMoves(grid,sX-1,sY-1,gX-1,gY-1);
    cout << result << endl;
    return 0;
}

