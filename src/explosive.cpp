#include "explosive.hpp"
#include "tower_game.hpp"
#include "calc.hpp"








void Explosive::Upgrade(GameData& data)
{

	if (data.player.coins >= this->cost * (currentLevel + 1) && this->currentLevel < this->maxLevel)
	{

		//Projectile Update
		this->currentLevel++;
		this->projectile.radiusOfExplosion += 5;
		this->damage *= 2;
		this->upgrade = false;
		
		
	}


}




Projectile::Projectile(float2 missileStartPoint)
{
	this->pos = missileStartPoint;
	this->radiusImpact = 5.f;
	this->velocityProjectile = 140.f;
	this->radiusOfExplosion = 50.f;
	this->explosionTimer = DEFexplosionTimer;
	this->explosion = false;
}
Projectile::Projectile()
{
	this->pos = {0,0};
	this->radiusImpact = 5.f;
	this->velocityProjectile = 140.f;
	this->radiusOfExplosion = 50.f;
	this->explosionTimer = DEFexplosionTimer;
	this->explosion = false;

}

Projectile::~Projectile()
{

}











void Explosive::Shoot(GameData& data)
{








	if (target == nullptr)
	{
		Reset(data);
	}
		
	if(projectile.explosion == false)
	{
		float2 vector = projectile.pos - target->pos;
		projectile.pos -= normaliseVector(vector) * projectile.velocityProjectile * data.deltatime;

		if (ColSStoSS2d(projectile.pos, projectile.radiusImpact, target->pos, projectile.radiusImpact))
		{
			projectile.explosion = true;



			for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
			{
				Enemy* current = *it;

				if (ColSStoSS2d(projectile.pos, projectile.radiusOfExplosion, current->pos, projectile.radiusImpact))
				{
					current->currentHealth -= damage;
				}

			}

		}
	}
	
	
	
	
	

	
}

void Explosive::Reset(GameData& data)
{
		
	projectile.explosionTimer = DEFexplosionTimer;
	projectile.explosion = false;
	projectile.pos = basePosProjetile;
	timer = 0;

	
}




void Explosive::TowerEffectRender(GameData& data)
{

	float2 TileMin = { (float)TileX, (float)TileY };
	float2 TileMax = { (float)TileX + 72 , (float)TileY + 72 };
	pos = { (float)TileX + data.map.Tilesize / 2, (float)TileY + data.map.Tilesize / 2 };
	texture = data.asset.textureTowerExplosive;
	
	
	data.dl->AddImage(texture.id, TileMin, TileMax, float2(0.f,0.f), float2(0.1f, 1.f));

	if (hasTarget)
	{
		data.dl->AddCircleFilled(projectile.pos, projectile.radiusImpact, IM_COL32(242, 62, 7, 255), 64);

		if (projectile.explosion && projectile.explosionTimer > 0)
		{
			
			float2 explosionPos = projectile.pos;
			data.dl->AddCircleFilled(explosionPos, projectile.radiusOfExplosion, IM_COL32(242, 62, 7, 255), 64);
			projectile.explosionTimer -= data.deltatime;
			std::cout << "Explosion timer = " << projectile.explosionTimer << std::endl;
			
	
			
			
			
		}
		else if (projectile.explosionTimer <= 0)
		{
			
			Reset(data);
			
		}
			
	}




}









Explosive::Explosive()
{
	this->name = "Explosive";
	this->type = EXPLOSIVE;
	this->TileX = 0;
	this->TileY = 0;
	this->cost = 50;
	this->range = 2; 
	this->damage = 50;
	this->fireRate = 0.5f;
	
	canonTexture = { 0 };



}
Explosive::Explosive(float2 missileStartPoint)
{
	this->name = "Explosive";
	this->type = EXPLOSIVE;
	this->TileX = 0;
	this->TileY = 0;
	this->cost = 50;
	this->range = 2; 
	this->damage = 50;
	this->fireRate = 2.f;
	basePosProjetile = missileStartPoint;
	projectile = Projectile(missileStartPoint);
}


Explosive::~Explosive()
{
}