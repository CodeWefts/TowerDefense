#pragma once

#include<vector>
#include"wave.hpp"



using namespace std;


struct GameData;



class Level
{
public:

	int maxWave;
	int nbrOfWave;
	int currentWave;
	int nbrOfRoad;	

	float timerBetweenWave;

	vector<EnemyWave> waves;

	Level(const int& nbrWave , const int& nbrOfRoad);
	Level();
	~Level();

private:

};


