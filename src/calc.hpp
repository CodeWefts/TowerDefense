#pragma once

#include <stdlib.h>
#include <math.h>

#include "float2.hpp"


static inline float2 operator+(float2 a, float2 b) { return { a.x + b.x, a.y + b.y }; }
static inline float2 operator-(float2 a, float2 b) { return { a.x - b.x, a.y - b.y }; }
static inline float2 operator*(float2 a, float2 b) { return { a.x * b.x, a.y * b.y }; }
static inline float2 operator*(float2 a, float b) { return { a.x * b, a.y * b }; }
static inline float2 operator/(float2 a, float2 b) { return { a.x / b.x, a.y / b.y }; }
static inline float2 operator/(float2 a, float b) { return { a.x / b, a.y / b }; }
static inline float2 operator-(float2 a ) { return { -a.x,-a.y }; }

/*
* static inline float2& operator+=(float2& a, float2 b) { return {a.x = a.x + b.x ,a.y = a.y + b.y};
static inline float2& operator*=(float2& a, float2 b) { a = a * b; return a; }
static inline float2& operator/=(float2& a, float2 b) { a = a / b; return a; }
*/

static inline ImVec2 operator+(ImVec2 a, float2 b) { return { a.x + b.x, a.y + b.y }; }

/*
* 
*/

static inline bool operator==(const float2& a, const float2& b) { if (a.x == b.x && a.y == b.y) { return true; } return false; }

static inline bool operator>(const float2& a, const float2& b) { if (a.x > b.x && a.y > b.y) { return true; } return false; }

static inline bool operator<(const float2& a, const float2& b) { if (a.x < b.x && a.y < b.y) { return true; } return false; }




float toNormVector(const float2& v);


float2  Rotationfloat2(float2& P, const float2& R, const float& angle );

    



float2 normaliseVector(float2& Vector);

        



bool ColSStoSS2d(const float2& C1, float rC1, const float2& C2, float rC2);


bool colPoint2dtoAABB2d(const float2& min, const float2& max, const float2& P);
    


float getModule(const float2& pos, const float2& postowe);




namespace Calc
{
    static const float GRAVITY = 9.80665f;
    static const float TAU = 6.28318530717958f;

    static inline float sign(float x) { return (x < 0.f) ? -1.f : 1.f; }

    static inline float dot(float2 a, float2 b) { return a.x * b.x + a.y * b.y; }
    static inline float lengthSq(float2 v) { return dot(v, v); }
    static inline float length(float2 v) { return sqrtf(lengthSq(v)); }

    static inline float lerp(float a, float b, float t)
    {
	    return (1.f-t) * a + t * b;
    }


    // Random utils, TODO: Move
    static inline float randomFloat(float min, float max)
    {
        float rand01 = (rand() % RAND_MAX) / (float)RAND_MAX;
        return lerp(min, max, rand01);
    }

    static inline float max(float x, float maxValue)
    {
        return (x > maxValue) ? x : maxValue;
    }

    static inline float min(float x, float minValue)
    {
        return (x < minValue) ? x : minValue;
    }

    static inline float clamp(float x, float minValue, float maxValue)
    {
        return min(max(x, minValue), maxValue);
    }
}