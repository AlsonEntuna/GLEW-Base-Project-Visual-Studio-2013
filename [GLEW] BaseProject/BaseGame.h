#ifndef BASEGAME_H
#define	BASEGAME_H

#include <math.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

class BaseGame
{
    public:
		BaseGame(int width,int height,char title[]);
		void initialization();
		void eventPoll();
		bool isRunning();
        void start();
    protected:
        void clear();
		void display();
		bool isUPPressed();
		bool isDOWNPressed();
		bool isLEFTPressed();
		bool isRIGHTPressed();
		bool isSPressed();
		bool isWPressed();
        bool isSpacePressed();

        virtual void update() = 0;
        virtual void draw() = 0;
	private:
		sf::Window window;
		bool running;
		void gluPerspectiveCompat( GLdouble fovY, GLdouble aspect,
			GLdouble zNear, GLdouble zFar );
		void resizeWindow(unsigned int width,unsigned int height);
};

#endif /* BASEGAME_H */
