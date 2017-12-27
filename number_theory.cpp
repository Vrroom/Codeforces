// Some number theory related computations
#include <climits>
#include <iostream>
#include <utility>

using namespace std;
typedef long long ll;

ll mod_inv(ll,ll);

bool v[1000001];
int sp[1000001];
ll twoPow[1000001];
ll fact[2000001];
ll ifact[2000001];
ll mod = 1000000007;

void inverseFact(){
    ifact[0] = 1;
    for(int i = 1; i < 2000001; i++){
        ifact[i] = (mod_inv(i,mod)*ifact[i-1]) % mod;
        if(ifact[i] < 0) ifact[i]+=mod;
    }
}

void factorial(){
    fact[0] = 1;
    for(int i = 1; i < 2000001; i++){
        fact[i] = (i*fact[i-1]) % mod;
    }
}

ll ncr(int n, int r){
    if(r > n) return 0;
    if(n-r < r) r = n-r;
    ll num = fact[n]*ifact[r];
    num = num % mod;
    num *= ifact[n-r];
    num = num % mod;
    return num;
}

/* In the array sp, we are storing the smallest prime 
 * factor of n. Clearly, for even n, this number is 
 * going to be 2. For others, we use the sieve 
 * technique to figure out the smallest prime factor.
 * Computing this is going to help us compute the prime 
 * factors of the number n.
 */
void sieve(){
    sp[0] = sp[1] = 0;
    for(int i = 2; i < 1000001; i+=2) sp[i] = 2;
    for(int i = 3; i < 1000001; i+=2){
        if(!v[i]){
            sp[i] = i;
            for(ll j = i; j*i < 1000001;j+=2){
                if(!v[j*i]){
                    v[j*i] = true;
                    sp[j*i] = i;
                }
            }
        }
    }
}

/* Extended Euclid's Algorithm:
 * We know that if d is the gcd of m and n, then there exist
 * integers x and y such that x*m + y*n = d.
 * This algorithm finds x,y and d given m and n. Being able to
 * compute x and y is useful for finding modular inverses.
 * Because if m,n are coprime, then gcd(m,n) = d = 1.
 *  => x*m + y*n = 1
 *  => x*m = 1 - y*n
 *  => x*m = 1 (mod n)
 *  => x is the modular inverse of m (mod n).
 * The following algorithm is taken from TAOCP Vol 1.
 */
pair<ll, pair<ll, ll> > eea(ll m, ll n){
    ll a_ = 1;
    ll b = a_;
    ll a = 0;
    ll b_ = a;
    ll c = m;
    ll d = n;
    while(true){
        /* Loop invariant: 
         * a_*m + b_*n = c --(1)
         * a*m + b*n = d --(2)
         * The first time we enter this loop,
         * this is definitely true.
         * In the else block, c<-d, a_<-a and b_<-b.
         * By (2), (1) is preserved.
         * Also, a<-(a_ - (c/d)*a) and b<-(b_ - (c/d)*b).
         * Hence a*m + b*n = a_*m + b_*n - (c/d)*a*m - (c/d)*b*n.
         * = c - (c/d)(a*m + b*n)
         * = c - (c/d)(d)
         * = c%d = r (which is the new c).
         * Remember, all the values used in the computation
         * are the ones before entering the else block.
         */
        ll q = c/d;
        ll r = c%d;
        if(r == 0){
            pair<ll,ll> p(a,b);
            pair<ll,pair<ll,ll> > p1(d,p);
            return p1;
        }else{
            c = d;
            /* We know that d is going to be the gcd(m,n)
             * in some time. Rest is simply a matter of maintaining
             * the other values such that a*m + b*n = d.
             */
            d = r;
            ll t = a_;
            a_ = a;
            a = t - q*a;
            t = b_;
            b_ = b;
            b = t - q*b;
        }
    }
}

/* Calculates modular inverse of a number m (mod n).
 * It should be noted that modular inverse of m (mod n)
 * exists if and only if m and n are relatively prime.
 */ 
ll mod_inv(ll m,ll n){
    pair<ll, pair<ll, ll> > result = eea(m,n);
    return result.second.first;
}


void eTwo(){
    twoPow[0] = 1;
    for(int i = 1; i < 1000001; i++){
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
                csp = sp[tX];
                count = count*ncr(c+y-1,c);
                c = 1;
                count = count % mod;
            }
        }
        cout << count << endl;
    }
}
            
