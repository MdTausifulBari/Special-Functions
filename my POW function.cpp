#include<iostream>
#define MOD 1000000007
using namespace std;

long long int pow(long long base, long long power)
{
    long long temp;

    if(power == 0)
        return 1;
    if(power == 1)
        return base;

    if(power%2 != 0)
        return (pow(base, power-1)*base) % MOD;

    temp = pow(base, power/2);
    return (temp*temp) % MOD;
}

int main()
{
    long long bs, pwr;
    cin >> bs >> pwr;

    long long ans = pow(bs, pwr);
    cout << ans << endl;

    return 0;
}
