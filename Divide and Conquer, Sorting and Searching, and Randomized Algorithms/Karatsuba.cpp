#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long

long long get_n(ll x, ll y){
    return max(to_string(x).size(),to_string(y).size());
}

long long get_b_d(ll x, ll half_n){
    ll p = pow(10,half_n);
    return x%p;
}

long long get_a_c(ll x, ll half_n){
    ll p = pow(10,half_n);
    return floor(x/p);
}

long long star(ll ac, ll bd, ll mid, ll half_n){
      return (pow(10 * 1L,half_n*2)*ac + pow(10* 1L,half_n)*mid + bd);
}

long long Karatsuba(long long x, long long y){
    if(x < 10 && y < 10)
        return x*y;

    ll n = get_n(x,y);
    ll half_n = n/2;

    ll a = get_a_c(x,half_n);
    ll c = get_a_c(y,half_n);
    ll b = get_b_d(x,half_n);
    ll d = get_b_d(y,half_n);

    ll ac = Karatsuba(a,c);
    ll bd = Karatsuba(b,d);
    ll mid = Karatsuba(a+b,c+d) - ac - bd;

    return star(ac,bd,mid,half_n); 
}

void test_Karatsuba(){
    ll x,y; 
    cin >> x >> y;
    ll k = Karatsuba(x,y);
    cout << (( k == x*y) ? "Pass" : "Fail") << endl;
    cout << "yours:   " <<  k << endl;
    cout << "correct: " << x*y << endl;
}

void test_to_xy(){
    ll x; 
    cin >> x;
    ll allc =  0;
    ll failc = 0;
    for(int j = 0 ; j <= x ; j++){
        for(int i = 0 ; i <= x ; i++){
            allc++;
            ll k = Karatsuba(i,j);
            bool fail =0;
            k == i*j ? fail : fail = 1 ;
            if(fail){
                failc++;
                cout << "x: " << i << " y: " << j << endl;
                cout << "yours:   " <<  k << endl;
                cout << "correct: " << i*j << endl;
                cout << "-------------" << endl;
            }
        }
    }
    cout << "passed: " << allc-failc<< "/" << allc << endl;
    cout << "accuracy: " << (double)(allc-failc)/allc*100 << "%" << endl;
}

int main(){
    //test_Karatsuba();
    //test_to_xy();
    return 0;
}
