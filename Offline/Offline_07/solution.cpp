#include <bits/stdc++.h>
using namespace std;

int main()
{
    int insertionCost, deletionCost, replaceCost;
    cin >> insertionCost >> deletionCost >> replaceCost;
    cin.ignore();

    string source, target;
    getline(cin, source);
    getline(cin, target);

    int n = source.length();
    int m = target.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // 1

    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = i * insertionCost; // 2
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i * deletionCost; // 3
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (source[i - 1] == target[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1] + replaceCost, min(dp[i - 1][j] + deletionCost, dp[i][j - 1] + insertionCost));
        }
    }

    cout << "Minimum Cost: " << dp[n][m] << endl;
    cout << "Operations: " << endl;

    vector<string> operations;
    int i = n, j = m;

    while (i > 0 || j > 0)
    {
        if (i && j && source[i - 1] == target[j - 1])
        {
            operations.push_back("Match " + string(1, source[i - 1]));
            i--, j--;
        }

        else if (i && j && dp[i][j] == dp[i - 1][j - 1] + replaceCost)
        {
            operations.push_back("Replace " + string(1, source[i - 1]) + " with " + string(1, target[j - 1]));
            i--, j--;
        }

        else if (i && dp[i][j] == dp[i - 1][j] + deletionCost)
        {
            operations.push_back("Delete " + string(1, source[i - 1]));
            i--;
        }

        else if (j && dp[i][j] == dp[i][j - 1] + insertionCost)
        {
            operations.push_back("Insert " + string(1, target[j - 1]));
            j--;
        }
    }

    reverse(operations.begin(), operations.end());

    for (auto &operation : operations)
    {
        cout << operation << endl;
    }
}