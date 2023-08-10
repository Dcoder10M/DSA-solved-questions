/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
Node* constructs(int n,int i,int j,vector<vector<int>>& grid){
    Node* quad=new Node(1,0);
    int r=1;
       int p=grid[i][j];
    for(int k=i;k<i+n;k++){
        for(int v=j;v<j+n;v++){
            if(grid[k][v]!=p){
                r=0;
                break;
            }
        }
        if(!r)break;
    }
    if (r)
      return new Node(grid[i][j], 1);
    quad->topLeft=constructs(n/2,i,j,grid);
    quad->bottomLeft=constructs(n/2,i+(n/2),j,grid);
    quad->topRight=constructs(n/2,i,j+(n/2),grid);
    quad->bottomRight=constructs(n/2,i+(n/2),j+(n/2),grid);
    return quad;
}
    Node* construct(vector<vector<int>>& grid) {
        return constructs(grid.size(),0,0,grid);
    }
};