#include "vector3d.h"

Vector3D::Vector3D() {
    x = 0;
    y = 0;
    z = 0;
}

Vector3D::Vector3D(float x_,float y_,float z_) {
    x = x_;
    y = y_;
    z = z_;
}

Vector3D::Vector3D(float val) {
    x = val;
    y = val;
    z = val;
}

Vector3D::Vector3D(const Vector3D& v) {
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector3D::Vector3D(const Vector3D& from,const Vector3D& to) {
    x = to.x - from.x;
    y = to.y - from.y;
    z = to.z - from.z;
}

Vector3D& Vector3D::operator=(const Vector3D& v) {
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vector3D& Vector3D::operator+=(const Vector3D& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D& v) const {
    Vector3D t = *this;
    t += v;
    return t;
}

Vector3D& Vector3D::operator-=(const Vector3D& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector3D Vector3D::operator-(const Vector3D& v) const {
    Vector3D t = *this;
    t -= v;
    return t;
}

Vector3D& Vector3D::operator*=(const float a) {
    x *= a;
    y *= a;
    z *= a;
    return *this;
}

Vector3D Vector3D::operator*(const float a) const {
    Vector3D t = *this;
    t *= a;
    return t;
}

Vector3D operator*(const float a ,const Vector3D& v) {
    return Vector3D(v.x*a,v.y*a,v.z*a);
}

Vector3D Vector3D::operator*(const Vector3D& v) const {
    return Vector3D(x*v.x, y*v.y, z*v.z);
}

Vector3D& Vector3D::operator/=(const float a) {
    x /= a;
    y /= a;
    z /= a;
    return *this;
}

Vector3D Vector3D::operator/(const float a) const {
    Vector3D t = *this;
    t /= a;
    return t;
}

Vector3D Vector3D::crossProduct(const Vector3D& v) const {
    Vector3D t;
    t.x = y*v.z - z*v.y;
    t.y = z*v.x - x*v.z;
    t.z = x*v.y - y*v.x;
    return t;
}

Vector3D Vector3D::abs(Vector3D v) {
    v.x = fabs(v.x);
    v.y = fabs(v.y);
    v.z = fabs(v.z);
    return v;
}

float Vector3D::dot(const Vector3D& v) const {
    return x*v.x + y*v.y + z*v.z;
}

float Vector3D::length() const {
    return sqrt(x*x + y*y + z*z);
}

Vector3D& Vector3D::normalize() {
    (*this) /= length();
    return (*this);
}

Vector3D Vector3D::zero() {
    return Vector3D(0, 0, 0);
}
