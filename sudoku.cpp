#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define N 9
ll getMin(ll arr[], ll n)
{
    ll res = arr[0];
    for (ll i = 1; i < n; i++)
        res = min(res, arr[i]);
    return res;
}
ll getMax(ll arr[], ll n)
{
    ll res = arr[0];
    for (ll i = 1; i < n; i++)
        res = max(res, arr[i]);
    return res;
}

ll isSafe(ll grid[N][N], ll row,
          ll col, ll num)
{

    for (ll x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return 0;

    for (ll x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return 0;

    ll startRow = row - row % 3,
       startCol = col - col % 3;

    for (ll i = 0; i < 3; i++)
        for (ll j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                                   startCol] == num)
                return 0;

    return 1;
}
ll solveSudoku(ll grid[N][N], ll row, ll col)
{
    if (row == N - 1 && col == N)
        return 1;
    if (col == N)
    {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);

    for (ll num = 1; num <= N; num++)
    {
        if (isSafe(grid, row, col, num) == 1)
        {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1) == 1)
                return 1;
        }
        grid[row][col] = 0;
    }
    return 0;
}
int main()
{

    ll matrix[N][N];
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)

        {
            cin >> matrix[i][j];
        }
    }
    if (solveSudoku(matrix, 0, 0) == 1)
    {
        for (ll i = 0; i < N; i++)
        {
            for (ll j = 0; j < N; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "NO SOLUTION" << endl;
    }

    return 0;
}