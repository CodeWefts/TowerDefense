#pragma once
#include<iostream>
#include<math.h>

#include"Calcul.hpp"

bool colPoint2dtoSS2d(const Point2D& p, const Point2D& C, float rC);

bool colSStoSS2d(const Point2D& C1, float rC1, const Point2D& C2, float rC2);

bool colPoint2dtoAABB2d(const float2& min, const float2& max, const float2& P);


bool colSStoAABB(float2& Amin, float2& Amax, float2& C, float& rC);

bool colbetween2AABBS(const Point2D& Amin, const Point2D& Amax, const Point2D& Bmin, const Point2D& Bmax);




