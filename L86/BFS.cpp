vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    queue<int> q;
    vector<int> ans;
    unordered_map<int, bool> visited;

    q.push(0);
    visited[0] = true;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(int neighbor : adj[front])
        {
            if(!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return ans;
}