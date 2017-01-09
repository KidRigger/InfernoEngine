//--------------------------------------------------------------------------------
//
//  vector3.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/8/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#ifndef vector3_hpp
#define vector3_hpp

#define PI 3.14145926535897932384626433

#include <array>
#include <iostream>

class Vector3 {
public:
    
    //ctor
    Vector3 (void);
    Vector3 (float x, float y, float z = 0);
    Vector3 (const Vector3 &copy_from);
    void operator =(const Vector3 &copy_from);
    
    //getters and setters
    float GetX(void) const;
    float GetY(void) const;
    float GetZ(void) const;
    void SetValue(float x, float y, float z);
    
    //operators
    Vector3 operator +(const Vector3 &other) const;
    Vector3 operator -(const Vector3 &other) const;
    Vector3 operator *(const float &scalar) const;
    friend std::ostream& operator <<(std::ostream& output, const Vector3& self);
    friend Vector3 operator *(const float &scalar, const Vector3& vector);
    Vector3 operator /(const float &scalar) const;
    bool operator ==(const Vector3& other) const;

    //qualitative info
    float SqrMagnitude(void) const;
    float Magnitude(void) const;
    Vector3 Normalized(void) const;
    void Normalize(void);
    std::array<float,3> Angle(void);
    
    //2D rotations
    void RotateAroundX(const float& angle);
    void RotateAroundY(const float& angle);
    void RotateAroundZ(const float& angle);
    
    //products
    static float Dot(const Vector3& A, const Vector3& B);
    static Vector3 Cross(const Vector3& A, const Vector3& B);
    
    static Vector3 RandomDirection(void);
    static Vector3 RandomInRange(float max, float min = 0);
    
    static Vector3 Lerp(const Vector3& A, const Vector3& B, float factor);
    
private:
    float vec [3];
};

#endif /* vector3_hpp */

//--------------------------------------------------------------------------------