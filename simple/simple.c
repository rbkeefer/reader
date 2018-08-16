#include <stdio.h>

int left = 2;
int right = 4;
int top = 2;
int bottom = 4;
int size = 8;

void findRight(int inTop, int inLeft, int inBottom, int inRight)
{
  int pixel;
  int newRight = inRight;
  int currentColumn = inLeft;
  int currentRow = inTop;
  bool myColor = true;

  printf("FIND RIGHT from [%d, %d] to [%d, %d]\n", inLeft, inTop, inRight, inBottom);

  for (currentRow = inTop; currentRow <= inBottom; currentRow++)
  {
    myColor = true;
    currentColumn = inLeft;

    while (myColor)
    {
      pixel = currentColumn+(size*currentRow);

      if (pixel == 20) { myColor = false; newRight = (newRight < currentColumn) ? currentColumn : newRight; } 
      if (pixel == 29) { myColor = false; newRight = (newRight < currentColumn) ? currentColumn : newRight; } 
      if (pixel > 64) myColor = false;

      printf("%d\n", pixel);

      currentColumn++;
    }
  }

  printf("New Bounding Rectangle: [%d, %d] to [%d, %d]\n", inLeft, inTop, newRight-1, inBottom);
}

void findBottom(int inTop, int inLeft, int inBottom, int inRight)
{
  int pixel;
  int newBottom = inBottom;
  int currentColumn = inLeft;
  int currentRow = inTop;
  bool myColor = true;

  printf("FIND BOTTOM from [%d, %d] to [%d, %d]\n", inLeft, inTop, inRight, inBottom);

  for (currentColumn = inLeft; currentColumn <= inRight; currentColumn++)
  {
    myColor = true;
    currentRow = inTop;

    while (myColor)
    {
      pixel = currentColumn+(size*currentRow);

      if (pixel == 42) { myColor = false; newBottom = (newBottom < currentRow) ? currentRow : newBottom; } 
      if (pixel == 43) { myColor = false; newBottom = (newBottom < currentRow) ? currentRow : newBottom; } 
      if (pixel > 64) myColor = false;

      printf("%d\n", pixel);

      currentRow++;
    }
  }

  printf("New Bounding Rectangle: [%d, %d] to [%d, %d]\n", inLeft, inTop, inRight, newBottom-1);
}


int main(int argc, char** argv) {

  int pixel;
  int count = 0;
  int currentRow = 0;
  int currentColumn = 0;

  bool foundBottom = false;
  bool foundRight = false;

  while (currentRow < 5)
  {
    for (count = 0; count <= currentRow; count++)
    {
      currentColumn = count+left;
      pixel = (top*size)+currentColumn+(size*currentRow);

      if (pixel == 44)  // simulate hitting white space
      {
        (count == 0) ? foundBottom = true : foundRight = true;
        break;        
      }

      printf("%d\n", pixel);
    }
    if (foundBottom || foundRight) break;
    currentRow++;
  }

  if (foundBottom) findRight(top, left, currentRow+top-1, currentColumn);
  if (foundRight) findBottom(top, left, currentRow+top, currentColumn-1);

}

