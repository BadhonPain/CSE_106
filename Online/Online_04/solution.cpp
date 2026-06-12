#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;

    map<string, set<string>> adj;

    for (int i = 0; i < m; i++)
    {
        string line;
        cin >> line;
        line = line.substr(1, line.size() - 2);
        int comma = line.find(',');
        string a = line.substr(0, comma);
        string b = line.substr(comma + 2);
        adj[a].insert(b);
        adj[b].insert(a);
    }

    string s;
    cin >> s;

    set<string> friends = adj[s];
    set<string> all_nodes;
    for (auto &p : adj)
    {
        all_nodes.insert(p.first);
    }

    vector<pair<string, int>> result;

    for (auto &x : all_nodes)
    {
        if (x == s || friends.count(x))
            continue;
        int mutual = 0;
        for (auto &f : friends)
        {
            if (adj[x].count(f))
                mutual++;
        }
        result.push_back({x, mutual});
    }

    sort(result.begin(), result.end());

    for (auto &r : result)
    {
        cout << s << " -- " << r.first << ": " << r.second << "\n";
    }

    return 0;
}