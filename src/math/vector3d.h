#ifndef __VECTOR_3D_H__
#define __VECTOR_3D_H__

#include <cmath>

class Vector3D {
    public:
        union {
            struct { float x, y, z; };
            struct { float r, g, b; };
            float v[3];
        };
        
        Vector3D();
        Vector3D(float x,float y,float z);
        Vector3D(float val);
        Vector3D(const Vector3D& v);
        Vector3D(const Vector3D& from,const Vector3D& to);
        
        Vector3D& operator=(const Vector3D& v);
        Vector3D& operator+=(const Vector3D& v);
        Vector3D operator+(const Vector3D& v) const;        
        Vector3D& operator-=(const Vector3D& v);
        Vector3D operator-(const Vector3D& v) const;        
        Vector3D& operator*=(const float a);
        Vector3D operator*(const float a)const;
        Vector3D operator*(const Vector3D& v) const;
        Vector3D& operator/=(const float a);
        Vector3D operator/(const float a)const;
        friend Vector3D operator*(const float a, const Vector3D& v);

        static Vector3D zero();
        static Vector3D abs(Vector3D v);
        Vector3D crossProduct(const Vector3D& v) const;
        float length() const;
        float dot(const Vector3D& v) const;
        Vector3D& normalize();
};

#endif 
