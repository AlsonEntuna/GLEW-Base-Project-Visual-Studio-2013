#ifndef BASEOBJECT_H
#define	BASEOBJECT_H

#include <vector>
#include <fstream>
//#include <SFML/OpenGL.hpp>

class BaseObject{
    public:
        virtual void draw() = 0;
        void setX(float val);
        void setY(float val);
        void setZ(float val);
        float getX();
        float getY();
        float getZ();
	protected:
        float x, y, z;
};

#endif /* BASEOBJECT_H */
