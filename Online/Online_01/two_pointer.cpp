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
    sort(arr, arr + n);
    int idx_1 = -1, idx_2 = -1, idx_3 = -1;
    for (int i = 0; i < n; i++)
    {
        int start = i + 1, end = n - 1;
        while (start < end)
        {
            if (arr[i] + arr[start] + arr[end] > 0)
            {
                end--;
            }
            else if (arr[i] + arr[start] + arr[end] < 0)
            {
                start++;
            }
            else
            {
                cout << i << " " << start << " " << end << endl;
                return 0;
            }
        }
    }
    cout << "No Triplets Found!! " << endl;
}
// In this way, the real indices become changed but it was allowed by sessional teachers