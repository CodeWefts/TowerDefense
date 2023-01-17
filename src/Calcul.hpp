#pragma once
#include"Point2D.hpp"
#include"Vector2D.hpp"




float coefficendirector(float2 A, float2 B);
float getTriangleSurfacePoints2(const float2& p1, const float2& p2, const float2& p3);
float distPoints2(const float2& p1, const float2& p2);



float2 float2InRange(float2 p1, float2 p2, float range);
float2 circumcenterTrianglePoints2(const float2& p1, const float2& p2, const float2& p3);
float2 isobaryCenterTrianglePoints2(const float2& p1, const float2& p2, const float2& p3);
float2 midfloat2(float2 p1, float2 p2);



float2  Rotationfloat2(float2 P, const float2 R, float angle);

float2 crossProduct2d(const float2& a, const float2& b);

float toNormVector(float2 v);

float determinantVector2(float2 v1, float2 v2);


float dotproductvector2(const float2& v1, const float2& v2);
float2 getVectorFromPoint2d(float2& p1, float2& p2);
//float2 normaliseVector(float2 Vector);
float2 normaliseVector(float2 Vector);

float2 NormalVector(float2 vector);







