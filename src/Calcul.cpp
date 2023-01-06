#include<math.h>
#include "Calcul.hpp"


  

float determinantVector2( Vector2D v1,  Vector2D v2)
{
        
    float output = (v1.x * v2.y) - (v1.y * v2.x);

    return output;
}

float toNormVector(Vector2D v)
{
    return sqrtf(pow(v.x, 2) + pow(v.y, 2));
}

float getAngleVector2( Vector2D v1,  Vector2D v2)
{
    float output = 0;
    Vector2D vector1 = v1;
    Vector2D vector2 = v2;

    float normV1 = toNormVector(v1);
    float normV2 = toNormVector(v2);

    output = (((v1.x * v2.x) + (v1.y * v2.y)) / (normV1 * normV2));

    // Calculate dertimant to know if v1 is above or under v2
    // if v1 above output +
    // if v1 under output -

    float dertminent = determinantVector2(v1, v2);

    if (dertminent > 0)
        return acosf(output);
    else
    {
        return -acosf(output);
    }
}

float coefficendirector(Point2D A, Point2D B)
{
    float output = ((B.y - A.y) / (B.y - A.y));

    return output;
}

float distPoints2(const Point2D &p1, const Point2D &p2)
{
    // fabsf
    return fabsf(sqrtf(powf(p2.x - p1.x, 2) + powf(p2.y - p1.y, 2)));
}

Vector2D crossProduct2d(const Point2D &a, const Point2D &b)
{
    Vector2D t;
    Vector2D n;

    t.x = b.x - a.x;
    t.y = b.y - a.y;

    n.x = -t.y;
    n.y = t.x;

    return n;
}



Point2D Point2DInRange(Point2D p1, Point2D p2, float range)
{
    Point2D newPoint;

    newPoint.x = (p2.x - p1.x) * range + p1.x;
    newPoint.y = (p2.y - p1.y) * range + p1.y;

    return newPoint;
}

Point2D midPoint2D(Point2D p1, Point2D p2)
{
    Point2D midPoint;

    // X
    if (p1.x < p2.x)
        midPoint.x = p2.x - p1.x;

    if (p1.x > p2.x)
        midPoint.x = p1.x - p2.x;

    // Y
    if (p1.y < p2.y)
        midPoint.y = p2.y - p1.y;

    if (p1.y > p2.y)
        midPoint.y = p1.y - p2.y;

    midPoint.x /= 2;
    midPoint.y /= 2;

    midPoint.x = fabsf(midPoint.x);
    midPoint.y = fabsf(midPoint.y);

    return midPoint;
}



Point2D  RotationPoint2D(Point2D& P,const Point2D& R, float angle)
{
   
  
   
    // Calcule de la rotation de parametre angle 
    P.x = ( ( R.x * cosf(angle) ) - ( R.y * sinf(angle) ) ) ;
    P.y = ( ( R.x * sinf(angle) ) + ( R.y * cosf(angle) ) ) ;

    
    
    return P;
}

float getTriangleSurfacePoints2(const Point2D &p1, const Point2D &p2, const Point2D &p3)
{
    // calcule de la base

    //
    float a = distPoints2(p1, p2);
    float b = distPoints2(p1, p3);
    float c = distPoints2(p2, p3);

    float A = 0;
    float B = 0;
    float C = 0;

    if (a >= b)
    {
        A = a;
        if (b >= c)
        {
            B = b;
            C = c;
        }
        if (c >= b)
        {
            B = c;
            C = b;
        }
    }
    if (b >= a)
    {
        A = b;
        if (a >= c)
        {

            B = a;
            C = c;
        }
        if (C >= a)
        {
            B = c;
            C = a;
        }
    }
    if (c >= a)
    {
        A = c;
        if (a >= b)
        {
            B = b;
            C = a;
        }
        if (b >= a)
        {
            B = a;
            C = b;
        }
    }

    float Aire = (1.f / 4.f) * (sqrtf((A + (B + C)) * (C - (A - B)) * (C + (A - B)) * (A + (B - C)))); // racine de 3

    return Aire;
}

Point2D isobaryCenterTrianglePoints2(const Point2D &p1, const Point2D &p2, const Point2D &p3)
{
    /*float a = distPoints2(p1, p2);
    float b = distPoints2(p1, p3);
    float c = distPoints2(p2, p3);*/

    Point2D isobarycentre;

    isobarycentre.x = (p1.x + p2.x + p3.x);
    isobarycentre.x *= 1.0f / 3.0f;

    isobarycentre.y = (p1.y + p2.y + p3.y);
    isobarycentre.y *= 1.0f / 3.0f;

    return isobarycentre;
}


Point2D circumcenterTrianglePoints2(const Point2D &p1, const Point2D &p2, const Point2D &p3)
{
    Point2D output;
    float dia = 2.0f * (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));

    float xu = 1.0f / dia * (((pow(p1.x, 2.0) + pow(p1.y, 2.0)) * (p2.y - p3.y) + (pow(p2.x, 2.0) + pow(p2.y, 2.0)) * (p3.y - p1.y) + (pow(p3.x, 2.0) + pow(p3.y, 2.0)) * (p1.y - p2.y)));
    float yu = 1.0f / dia * (((pow(p1.x, 2.0) + pow(p1.y, 2.0)) * (p3.x - p2.x) + (pow(p2.x, 2.0) + pow(p2.y, 2.0)) * (p1.x - p3.x) + (pow(p3.x, 2.0) + pow(p3.y, 2.0)) * (p2.x - p1.x)));

    output.x = xu;
    output.y = yu;

    return output;
}


float *getTriangleSidesPoints2(const Point2D &p1, const Point2D &p2, const Point2D &p3)
{
    float *output = new float[3];

    output[0] = distPoints2(p1, p2);
    output[1] = distPoints2(p2, p3);
    output[2] = distPoints2(p3, p1);

    return output;
}





 
    /*
    * Vector2D normaliseVector(Vector2D Vector)
    {
        float normedVector = toNormVector(Vector);
       
        Vector.x = Vector.x / normedVector;
        Vector.y = Vector.y / normedVector;

        return Vector;
    }
    */

    float2 normaliseVector(float2 Vector)
    {
        float normedVector = toNormVector(Vector);

        Vector.x = Vector.x / normedVector;
        Vector.y = Vector.y / normedVector;

        return Vector;
    }


    

   

    float dotproductvector2(const Vector2D &v1, const Vector2D &v2)
    {
        float angle = atan2f(v2.y, v2.x) - atan2(v1.y, v1.x);
        float output = toNormVector(v1) * toNormVector(v2) * cos(angle);
        return output;
    }

    Vector2D getVectorFromPoint2d(Point2D &p1, Point2D &p2)
    {
        Vector2D vec(p2.x - p1.x, p2.y - p1.y);
        return vec;
    }

    Vector2D NormalVector(Vector2D vector)
    {
        Vector2D output;

        output.x = -vector.y;
        if (vector.x < 0)
            vector.x = -vector.x;

        output.y = vector.x;

        return output;
    }
    
