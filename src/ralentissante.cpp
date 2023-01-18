#include "ralentissante.hpp"
#include "tower_game.hpp"




void Ralentissante::Shoot(GameData& data)
{
	
	this->damage += (5 + data.deltatime);
	/*
	/std::cout << "has target  = " << this->hasTarget << std::endl;
	std::cout <<"target  = " << &this->target << std::endl;
	std::cout << " damage = " << this->damage << std::endl;

	//this->target->velocity -= (10 + data.deltatime);
	*/
	this->beamValue += (2 + data.deltatime);
	this->target->currentHealth -= this->damage;
	this->timer = 0;
}
void Ralentissante::Reset(GameData& data)
{
	
	if (hasTarget == false)
	{
			std::cout << "has target  = " << this->hasTarget << std::endl;
			this->damage = baseDamage;
			this->beamValue = beamBaseValue;

	}
	
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
	this->type = 3;
	this->TileX = 0;
	this->TileY = 0;
	this->cost = 150;
	this->range = 2; // range per tile
	this->damage = 10;
	this->fireRate = 1.f;
	this->beamBaseValue = 5.f;

}

Ralentissante::~Ralentissante()
{

}