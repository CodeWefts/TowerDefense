#pragma once
#include "tower.hpp"
#include <vector>
#include "imgui_utils.hpp"




#define DEFexplosionTimer 2.f



using namespace std;

struct GameData;

struct Projectile
{
	bool explosion;
	float2 pos;
	float radiusImpact;
	float radiusOfExplosion;
	float velocityProjectile;
	float explosionTimer;


	Projectile(float2 missileStartPoint);
	Projectile();
	~Projectile();
	
};

class Explosif : public Tower
{


public:

	float2 basePosProjetile;
	Projectile projectile;

	
	void Upgrade(GameData& data) override;
	void TowerEffectRender(GameData& data) override;

	Explosif();
	Explosif(float2 missileStartPoint);
	~Explosif();

protected : 
	void Shoot(GameData& data) override;
	void Reset(GameData& data) override;

	

};