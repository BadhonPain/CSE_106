#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int idx_1 = -1, idx_2 = -1, idx_3 = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
    cout << "No Triplets Found!! " << endl;
    return 0;
}