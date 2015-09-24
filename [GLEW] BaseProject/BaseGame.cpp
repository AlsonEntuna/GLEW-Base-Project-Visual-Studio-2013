#include "BaseGame.h"

#define M_PI = 3.14

BaseGame::BaseGame(int width,int height,char title[]){
window.create(sf::VideoMode(width, height), title, sf::Style::Default,
		sf::ContextSettings(32));
    window.setPosition(sf::Vector2i(0,0));
    window.setVerticalSyncEnabled(true);

    glEnable(GL_DEPTH_TEST);

    resizeWindow(window.getSize().x,window.getSize().y);
	running = true;
}

void BaseGame::eventPoll(){
	sf::Event event;
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            running = false;
        }else if (event.type == sf::Event::Resized){
            resizeWindow(event.size.width, event.size.height);
        }
    }
}

bool BaseGame::isRunning(){
	return running;
}

void BaseGame::clear(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
}

void BaseGame::display(){
	window.display();
}

bool BaseGame::isUPPressed(){
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
}

bool BaseGame::isDOWNPressed(){
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

bool BaseGame::isLEFTPressed(){
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
}

bool BaseGame::isRIGHTPressed(){
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

bool BaseGame::isSPressed(){
	return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}

bool BaseGame::isWPressed(){
	return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
}

bool BaseGame::isSpacePressed(){
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void BaseGame::start(){
    while(isRunning()){
        eventPoll();
        update();
        clear();
        draw();
        display();
    }//end while
}

//private functions

void BaseGame::gluPerspectiveCompat( GLdouble fovY, GLdouble aspect, GLdouble zNear,
		GLdouble zFar ){
    GLdouble fW, fH;
    fH = tan( (fovY / 2) / 180 * 3.14 ) * zNear;
    fH = tan( fovY / 360 * 3.14 ) * zNear;
    fW = fH * aspect;
    glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}

void BaseGame::resizeWindow(unsigned int width,unsigned int height){
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspectiveCompat(45, width * 1.0 / height,0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}
