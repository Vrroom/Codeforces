#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(m.count(x) == 0){
            m[x] = 1;
        }else{
            m[x]++;
        }
    }
    int max = 0;
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
        if(max < it->second) max = it->second;
    }
    cout << max << endl;
}
