
#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include "vector3.hpp"  

/*
 * Base object for each and every gameobject in Inferno
 * UI elements excluded.
 */

class Object {

public:
    // Draw the objeect on the screen.
    virtual void Draw(void) = 0;
    // Update the position and location of the object
    virtual void Update(float dt) = 0;
    // Implement what happens when the object is hit.
    virtual void Hit(void) = 0;
    virtual Vector3 GetPosition(void) const = 0;
    virtual float GetRadius(void) const = 0;
    // Change the ID to another. Should still denote the array index.
    virtual void ChangeID(int id) = 0;
    // Should return an ID interger that denotes the array index
    virtual int GetID(void) const = 0;
    virtual ~Object(void) {};
    // Should return an integer that gives the type of the object
    virtual int getTypeInt(void) { return 0; }
};

#endif