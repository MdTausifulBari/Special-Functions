#include<iostream>
#include<cmath>
using namespace std;

bool mark[10000005];
int prime[10000005];

void sieve(int n)
{
    mark[0] = mark[1] = 1;

    int limit = sqrt(n)+1;

    for(int i = 4; i <= n; i += 2)
        mark[i] = 1;

    for(int i = 3; i <= limit; i += 2)
    {
        if(mark[i] == 0)
        {
            for(int j = i*i; j <= n; j += 2*i)
                mark[j] = 1;
        }
    }

    int k = 0;
    for(int i = 1; i <= n; i++)
    {
        if(mark[i] != 1)
        {
            prime[k] = i;
            k++;
        }
    }
}

int main()
{
    sieve(1000000);

    return 0;
}

