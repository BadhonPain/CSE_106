#include <bits/stdc++.h>
using namespace std;

void grouping(int src, vector<int> &g, vector<vector<int>> &graph, vector<bool> &isVisited)
{
    isVisited[src] = true;
    g.push_back(src);

    for (int dest : graph[src])
    {
        if (!isVisited[dest])
            grouping(dest, g, graph, isVisited);
    }
}

bool alreadyPlayed(int team1, int team2, vector<vector<int>> &graph)
{
    for (int team : graph[team1])
    {
        if (team == team2)
            return true;
    }

    return false;
}

int main()
{
    int n, edges;
    cin >> n >> edges;

    vector<vector<int>> graph(n);

    char br1, comma, br2;
    int a, b;
    while (edges--)
    {
        cin >> br1 >> a >> comma >> b >> br2;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> isVisited(n, false);
    vector<vector<int>> group;

    for (int i = 0; i < n; i++)
    {
        if (!isVisited[i])
        {
            vector<int> g;
            grouping(i, g, graph, isVisited);
            group.push_back(g);
        }
    }

    int group_size = group.size();
    cout << group_size << endl;

    for (int i = 0; i < group_size; i++)
    {
        int ith_group_size = group[i].size();
        cout << "Group " << i + 1 << ": {";

        for (int j = 0; j < ith_group_size; j++)
        {
            cout << group[i][j];
            if (j != ith_group_size - 1)
                cout << ", ";
        }
        cout << "} | ";

        vector<pair<int, int>> missingMatches;

        for (int j = 0; j < ith_group_size; j++)
        {
            for (int k = j + 1; k < ith_group_size; k++)
            {
                int team1 = group[i][j];
                int team2 = group[i][k];

                if (!alreadyPlayed(team1, team2, graph))
                    missingMatches.push_back({team1, team2});
            }
        }

        if (!missingMatches.empty())
        {
            for (int j = 0; j < missingMatches.size(); j++)
            {
                cout << "[" << missingMatches[j].first << ", " << missingMatches[j].second << "]";
                if (j != missingMatches.size() - 1)
                    cout << ", ";
            }
        }

        else
            cout << "none";

        cout << endl;
    }
}