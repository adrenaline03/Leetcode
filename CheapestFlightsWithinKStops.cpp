class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);

        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto &vec: flights) {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];

            adj[u].push_back({v, cost});
        }

        queue<pair<int, int>> que;
        que.push({src, 0});
        distance[src] = 0;

        int steps = 0;

        while(!que.empty() && steps <= k) {
            int N = que.size();

            while(N--) {
                int u = que.front().first;
                int d = que.front().second;

                que.pop();

                for(auto &p: adj[u]) {
                    int v = p.first;
                    int cost = p.second;

                    if(distance[v] > d + cost) {
                        distance[v] = d + cost;
                        que.push({v, d + cost});
                    } 
                }
            }

            steps++;
        }

        if(distance[dst] == INT_MAX) return -1;

        return distance[dst];
    }
};