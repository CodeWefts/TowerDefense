#include "SlowingTurret.hpp"
#include "tower_game.hpp"





void SlowingTower::Upgrade(GameData& data)
{
	if (data.player.coins >= this->cost * (currentLevel + 1) && this->currentLevel < this->maxLevel)
	{
		data.player.coins -= int(this->cost * this->currentLevel++);
		this->currentLevel++;
		this->fireRate /= 1, 25;
		this->baseDamage *= 1.3;
		this->maxDamage *= 1.2;
		this->range *= 1.2;
		this->slowingValue *= 1.2;
		this->maxDebuffVelocity *= 1.3;

	}

}



void SlowingTower::Shoot(GameData& data)
{

	// while damage is below max damage increase damge every second
	if (this->maxDamage > this->damage)
	{
		this->damage += (incrementDamage + data.deltatime);
	}

	// while target velocity is below max debuff velocity slow them every second
	if (this->target->velocity > this->maxDebuffVelocity)
	{
		this->target->velocity -= float(slowingValue + data.deltatime);
	}

	// increase beamValue
	if (beamValue < maxBeamValue)
	{
		this->beamValue += (2 + data.deltatime);
	}

	this->target->currentHealth -= int(this->damage);
	this->timer = 0;
}

//Reset values if has no target 
void SlowingTower::Reset(GameData& data)
{
	this->damage = baseDamage;
	this->beamValue = beamBaseValue;

}



// Renderer Effect For Slowing One
void SlowingTower::TowerEffectRender(GameData& data)
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

		data.dl->AddLine(float2(pos.x, pos.y - 100), target->pos, IM_COL32(50, 139, 255, 255), float(beamValue));

	}

}








SlowingTower::SlowingTower()
{
	this->name = "SlowingTurret";
	this->type = SLOWINGTURRET;
	this->TileX = 0;
	this->TileY = 0;
	this->cost = 150;
	this->range = 2; 
	this->damage = 10;
	this->fireRate = 1.25f;
	this->beamBaseValue = 5.f;
	this->maxDebuffVelocity = 40.f;
	this->slowingValue = 10;
	this->maxBeamValue = 20.f;
	this->incrementDamage = 10;
	this->maxDamage = 300;


}

SlowingTower::~SlowingTower()
{
	delete target;
}