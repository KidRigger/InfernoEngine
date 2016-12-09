//--------------------------------------------------------------------------------
//
//  vector3.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/8/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#include "vector3.hpp"
#include <cmath>

// ---------- CTORS ---------- //

Vector3::Vector3(void){
    ;
}

Vector3::Vector3 (float x, float y, float z){
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
}

Vector3::Vector3 (const Vector3& copy_from){
    vec[0] = copy_from.GetX();
    vec[1] = copy_from.GetY();
    vec[2] = copy_from.GetZ();
}

void Vector3::operator=(const Vector3 &copy_from){
    vec[0] = copy_from.GetX();
    vec[1] = copy_from.GetY();
    vec[2] = copy_from.GetZ();
}

// ---------- Getters ---------- //

float Vector3::GetX(void) const {
    return vec[0];
}

float Vector3::GetY(void) const {
    return vec[1];
}

float Vector3::GetZ(void) const {
    return vec[2];
}

void Vector3::SetPosition(float x, float y, float z){
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
}

// ---------- Operators ---------- //

Vector3 Vector3::operator +(const Vector3 &other) const {
    return Vector3(this->vec[0] + other.GetX(),
                   this->vec[1] + other.GetY(),
                   this->vec[2] + other.GetZ());
}

Vector3 Vector3::operator -(const Vector3 &other) const {
    return Vector3(this->vec[0] - other.GetX(),
                   this->vec[1] - other.GetY(),
                   this->vec[2] - other.GetZ());
}

Vector3 Vector3::operator *(const float &scalar) const {
    return Vector3(this->vec[0]*scalar,
                   this->vec[1]*scalar,
                   this->vec[2]*scalar);
}

Vector3 operator *(const float &scalar, const Vector3& vector) {
    return Vector3(vector.GetX()*scalar,
                   vector.GetY()*scalar,
                   vector.GetZ()*scalar);
}

Vector3 Vector3::operator /(const float& scalar) const {
    return Vector3(this->vec[0]/scalar,
                   this->vec[1]/scalar,
                   this->vec[2]/scalar);
}

bool Vector3::operator ==(const Vector3& other) const {
    return (this->vec[0] == other.GetX()
            && this->vec[1] == other.GetY()
            && this->vec[2] == other.GetZ());
}

// ---------- Processed ---------- //

float Vector3::SqrMagnitude(void) const {
    return vec[0]*vec[0] + vec[1]*vec[1] * vec[2]*vec[2];
}

float Vector3::Magnitude(void) const {
    return sqrt(this->SqrMagnitude());
}

Vector3 Vector3::Normalized(void) const {
    float mag = this->Magnitude();
    return (*this)/mag;
}

void Vector3::Normalize(void){
    float mag = this->Magnitude();
    vec[0] /= mag;
    vec[1] /= mag;
    vec[2] /= mag;
}

std::array<float, 3> Vector3::Angle(void) {
    float mag = this->Magnitude();
    return std::array<float,3> {acosf(vec[0]/mag),
                                acosf(vec[1]/mag),
                                acosf(vec[2]/mag)};
}

// ---------- Rotations ----------- //
void Vector3::RotateAroundX(const float &angle){
    float y = vec[1]*cosf(angle)-vec[2]*sinf(angle);
    vec[2] = vec[1]*sinf(angle)+vec[2]*cosf(angle);
    vec[1] = y;
}

void Vector3::RotateAroundY(const float &angle){
    float x = vec[0]*cosf(angle)-vec[2]*sinf(angle);
    vec[2] = vec[0]*sinf(angle)+vec[2]*cosf(angle);
    vec[0] = x;
}

void Vector3::RotateAroundZ(const float &angle){
    float x = vec[0]*cosf(angle)-vec[1]*sinf(angle);
    vec[1] = vec[0]*sinf(angle)+vec[1]*cosf(angle);
    vec[0] = x;
}

// ---------- Products ---------- //

float Dot(const Vector3& A, const Vector3& B){
    float product = 0;
    for(int i = 0; i != 3; ++i){
        product += A.vec[i]*B.vec[i];
    }
    return product;
}

Vector3 Cross(const Vector3& A, const Vector3& B){
    return Vector3(A.vec[1]*B.vec[2] - B.vec[1]*A.vec[2],
                   A.vec[2]*B.vec[0] - B.vec[2]*A.vec[0],
                   A.vec[0]*B.vec[1] - B.vec[0]*A.vec[1]);
}

//--------------------------------------------------------------------------------
