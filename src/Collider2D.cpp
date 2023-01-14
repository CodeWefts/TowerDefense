#include"Collider2D.hpp"





bool colPoint2dtoSS2d(const Point2D& p ,const Point2D& C, float rC )
{
    
    if( ( pow(p.x-C.x,2) + pow(p.y-C.y,2) ) < pow(rC,2))
    {
        return true ;
    }

    return false ;
}

bool colSStoSS2d( Point2D C1, float rC1 ,Point2D C2, float rC2)
{   if( ( pow(C1.x-C2.x,2) + pow(C1.y-C2.y,2) ) <  ( pow(rC1,2) + pow(rC2,2) ) )
    {
        return true ;
    }

    return false ;
}



bool colbetween2AABBS (const Point2D& Amin , const Point2D& Amax , const Point2D& Bmin , const Point2D& Bmax )
{

    if
    (
        Amin.x < Bmax.x && Amax.x > Bmin.x && 
        Amin.y < Bmax.y && Amax.y > Bmin.y 
    )
    return true ;

    return false ;

}

bool colPoint2dtoAABB2d(float2& min, float2& max, float2& P)
{
    if
        (
            (min.x < P.x && max.x > P.x)
            &&
            (min.y < P.y && max.y > P.y)
            )
    {
        return true;
    }
    else
    {
        return false;

    }

    return false;

}


float minimum(float a, float b)
{
    if (a < b)
        return a;
    if (b < a)
        return b;

    return -1;
}

/* Return the Max value between 2 float*/
float maximum(float a, float b)
{
    if (a > b)
        return a;
    if (b > a)
        return b;


}




bool colSStoAABB(float2& Amin, float2& Amax, float2& C, float& rC)
{

    float2 P;

    P.x = maximum(Amin.x, minimum(C.x, Amax.x));
    P.y = maximum(Amin.x, minimum(C.y, Amax.y));


    if (powf((P.x - C.x), 2) + powf((P.y - C.y), 2) < sqrtf(rC))
    {
        return true;
    }

    return false;
}







float getMinimumForNormal(Point2D* point , const Vector2D& normal,int nbrpoint)
{
    // Return Minimum for a normal
    Point2D Origine = {0,0};
    float* dotproduct = new float[nbrpoint];
    float min = dotproductvector2(getVectorFromPoint2d(Origine,point[0]),normal);
   
    
    
    for (int i = 0; i < nbrpoint; i++)
    {
        dotproduct[i] = dotproductvector2(getVectorFromPoint2d(Origine,point[i]),normal);
        if(dotproduct[i] < min)
        min = dotproduct[i];
        
    }  
    return min ;

}

float getMaximumForNormal(Point2D* point ,const Vector2D& normal,int nbrpoint)
{
    // Return Minimum for a normal
    Point2D Origine = {0,0};
    float* dotproduct = new float[nbrpoint];
    float max = dotproductvector2(getVectorFromPoint2d(Origine,point[0]),normal);;
    
    
    for (int i = 0; i < nbrpoint; i++)
    {
        dotproduct[i] = dotproductvector2(getVectorFromPoint2d(Origine,point[i]),normal);
        if(dotproduct[i] > max)
        max = dotproduct[i];
        
    }  
    return max ;

}



// Work For concav Polygone
bool theoremeSAT(Point2D* figureA , int nbrA , Point2D* figureB  ,int nbrB )
{

    Vector2D* figureVectorA = new Vector2D[nbrA];
    Vector2D* figureVectorB = new Vector2D[nbrB];
    Vector2D* figureVectorNormalA = new Vector2D[nbrA];
    Vector2D* figureVectorNormalB = new Vector2D[nbrB];


    Vector2D* figureVectorA2 = new Vector2D[nbrA];
    Vector2D* figureVectorB2 = new Vector2D[nbrB];

    float Amin =  0 ;
    float Amax = 0 ;
    float Bmin =  0;
    float Bmax = 0;


    float Amin2 =  0 ;
    float Amax2 = 0 ;
    float Bmin2 =  0;
    float Bmax2 = 0;

  
    if(nbrB <= nbrA)
    for (int i = 0; i < nbrA; i++)
    {
        figureVectorA[i] = getVectorFromPoint2d(figureA[i],figureA[(i + 1) % nbrA]);
        figureVectorNormalA[i] = NormalVector(figureVectorA[i]);
        figureVectorNormalA[i] = normaliseVector(figureVectorNormalA[i]);

        figureVectorB2[i] = getVectorFromPoint2d(figureB[i],figureB[(i + 1) % nbrB]);

        Amin = getMinimumForNormal(figureA,figureVectorNormalA[i],nbrA);
        Amax = getMaximumForNormal(figureA,figureVectorNormalA[i],nbrA);
        Bmin = getMinimumForNormal(figureB,figureVectorNormalA[i],nbrB);
        Bmax = getMaximumForNormal(figureB,figureVectorNormalA[i],nbrB);

        if(Amin >= Bmax || Bmin  >= Amax)
        return false;
    }

    if(nbrB > nbrA)
    for (int i = 0; i < nbrB; i++)
    {
        figureVectorB[i] = getVectorFromPoint2d(figureB[i],figureB[(i + 1) % nbrB]);
        figureVectorNormalB[i] = NormalVector(figureVectorB[i]);
        figureVectorNormalB[i] = normaliseVector(figureVectorNormalB[i]);

        figureVectorA2[i] = getVectorFromPoint2d(figureA[i],figureA[(i + 1) % nbrA]);



        Amin2 = getMinimumForNormal(figureA,figureVectorNormalB[i],nbrA);
        Amax2 = getMaximumForNormal(figureA,figureVectorNormalB[i],nbrA);
        Bmin2 = getMinimumForNormal(figureB,figureVectorNormalB[i],nbrB);
        Bmax2 = getMaximumForNormal(figureB,figureVectorNormalB[i],nbrB);

        
        if(Amin2 >= Bmax2 || Bmin2  >= Amax2)
        return false;
    }
    
   
    return true;
}
