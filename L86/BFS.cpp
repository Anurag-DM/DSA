vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
  queue<int> q;
  q.push(adj[0][0]);
  vector<int> ans;
  unordered_map<int, bool> visited;
  visited[adj[0][0]] = true;
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    ans.push_back(front);
    for (int i = 1; i < adj[front].size(); i++)
    {
      int neighbor = adj[front][i];
      if (!visited[neighbor])
      {
        q.push(neighbor);
        visited[neighbor] = true;
      }
    }
  }
  return ans;
}