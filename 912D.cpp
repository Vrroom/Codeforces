#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
#include <utility>
#include <set>
#include <vector>

using namespace std;

typedef pair<double,double> pair_d;

void BFS(double,double,double &a);
double pSquares(double,double);
double n,m,k,r;

struct queue_compare{
    bool operator()(const pair_d &p1, const pair_d &p2) const{
        return pSquares(p1.first,p1.second) < pSquares(p2.first,p2.second);
    }
} typedef pqc; 

struct set_compare{
    bool operator()(const pair_d &p1, const pair_d &p2) const{
        if(p1.first != p2.first){
            return p1.first < p2.first;
        }else{
            return p1.second < p2.second;
        }
    }
} typedef sc;

int main(){
    cin >> n >> m >> r >> k;
    double numer = 0;
    double denom = (n-r+1)*(m-r+1);
    BFS(floor((m+1)/2),floor((n+1)/2),numer);
    cout << setprecision(15) << (numer/denom) << endl;
}

double pSquares(double i, double j){
    double x, y;
    y = abs(min(j-1,r-1)+1 - (r - (min(n-j,r-1)))) + 1;
    x = abs(min(i-1,r-1)+1 - (r - (min(m-i,r-1)))) + 1;
    return x*y;
}

void BFS(double i, double j, double &numerator){
    priority_queue<pair_d,vector<pair_d>,pqc> pq;
    set<pair_d,sc> s; 
    pair_d p(i,j);
    pq.push(p);
    s.insert(p);
    for(int i = 0; i < k; i++){
        pair_d tp = pq.top();
        pq.pop();
        numerator += pSquares(tp.first, tp.second);
        pair_d left(tp.first,tp.second-1);
        pair_d right(tp.first,tp.second+1);
        pair_d above(tp.first-1,tp.second);
        pair_d bot(tp.first+1,tp.second);
        if(tp.second-1 >= 1 && s.find(left) == s.end()){
            s.insert(left);
            pq.push(left);
        }
        if(tp.first-1 >= 1 && s.find(above) == s.end()){
            s.insert(above);
            pq.push(above);
        }
        if(tp.first+1 <= m && s.find(bot) == s.end()){
            s.insert(bot);
            pq.push(bot);
        }
        if(tp.second+1 <= n && s.find(right) == s.end()){
            s.insert(right);
            pq.push(right);
        }
    }
}

