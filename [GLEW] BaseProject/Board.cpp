#include "Board.h"

// constant shaders
char GREEN_SHADER[] = "res/shaderGreen";
char RED_SHADER[] = "res/shaderRed";
char BLUE_SHADER[] = "res/shaderBlue";
char YELLOW_SHADER[] = "res/shaderYellow";
char WHITE_SHADER[] = "res/shaderWhite";
char BASIC_SHADER[] = "res/basicShader";

Board::Board()
{
}//end func

Board::Board(char file[],float sideHeight,float xVal,float yVal,float zVal){
	init(file,sideHeight,xVal,yVal,zVal);
}//end func

void Board::init(char file[],float sideHeight,float xVal,float yVal,float zVal){
	std::ifstream in;
	in.open(file);
    std::vector<char> line;
	if(!in.fail())
	{
	    char c;
	    do{
		    c = in.get();
            if(c=='\n'||c==-1)
			{
                if(line.size()>0)
				{
                    boxContent.push_back(line);
                    line.erase(line.begin(),line.end());
                }
            }
			else line.push_back(c);
	    }
		while(in.good());
        x = xVal;
        y = yVal;
        z = zVal;
        squareSize = sideHeight;
    }
	else squareSize = -1;
}

void Board::draw()
{
	/*glPushMatrix();
	for(int i=0;i<boxContent.size();i++){
	    for(int j=0;j<boxContent[i].size();j++){
            switch(boxContent[i][j]){
                case 'l':glColor3f(1.0f, 1.0f, 1.0f);break;
                case 'd':glColor3f(0.5f, 0.5f, 0.5f);break;
                case 'r':glColor3f(1.0f, 0.0f, 0.0f);break;
                case 'g':glColor3f(0.0f, 1.0f, 0.0f);break;
                case 'b':glColor3f(0.0f, 0.0f, 1.0f);break;
                case 'y':glColor3f(1.0f, 1.0f, 0.0f);break;
            }
			drawSquare(x+j*squareSize,y+(boxContent.size()-i-1)*squareSize);
		}
	}
	glPopMatrix();*/

	// TODO: Change the shader
	for (int i = 0; i < boxContent.size(); i++)
	{
		for (int j = 0; j < boxContent[i].size(); j++)
		{
			switch(boxContent[i][j])
			{
				case 'l': drawSquare(WHITE_SHADER, x + j * squareSize, y + (boxContent.size() - i - 1) * squareSize); break;
				case 'd': drawSquare(BASIC_SHADER, x + j * squareSize, y + (boxContent.size() - i - 1) * squareSize); break;
				case 'r': drawSquare(RED_SHADER, x + j * squareSize, y + (boxContent.size() - i - 1) * squareSize); break;
				case 'g': drawSquare(GREEN_SHADER, x + j * squareSize, y + (boxContent.size() - i - 1) * squareSize); break;
				case 'b': drawSquare(BLUE_SHADER, x + j * squareSize, y + (boxContent.size() - i - 1) * squareSize); break;
				case 'y': drawSquare(WHITE_SHADER, x + j * squareSize, y + (boxContent.size() - i - 1) * squareSize); break;
			}
		}
	}
}

void Board::drawSquare(char shaderFile[], float xPos, float yPos)
{
	/*glBegin(GL_QUADS);
		glVertex3f( squareSize/2+xPos,  squareSize/2+yPos, z);
		glVertex3f(-squareSize/2+xPos,  squareSize/2+yPos, z);
		glVertex3f(-squareSize/2+xPos, -squareSize/2+yPos, z);
		glVertex3f( squareSize/2+xPos, -squareSize/2+yPos, z);
	glEnd();*/

	// TODO: Generate a Cube using the GLEW function

	m_Cube.initialize(shaderFile, squareSize / 2);
	m_Cube.getTransform()->GetPos()->x = xPos;
	m_Cube.getTransform()->GetPos()->y = yPos;

}

bool Board::isInitProperly()
{
    return (boxContent.size() > 0);
}

char Board::getTileType(int xSpace,int ySpace)
{
    return boxContent[getHeight()-1-ySpace][xSpace];
}

float Board::getBlockWidth()
{
    return squareSize;
}

float Board::getTopY(){return (boxContent.size()-1)*squareSize+y;}

int Board::getWidth(){
    return boxContent[0].size();
}

int Board::getHeight()
{
    return boxContent.size();
}

void Board::emptyBoard()
{
    boxContent.erase(boxContent.begin(),boxContent.end());
}
