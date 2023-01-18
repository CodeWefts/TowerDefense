#include "explosive.hpp"
#include "tower_game.hpp"
#include "calc.hpp"
#include "Calcul.hpp"
#include "Collider2D.hpp"


void Explosive::Shoot(GameData& data)
{



	float2 vector = firstMissile - target->pos;
	//std::cout << vector.x << " , " << vector.y << std::endl;
	firstMissile -= normaliseVector(vector) * velocityMissile * data.deltatime;

	if (colSStoSS2d(firstMissile, rayonOfMissile, target->pos, rayonOfMissile))
	{
		for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
		{
			Enemy* current = *it;

			if (colSStoSS2d(firstMissile, rayonOfExplosion, current->pos, rayonOfMissile))
			{
				explosion = true;
				std::cout << damage << std::endl;
				current->currentHealth -= damage;
				Reset(data);


			}

		}

	}
}

void Explosive::Reset(GameData& data)
{
	this->firstMissile = this->basePosMissile;
	timer = 0;

	/*std::cout << "base = " << basePosMissile.x << " , " << basePosMissile.y << std::endl;
	std::cout << "base = " << firstMissile.x << " , " << firstMissile.y << std::endl;
	*/
}




void Explosive::TowerEffectRender(GameData& data)
{

	ImVec2 TileMin = { (float)TileX, (float)TileY };
	ImVec2 TileMax = { (float)TileX + 72 , (float)TileY + 72 };
	pos = { (float)TileX + data.map.Tilesize / 2, (float)TileY + data.map.Tilesize / 2 };
	texture = data.asset.texureSlowing;
	canonTexture = { 0 };
	data.dl->AddImage(texture.id, TileMin, TileMax);

	if (hasTarget)
	{
		data.dl->AddCircleFilled(firstMissile, rayonOfMissile, IM_COL32(242, 62, 7, 255), 64);

		if (explosion)
		{


			float2 explosionPos = firstMissile;
			data.dl->AddCircleFilled(explosionPos, rayonOfExplosion, IM_COL32(242, 62, 7, 255), 64);
			explosion = false;


		}
		std::cout << explosion << std::endl;
	}




}









Explosive::Explosive()
{
	this->name = "Explosive";
	this->type = EXPLOSIVE;
	this->TileX = 0;
	this->TileY = 0;
	this->cost = 50;
	this->range = 2; // range per tile
	this->damage = 10;
	this->fireRate = 0.5f;
	this->rayonOfMissile = 5.f;
	this->firstMissile = { 0 ,0 };
	this->velocityMissile = 50.f;
	this->rayonOfExplosion = 50.f;
	this->explosion = false;
	//this->missile = nullptr;

}
Explosive::Explosive(float2 missileStartPoint)
{
	this->hit = false;
	this->name = "Explosive";
	this->type = EXPLOSIVE;
	this->TileX = 0;
	this->TileY = 0;
	this->cost = 50;
	this->range = 2; // range per tile
	this->damage = 10;
	this->fireRate = 2.f;
	this->rayonOfMissile = 5.f;
	this->basePosMissile = { missileStartPoint };
	this->firstMissile = basePosMissile;
	this->velocityMissile = 100.f;
	rayonOfExplosion = 50.f;
	explosion = false;

}


Explosive::~Explosive()
{

}