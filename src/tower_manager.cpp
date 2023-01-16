#include "tower_manager.hpp"
#include "tower_game.hpp"















void TowerManager::UpdateTower(GameData& data)
{
	
	for (auto it = data.towerVector.begin(); it != data.towerVector.end(); it++)
	{
		Tower* currentTower = *it;

		currentTower->TargetEnemy(data);
	}
   
    




}




TowerManager::TowerManager()
{
}

TowerManager::~TowerManager()
{
}