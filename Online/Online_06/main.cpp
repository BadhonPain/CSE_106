#include <bits/stdc++.h>
using namespace std;

int damerauLevenshtein(string A, string B)
{
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int cost = (A[i - 1] == B[j - 1]) ? 0 : 1;

            dp[i][j] = min({dp[i - 1][j] + 1,
                            dp[i][j - 1] + 1,
                            dp[i - 1][j - 1] + cost});

            if (i > 1 && j > 1 && A[i - 1] == B[j - 2] && A[i - 2] == B[j - 1])
            {
                dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + 1);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string A, B;
    cin >> A >> B;
    cout << damerauLevenshtein(A, B) << endl;
    return 0;
}