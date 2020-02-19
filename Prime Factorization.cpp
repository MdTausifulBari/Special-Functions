/*
NEED TO ADD "DISPLAY ALL FACTOR OF A NUMBER"

Source: Programming Contest (Data Structure and Algorithm) by Mahbubul Hasan Santo (Page: 56)

*/

#include<iostream>
#include<vector>
#include<map>
#define MOD 1000000007
using namespace std;

int power(int a, int b)     //a = base, b = power
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;

    int tmp;

    if(b%2 != 0)
        return (power(a, b-1)*a)% MOD;
    tmp = power(a, b/2);
    return (tmp * tmp) % MOD;
}

int main()
{
    map<int, int> mp;
    vector<int> v, factor;

    cout << "Enter a value : ";
    int num;
    cin >> num;
    cout << endl;

    bool con = true;
    int clone = num;
    int temp = 2;

    while(num != 1)
    {
        if(num%temp == 0)
        {
            num = num/temp;
            mp[temp] += 1;

            if(con)
            {
                v.push_back(temp);
                con = false;
            }
        }
        else
        {
            temp++;
            con = true;
        }
    }

    int len = v.size();

    cout << "Prime Factorization of " << clone << " is : " << endl;

    for(int i = 0; i < len; i++)
        cout << v[i] << " with power " << mp[v[i]] << endl;
    cout << endl;


    //Displaying all factors




    //NOD - Number of Divisor

    int nod = 1;

    for(int i = 0; i < len; i++)
        nod *= (mp[v[i]] + 1);

    cout << "Number of divisor of " << clone << " is : " << nod << endl;
    cout << endl;

    //SOD - Sum of Divisor

    int sod = 1;

    for(int i = 0; i < len; i++)
        sod *= ((power(v[i], (mp[v[i]]+1)) - 1)/(v[i] - 1));

    cout << "Total sum of divisor of " << clone << " is : " << sod << endl;
    cout << endl;

    return 0;
}
