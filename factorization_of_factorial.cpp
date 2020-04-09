#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool mark[10000005];
vector<long long> prime;

void sieve(int n)
{
    int limit = sqrt(n) + 1;

    mark[0] = mark[1] = 1;

    for(int i = 4; i <= n; i += 2)  mark[i] = 1;

    for(int i = 3; i <= limit; i++)
    {
        if(!mark[i])
        {
            for(int j = i*i; j <= n; j += i*2)
                mark[j] = 1;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(!mark[i])
            prime.push_back(i);
    }
}

long long frequency_of_a_prime(long long n, long long prime_num)
{
    long long freq = 0;

    while(n)
    {
        freq += n/prime_num;
        n /= prime_num;
    }

    return freq;
}

int main()
{
    sieve(10000000);

    int cs = 1;

    int q;
    cin >> q;

    while(q--)
    {
        long long int n;
        cin >> n;

        vector<long long> prime_factor, frequency;

        for(int i = 0; i < prime.size() && prime[i] <= n; i++)
        {
            int freq = frequency_of_a_prime(n, prime[i]);

            if(freq)
            {
                prime_factor.push_back(prime[i]);
                frequency.push_back(freq);
            }
        }

// prime (it's power)...

        cout << "Case " << cs << ": " << n << " = ";
        for(int i = 0; i < prime_factor.size(); i++)
        {
            if(i)   cout << " * ";

            cout << prime_factor[i] << " (" << frequency[i] << ")";
        }
        cout << endl;
        cs++;
    }

    return 0;
}
