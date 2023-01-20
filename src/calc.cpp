#include "calc.hpp"


float2  Rotationfloat2(float2& P, const float2& R, const float& angle)
{
    
        float2 tmprR = R;
        float2 tmprP = P;

        float2 p_R = { tmprP.x - R.x , tmprP.y - R.y };

        P.x = ((p_R.x * cosf(angle)) - (p_R.y * sinf(angle)));
        P.y = ((p_R.x * sinf(angle)) + (p_R.y * cosf(angle)));

        P.x += tmprR.x;
        P.y += tmprR.y;

        return P;

}


float getModule(const float2& pos, const float2& postower)
{
    float2 diff = postower - pos;

    return sqrtf(pow(diff.x, 2.f) + powf(diff.y, 2.f));
}


float2 normaliseVector(float2& Vector)
{
    float normedVector = toNormVector(Vector);

    Vector.x = Vector.x / normedVector;
    Vector.y = Vector.y / normedVector;

    return Vector;
}


bool ColSStoSS2d(const float2& C1, float rC1, const float2& C2, float rC2)
{
    if ((pow(C1.x - C2.x, 2) + pow(C1.y - C2.y, 2)) < (pow(rC1, 2) + pow(rC2, 2)))
    {
        return true;
    }

    return false;
}

bool colPoint2dtoAABB2d(const float2& min, const float2& max, const float2& P)
{
    if
        (
            (min.x <= P.x && max.x >= P.x)
            &&
            (min.y <= P.y && max.y >= P.y)
            )
    {
        return true;
    }


    return false;
}




float toNormVector(const float2& v)
{
    return sqrtf(pow(v.x, 2) + pow(v.y, 2));
}