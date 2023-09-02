class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // Initialize distance arrays and visited arrays
        vector<int> dist1(edges.size(), -1);
        vector<int> dist2(edges.size(), -1);
        vector<bool> visited1(edges.size(), false);
        vector<bool> visited2(edges.size(), false);
        // Perform BFS from node1 and node2
        queue<int> q;
        q.push(node1);
        dist1[node1] = 0;
        visited1[node1] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (edges[curr] != -1 && !visited1[edges[curr]]) {
                q.push(edges[curr]);
                dist1[edges[curr]] = dist1[curr] + 1;
                visited1[edges[curr]] = true;
            }
        }
        q.push(node2);
        dist2[node2] = 0;
        visited2[node2] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (edges[curr] != -1 && !visited2[edges[curr]]) {
                q.push(edges[curr]);
                dist2[edges[curr]] = dist2[curr] + 1;
                visited2[edges[curr]] = true;
            }
        }
    
        // Find the node with the minimum maximum distance from node1 and node2
        int minDist = INT_MAX;
        int minNode = -1;
        for (int i = 0; i < edges.size(); i++) {
            if (visited1[i] && visited2[i]) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    minNode = i;
                }
            }
        }
    
        return minNode;
    }
};