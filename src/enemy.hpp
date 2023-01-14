#pragma once
#include<iostream>
#include "entity.hpp"
#include "imgui_utils.hpp"

struct GameData;


#define IsIncenter 4.0


enum PathNbr : int
{
	Path0 = 0,
	Path1,
	Path2
};




class enemy : public entity
{
public:

	int maxHealt;
	int currentHealth;
	int damageToPlayer;
	int path;

	std::string name;
	Texture texture;
	float velocity;

	
	int destinationIndex;
	int roadChoice;

	float2 healBoxSize;

	float2 ReturnCheckPoint(GameData& data, int& checkPoint);


	void pathFollow(GameData& data,bool& erase);
	void DrawSlider(ImDrawList& dl);
	virtual void DrawDebug(ImDrawList& dl);
	virtual void UpdateEnemy(GameData& data,bool& erase);

	virtual void Heal(GameData& data);


	 enemy();
	 ~enemy();

private:

};

