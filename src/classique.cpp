#include "classique.hpp"
#include "tower_game.hpp"






void Classique::Shoot(GameData& data)
{
   
    this->target->currentHealth -= this->damage;
    this->timer = 0;

}

void Classique::TowerEffectRender(GameData& data)
{

	float2 tileMin = { (float)TileX , (float)TileY };
	float2 tileMax = { (float)TileX + 72, (float)TileY + 72 };
	pos = { (float)TileX + data.map.Tilesize / 2, (float)TileY + data.map.Tilesize / 2 };
	texture = data.asset.textureTowerClassicalBase;
	canonTexture = data.asset.textureTowerClassicalCanon;
	data.dl->AddImage(texture.id, tileMin, tileMax);


	if (hasTarget == true)
	{
		float2 targetVector = target->pos - pos;
		// Fond angle between enemy and turret
		angle = -atan2f(targetVector.x, targetVector.y);
	}
	float2 Point4[4] =
	{
	 tileMin,float2(tileMax.x,tileMin.y),tileMax , float2(tileMin.x,tileMax.y)
	};
	for (int i = 0; i < 4; i++)
	{
		// add point Rotation
		Point4[i] = Rotationfloat2(Point4[i], pos, angle);
	}

	data.dl->AddImageQuad(canonTexture.id, Point4[3], Point4[2], Point4[1], Point4[0]);

}













Classique::Classique()
{
    this->name = "Classique";
    this->type = CLASSIQUE;
    this->TileX = 0;
    this->TileY = 0;
    this->cost = 25;
    this->range = 1;// range per tile
    this->damage = 30;
    this->fireRate = 0.5f;
    this->angle = 0;
}

Classique::~Classique() 
{

}