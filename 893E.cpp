#include "numTh.cpp"

ll twoPow[1000000];

void eTwo(){
    twoPow[0] = 1;
    for(int i = 1; i < 1000000; i++){
        twoPow[i] = twoPow[i-1]*2 % mod;
    }
}

int main(){
    int q;
    cin >> q;
    factorial();
    inverseFact();
    sieve(); 
    eTwo();
    for(int i = 0; i < q; i++){
        int x,y;
        cin >> x >> y;
        ll count = twoPow[y-1];
        int tX = x;
        int csp = sp[tX];
        int c = 1;
        while(tX != 1){
            tX = tX/csp;
            if(sp[tX] == csp){
                c++;
            }else{
                c == 1;
                csp = sp[tX];
                count = count*ncr(c+y-1,c);
                count = count % mod;
            }
        }
        cout << count << endl;
    }
}
            
