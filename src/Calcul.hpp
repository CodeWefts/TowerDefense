#pragma once
#include"Point2D.hpp"
#include"Vector2D.hpp"




float coefficendirector(Point2D A , Point2D B);
float getTriangleSurfacePoints2(const Point2D& p1, const Point2D& p2, const Point2D& p3);
float distPoints2(const Point2D& p1, const Point2D& p2);




Point2D Point2DInRange(Point2D p1, Point2D p2, float range);
Point2D circumcenterTrianglePoints2(const Point2D& p1, const Point2D& p2, const Point2D& p3);
Point2D isobaryCenterTrianglePoints2(const Point2D& p1, const Point2D& p2, const Point2D& p3);
Point2D midPoint2D(Point2D p1 , Point2D p2 );
Point2D  RotationPoint2D(Point2D& P,const Point2D& R, float angle);

Vector2D crossProduct2d(const Point2D& a , const Point2D& b );

float toNormVector(Vector2D v);

float determinantVector2( Vector2D v1,  Vector2D v2);


float dotproductvector2(const Vector2D &v1, const Vector2D &v2);
Vector2D getVectorFromPoint2d(Point2D &p1, Point2D &p2);
//Vector2D normaliseVector(Vector2D Vector);
float2 normaliseVector(float2 Vector);

Vector2D NormalVector(Vector2D vector);





