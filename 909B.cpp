#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void swap (int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

/* This algorithm is taken from https://www.iarcs.org.in/inoi/online-study-material/topics/permutations.php
 * In words, the algorithm is as follows: 
 * 1) Look at the current permutation in reverse order.
 * 2) Continue while the numbers are in increasing order.
 * 3) Let i be the first index for which p_i < p_{i+1}.
 * 4) Swap p_i with the smallest element larger to the left of i.
 * 5) Reverse the segment to the right of i.
 *
 * But the funny thing is that there is a method in c++ called
 * next_permutation which does the exact same thing. Have to include
 * <algorithm>.
 *
 * Why does this algo work though??
 * --------------------------------
 * 1) For the element which we have found (ith element), the 
 *    permutation to the right is the largest that can be 
 *    obtained from those letters since they are in descending
 *    order.
 * 2) There is no way of incrementing this permutation keeping the
 *    ith term fixed. So to increase the algorithm, choose the next 
 *    element from the right i.e. the smallest element greater than
 *    this element. This could be done using Binary Search, a fact that
 *    escaped my small brain. 
 * 3) Now we have to reorder the elements in ascending order. For that
 *    we simply reverse. Let's say that the jth element was the next 
 *    larger element to the ith one. Clearly, p_j > p_{j+1}. This 
 *    implies that p_{j+1} < p_i. Since had that not been the case
 *    we would have chosen (j+1)th index for the swap.
 *    
 */
void increment(vector<int> &v){
    int i;
    for(i = v.size()-1; i > 0; i--){
        if(v[i-1] < v[i]) break;
    }
    int minDiff = INT_MAX;
    int iMin;
    for(int j = i; j < v.size(); j++){
        if(v[j] - v[i-1] > 0 && v[j] - v[i-1] < minDiff){
            minDiff = v[j] - v[i-1];
            iMin = j;
        }
    }
    swap(v[i-1],v[iMin]);
    vector<int> u(v.size() - i);
    int uInd = 0;
    for(int j = v.size()-1; j >= i; j--){
        u[uInd] = v[j];
        uInd++;
    }
    for(int j = i; j < v.size(); j++){
        v[j] = u[j-i];
    }
} 

int main(){
    vector<int> v(4);
    for(int i = 0; i < 4; i++) v[i] = i;
    string s;
    int n,m;
    cin >> n >> m;
    vector<vector<int> > maze(n);
    for(int i = 0; i < n; i++) maze[i].resize(m);
    int sx,sy,ex,ey;
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < m; j++){
            if(line[j] == 'S') sx = i, sy = j, maze[i][j] = 0;
            else if(line[j] == 'E') ex = i, ey = j, maze[i][j] = 3;
            else if(line[j] == '.') maze[i][j] = 1;
            else if(line[j] == '#') maze[i][j] = 2;
        }
    }
    cin >> s;
    int count = 0;
    int tx = sx, ty = sy;
    for(int i = 0; i < 24; i++){
        for(int j = 0; j < s.size(); j++){
            int dir = s[j]-48;
            if(v[dir] == 0) sx++;
            else if(v[dir] == 1) sy++;
            else if(v[dir] == 2) sx--;
            else if(v[dir] == 3) sy--;
            if(sx == ex && sy == ey){
                count++;
                break;
            }
            if(sx < 0 || sx >= n || sy < 0 || sy >= m || maze[sx][sy] == 2)
                break;
        }
        sx = tx, sy = ty;
        if(i != 23) increment(v);
    }
    cout << count << endl;
}

