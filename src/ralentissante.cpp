#include "ralentissante.hpp"
#include "tower_game.hpp"





void Ralentissante::Upgrade(GameData& data)
{
	if (data.player.coins >= this->cost * (currentLevel + 1) && this->currentLevel < this->maxLevel)
	{
		this->currentLevel++;
		data.player.coins -= this->cost  * this->currentLevel++;
		this->baseDamage *= 1.3;
		this->maxDamage *= 1.2;
		this->range *= 1.2;
		this->slowingValue *= 1.2;
		this->maxDebuffVelocity *= 1.3;

	}

}



void Ralentissante::Shoot(GameData& data)
{
	if (this->maxDamage > this->damage)
	{
		this->damage += (incrementDamage + data.deltatime);
	}

	if (this->target->velocity > this->maxDebuffVelocity)
	{
		this->target->velocity -= (slowingValue + data.deltatime);
	}

	if (beamValue < maxBeamValue)
	{
		this->beamValue += (2 + data.deltatime);
	}

	this->target->currentHealth -= this->damage;
	this->timer = 0;
}


void Ralentissante::Reset(GameData& data)
{
	this->damage = baseDamage;
	this->beamValue = beamBaseValue;

}


void Ralentissante::TowerEffectRender(GameData& data)
{

	ImVec2 TileMin = { (float)TileX, (float)TileY - 102 };
	ImVec2 TileMax = { (float)TileX + 72 , (float)TileY + 72 };
	pos = { (float)TileX + data.map.Tilesize / 2, (float)TileY + data.map.Tilesize / 2 };
	texture = data.asset.texureSlowing;
	canonTexture = { 0 };
	data.dl->AddImage(texture.id, TileMin, TileMax);


	if (hasTarget)
	{
		data.dl->AddCircleFilled(float2(pos.x, pos.y - 100), 6.f, IM_COL32(50, 139, 255, 255), 30);

		data.dl->AddLine(float2(pos.x, pos.y - 100), target->pos, IM_COL32(50, 139, 255, 255), beamValue);

	}

}








Ralentissante::Ralentissante()
{
	this->name = "Ralentissante";
	this->type = RALENTISSANTE;
	this->TileX = 0;
	this->TileY = 0;
	this->cost = 150;
	this->range = 2; // range per tile
	this->damage = 5;
	this->fireRate = 3.f;
	this->beamBaseValue = 5.f;
	this->maxDebuffVelocity = 40.f;
	this->slowingValue = 10;
	this->maxBeamValue = 20.f;
	this->incrementDamage = 10;
	this->maxDamage = 300;


}

Ralentissante::~Ralentissante()
{

}