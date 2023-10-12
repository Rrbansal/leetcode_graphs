// keys in room indicates neighbours of that room(node)
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>visited;
        queue<int>q;
        q.push(0);
        visited.insert(0);
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(int nei:rooms[curr])
            {
                if(visited.count(nei)==0)
                {
                    q.push(nei);
                    visited.insert(nei);
                }
            }
        }
        if(visited.size()==rooms.size()) return true;
        return false;
        
    }
};
