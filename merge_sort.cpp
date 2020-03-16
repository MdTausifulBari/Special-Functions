#include<iostream>
using namespace std;

int ara[1000000], tmp[1000000];

void merge_sort(int st, int nd)
{
    if(st == nd) return;

    int mid = (st+nd)/2;

    merge_sort(st, mid);
    merge_sort(mid+1, nd);

    int i = st, j = mid+1;

    for(int k = st; k <= nd; k++)
    {
        if(i == mid+1)             tmp[k] = ara[j++];
        else if(j == nd+1)         tmp[k] = ara[i++];
        else if(ara[i] < ara[j])   tmp[k] = ara[i++];
        else                       tmp[k] = ara[j++];
    }

    for(int k = st; k <= nd; k++) ara[k] = tmp[k];
}


int main()
{
    int n;

    while(cin >> n)
    {
        if(!n) return 0;

        for(int i = 1; i <= n; i++)
            cin >> ara[i];

       merge_sort(1, n);                                //parameter should be exactly the starting and ending point of the array

       for(int i = 1; i <= n; i++)
        cout << ara[i] << " ";
       cout << endl;
    }
}

