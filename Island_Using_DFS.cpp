#include <iostream>
#include <vector>

using namespace std;
void DFS(int x,int y,vector<vector<bool> >& visited,const vector<vector<int>>& matrix)
{
    if(x < 0 || x >= visited.size() || y < 0 || y >= visited[0].size() || visited[x][y] || matrix[x][y] == 0)
        return;
    visited[x][y] = true;
    DFS(x+1,y,visited,matrix);
    DFS(x-1,y,visited,matrix);
    DFS(x,y+1,visited,matrix);
    DFS(x,y-1,visited,matrix);
}
int getNumberOfIslands( const vector<vector<int>>& binaryMatrix ) 
{
    if(binaryMatrix.size() == 0)
        return 0;
    if(binaryMatrix[0].size() == 0)
        return 0;
    vector<vector<bool> > visited(binaryMatrix.size());
    for(int i = 0;i < binaryMatrix.size();i++)
    {
        visited[i].resize(binaryMatrix[i].size());
        for(int j = 0;j < binaryMatrix[0].size();j++)
            visited[i][j] = false;
    }
    int count = 0;
    for(int i = 0;i < binaryMatrix.size();i++)
    {
        for(int j = 0;j < binaryMatrix[0].size();j++)
        {
            if(visited[i][j] || binaryMatrix[i][j] == 0)
                continue;
            DFS(i,j,visited,binaryMatrix);
            count++;
        }
    }
    return count;
}
