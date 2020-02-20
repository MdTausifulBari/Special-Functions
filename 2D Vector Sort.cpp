#include<iostream>
#include<vector>
#include<algorithm>                       //for sort function
using namespace std;

bool sortcol(vector<int>& v1, vector<int>& v2)
{
                                         // [something] denotes sort using which column.
                                         // exm: [0] denotes 1st column, [1] denotes 2nd column...so on
    return v1[1] > v2[1];                // v1 < v2 refers to ascending order sort
                                         // v1 > v2 refers to descending order sort
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector< vector<int> > v(m);          //vector with defined column

    for(int i = 0; i < m; i++)
    {
        v[i] = vector<int>(2);           //declaring length of rows of columns

        for(int j = 0; j < 2; j++)
            cin >> v[i][j];
    }

    sort(v.begin(), v.end(), sortcol);   // sortcol to return which sort will perform

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < 2; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }

    return 0;
}

