
#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include "vector3.hpp"  

class Object {

public:
    virtual void Draw(void) = 0;
    virtual void Update(float dt) = 0;
    virtual void Hit(void) = 0;
    virtual Vector3 GetPosition(void) const = 0;
    virtual float GetRadius(void) const = 0;
    virtual void ChangeID(int id) = 0;
    virtual int GetID(void) const = 0;
    virtual ~Object(void) {};
    virtual int getTypeInt(void) { return 0; }
};

#endif