#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int arr[N];
int dp[1005][1005];

bool subset(int n, int s)
{
    if (n == 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }

    if (dp[s][n] != -1)
        return dp[s][n];

    if (arr[n - 1] <= s)
    {
        bool op1 = subset(n - 1, s - arr[n - 1]);
        bool op2 = subset(n - 1, s);

        return dp[s][n] = op1 || op2;
    }
    else
    {
        return dp[s][n] = subset(n - 1, s);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s;
    cin >> s;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }
    subset(n, s) ? cout << "YES" << endl : cout << "NO" << endl;

    return 0;
}