#include <algorithm>
bool cmp(vector<int> &a, vector<int> &b)
{
  return a[2] < b[2];
}

int findParent(int u, vector<int> &parent)
{
  int temp = u;
  while (u != parent[u])
  {
    u = parent[u];
  }
  return parent[temp] = u;
}

void unionSet(int u, int v, vector<int> &rank, vector<int> &parent)
{

  u = findParent(i[0], parent); // this step and the follwoing step is just for safety purpose incase someone else calls unionset function with u and v not being the roots. even if u dont write these 2 steps the code runs fine.
  v = findParent(i[1], parent);
  if (rank[u] < rank[v])
    parent[u] = v;
  else if (rank[u] > rank[v])
    parent[v] = u;
  else
  {
    parent[v] = u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
  sort(edges.begin(), edges.end(), cmp);
  vector<int> parent(n);
  vector<int> rank(n, 0);

  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }

  int minWt = 0;
  for (auto i : edges)
  {
    int u = findParent(i[0], parent);
    int v = findParent(i[1], parent);
    int wt = i[2];

    if (u != v)
    {
      minWt += wt;
      unionSet(u, v, rank, parent);
    }
  }
  return minWt;
}