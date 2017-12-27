#include <iostream>
#include <queue>
#include <utility>
#include <climits>

using namespace std;
typedef long long ll;

int main(){
    queue<pair<ll,int> > candidates;
    ll n, m;
    cin >> n >> m;
    pair<ll,int> first(n,0);
    candidates.push(first);
    vector<bool> visited(10001,false);
    int min = INT_MAX;
    while(!candidates.empty()){
        pair<ll,int> front = candidates.front();
        if(front.first < m){
            if(front.first != 1 && !visited[front.first-1]){
                pair<ll,int> p1(front.first-1, front.second+1);
                visited[front.first-1] = true;
                candidates.push(p1);
            }
            if(front.first*2 < 10001 && !visited[front.first*2]){
                pair<ll,int> p2(front.first*2, front.second+1);
                visited[front.first*2] = true;
                candidates.push(p2);
            }
        }else{
            if(min > front.first + front.second - m){
                min = front.first + front.second - m;
            }
        } 
        candidates.pop();
    }
    cout << min << endl;
}
