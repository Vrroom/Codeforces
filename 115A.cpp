#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> hierarchy(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == -1) hierarchy[i] = x;
        else        hierarchy[i] = x-1;
    }
    int max = 0;
    vector<bool> visited(n);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            int x = hierarchy[i];
            int count = 1;
            while(x != -1){
                visited[x] = true;
                x = hierarchy[x];
                count++;
            }
            if(count > max) max = count;
        }
    }
    cout << max << endl;
}

