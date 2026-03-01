#include <bits/stdc++.h>
using namespace std;

class City
{
public:
    int ID;
    double x, y;

    City(){}
    

    City(int ID, double x, double y)
    {
        this->ID = ID;
        this->x = x;
        this->y = y;
    }
};

class Edge
{
public:
    int u, v;
    double cost;

    Edge() {}

    Edge(int u, int v, double cost)
    {
        this->u = u;
        this->v = v;
        this->cost = cost;
    }
};

double distance(const City &city1, const City &city2)
{
    double xDist = city1.x - city2.x;
    double yDist = city1.y - city2.y;

    return sqrt(xDist * xDist + yDist * yDist);
}

int thresold;
vector<Edge> selectedEdges;
double totalCost = 0;

bool isAlreadyConnected(int initID, int destID, unordered_map<int, vector<int>> &adjList, unordered_set<int> &isVisited)
{
    if (initID == destID)
        return true;
    isVisited.insert(initID);

    for (auto neighbor : adjList[initID])
    {
        if (!isVisited.count(neighbor))
            if (isAlreadyConnected(neighbor, destID, adjList, isVisited))
                return true;
    }

    return false;
}

void buildBase(vector<City> &cities, int left, int right)
{
    vector<Edge> connectEdges;

    for (int i = left; i <= right; i++)
    {
        for (int j = i + 1; j <= right; j++)
        {
            double dist = distance(cities[i], cities[j]);
            connectEdges.push_back(Edge(cities[i].ID, cities[j].ID, dist));
        }
    }

    sort(connectEdges.begin(), connectEdges.end(), [](const Edge &edge1, const Edge &edge2)
         { return edge1.cost < edge2.cost; });

    unordered_map<int, vector<int>> adjlist;
    int coveredEdges = 0;

    for (auto &edge : connectEdges)
    {
        unordered_set<int> isVisited;
        if (!isAlreadyConnected(edge.u, edge.v, adjlist, isVisited))
        {

            adjlist[edge.u].push_back(edge.v);
            adjlist[edge.v].push_back(edge.u);

            selectedEdges.push_back(edge);
            totalCost += edge.cost;
            coveredEdges++;
        }

        int n = right - left + 1;
        if (coveredEdges == n - 1)
            break;
    }
}

void merge(vector<City> &cities, int left, int mid, int right)
{
    int start = max(left, mid - thresold + 1);
    int end = min(right, mid + thresold);
    double suitableCost = 1e18;
    int suitableU = -1, suitableV = -1;

    for (int i = start; i <= mid; i++)
    {
        for (int j = mid + 1; j <= end; j++)
        {
            double d = distance(cities[i], cities[j]);
            if (d < suitableCost)
            {
                suitableCost = d;
                suitableU = cities[i].ID;
                suitableV = cities[j].ID;
            }
        }
    }
    if (suitableU != -1)
    {
        selectedEdges.push_back(Edge(suitableU, suitableV, suitableCost));
        totalCost += suitableCost;
    }
}

void divideAndConquere(vector<City> &cities, int left, int right)
{
    int n = right - left + 1;
    if (n <= thresold)
    {
        buildBase(cities, left, right);
        return;
    }

    int mid = left + (right - left) / 2;

    divideAndConquere(cities, left, mid);
    divideAndConquere(cities, mid + 1, right);

    merge(cities, left, mid, right);
}

int main()
{
    int N;
    cin >> N >> thresold;

    vector<City> cities;
    for (int i = 0; i < N; i++)
    {
        int ID;
        double x, y;
        cin >> ID >> x >> y;
        cities.push_back(City(ID, x, y));
    }

    sort(cities.begin(), cities.end(), [](City &city1, City &city2)
         { return city1.x < city2.x; });

    divideAndConquere(cities, 0, N - 1);

    cout << fixed << setprecision(2);
    cout << "Total Cost: " << totalCost << "\n";
    cout << "Edges:\n";

    for (auto &edge : selectedEdges)
    {
        cout << edge.u << " "
             << edge.v << "\n";
    }
}