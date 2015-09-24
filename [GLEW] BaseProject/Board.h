/*
Tips: You can take one of several approaches to convert the board class.
  1. Create several shaders to color the different squares.
  2. Have textures prepared for each of the colors.
  3. Pass the color as a uniform to the shader and let it color the squares.

Approach 3 is the most efficient method for this problem...
*/
#ifndef BOARD_H
#define	BOARD_H

#include <vector>
#include "Cube.h"
#include "BaseObject.h"

class Board: public BaseObject
{
    public:
        Board();
		Board(char file[],float sideHeight,float xVal,float yVal,float zVal);
        void init(char file[],float sideHeight,float xVal,float yVal,float zVal);
		void update();
        void draw();
        bool isInitProperly();
        char getTileType(int xSpace,int ySpace);
        int getWidth();
        int getHeight();
        void emptyBoard();
        float getBlockWidth();
        float getTopY();
	private:
        float squareSize;
        std::vector< std::vector<char> > boxContent;
        void drawSquare(char shaderFile[], float xPos, float yPos);

		// Cube Component
		Cube m_Cube;
};

#endif /* BOARD_H */
