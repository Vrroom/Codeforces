#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int min = INT_MAX;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < min) min = arr[i];
    }
    int prevInd = -1;
    int minDist = n;
    for(int i = 0; i < n; i++){
        if(arr[i] == min && prevInd == -1){
            prevInd = i;
        }else if(arr[i] == min){
            if(i-prevInd < minDist) minDist = i - prevInd;
            prevInd = i;
        }
    }
    cout << minDist << endl;
    return 0;
}

