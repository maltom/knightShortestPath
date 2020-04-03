#include <string>
#include <memory>
#include <array>
#include <queue>

struct pole
{

  pole(int xs, int ys, int movess)
  {
    x=xs;
    y=ys;
    moves=movess;
  }
  int x;
  int y;
  int moves;
};

int knight(std::string start, std::string finish) {
  
  int x = (int)(start[0]-97);
  int y = (int)(start[1]-49);
  
  int xEnd = (int)(finish[0]-97);
  int yEnd = (int)(finish[1]-49);
  
  int movesX [8] = {-2, -2, -1, 1, 2, 2, 1, -1};
  int movesY [8] = {-1, 1, 2, 2, 1, -1, -2, -2};
  
  std::array<std::array <int, 8>, 8> visited;
  
  for(int i=0; i < 8;i++)
  {
    for(int j=0; j < 8;j++)
    {
      visited[i][j]=false;
    }
  }
  
  visited[x][y] = true;
  std::queue<pole> visitedPoles;
  pole consider(x,y,0);
  visitedPoles.push(consider);
  for(;;)
  {
  
    consider = visitedPoles.front();
    visitedPoles.pop();
    
    if((consider.x == xEnd) && (consider.y == yEnd))
      return consider.moves;
      
    for(int i = 0; i < 8; ++i)
    {
      int xTemp = consider.x + movesX[i];
      int yTemp = consider.y + movesY[i];
      
      if((xTemp>=0) && (xTemp<8) && (yTemp>=0) && (yTemp<8) && (visited[xTemp][yTemp]==false))
      {
        if((xTemp==xEnd) && (yTemp==yEnd))
          return consider.moves+1;
          
        visited[xTemp][yTemp] = true;
        visitedPoles.push(pole(xTemp,yTemp,consider.moves+1));
      }
    }
  }
  return 0;
}