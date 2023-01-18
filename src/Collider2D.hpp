#pragma once
#include<iostream>
#include<math.h>

#include"Calcul.hpp"

bool colPoint2dtoSS2d(const float2& p, const float2& C, float rC);

bool colSStoSS2d(const float2& C1, float rC1, const float2& C2, float rC2);

bool colPoint2dtoAABB2d(const float2& min, const float2& max, const float2& P);


bool colSStoAABB(float2& Amin, float2& Amax, float2& C, float& rC);

bool colbetween2AABBS(const float2& Amin, const float2& Amax, const float2& Bmin, const float2& Bmax);




