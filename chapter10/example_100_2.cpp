
#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<vector>

#include<stack>

#include<queue>

#include<map>

#include<set>

#include<list>

#include<string>

#include<cmath>

#include<sstream>

#include<ctime>

using namespace std;

#define _PI acos(-1.0)

#define INF 1 << 10

#define esp 1e-6

typedef long long LL;

typedef unsigned long long ULL;

typedef pair<int,int> pill;

/*===========================================

===========================================*/

#define MAXD 200 + 10

#define max_size 10001

void gcd(LL a , LL b ,LL &d, LL &x,LL &y){

    if(!b){

        d = a ;

        x = 1;  y = 0;

        return ;

    }

    else{

        gcd(b , a % b ,d , y , x);

        y -= x * (a / b);

        return ;

    }

}

int main(){
    freopen("example_10_2_in.txt","r",stdin);
    LL a,b,x[MAXD];

    int T;

    scanf("%d",&T);

    for(int i = 1 ; i < 2 * T  ; i += 2)

        scanf("%lld",&x[i]);

    for(a = 0; ; a++){

        LL k , b , d;

        LL t = (x[3] - a * a * x[1]);

        gcd(max_size, a + 1, d , k, b);

        if(t % d) continue;

        b = b * t / d;

        int yes = 1;

        for(int i = 2 ; i <= 2 * T ; i ++){

            if(i & 1){

                if(x[i] != ((a * x[i - 1] + b) % max_size)){

                     yes = 0;

                     break;

                }

            }

            else{

                x[i] = (a * x[i - 1] + b) % max_size;

            }

        }

        if(yes)

            break;

    }

    for(int i = 2 ; i <= 2 * T ; i+=2)

        printf("%lld\n",x[i]);

    return 0;

}
