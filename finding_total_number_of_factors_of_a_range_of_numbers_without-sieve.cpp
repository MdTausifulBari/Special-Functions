#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int f[1000000];
int cnt[1000000][ 15 ];

void factor() {
        for( int i = 2; i <= 1000000; i++ ) {
                if( !f[i] ) {
                        for( int j = i; j <= 1000000; j += i ) {
                                f[j]++;
                        }
                }
        }
        for( int i = 1; i <= 1000000; i++ ) {
                for( int j = 0; j <= 10; j++ ) {
                        if( f[i] == j ) cnt[i][j]++;
                        cnt[i][j] += cnt[i-1][j];
                }
        }
}
int main( ) {
        factor();

        int t;
        scanf("%d",&t);
        while( t-- ) {
                int a , b , k;
                scanf("%d %d %d",&a,&b,&k);
                printf("%d\n",cnt[b][k]-cnt[a-1][k]);
        }

        return 0;
}
