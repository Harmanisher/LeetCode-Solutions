class Solution {
public:

    void DFSTraversal(int node, int size, vector<vector<int>>&isConnected, vector<int> &visited)
    {
        visited[node] = 1;

        for(int i=0; i<size; i++)
        {
            if(isConnected[node][i] ==1 &&  visited[i]==0)
            {
                DFSTraversal(i,size,isConnected,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        int count = 0;
        vector<int>visited(size,0);

        for(int i=0; i<size; i++)
        {
            if(visited[i]==0)
            {
                DFSTraversal(i,size,isConnected,visited);
                count++;
            }
        }

        return count;
    }
};