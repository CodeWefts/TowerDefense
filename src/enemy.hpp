#pragma once
#include<iostream>
#include "entity.hpp"
#include "imgui_utils.hpp"

struct GameData;


#define IsIncenter 5.0


enum PathNbr : int
{
	Path1 = 1,
	Path2,
	Path3
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
	float offsetCheckPoint;

	char baseChekcpoint;
	char destination;
	char afterDestination;

	

	float2 healBoxSize;


	void pathFollow(GameData& data,bool& erase);

	 void DrawSlider(ImDrawList& dl);

	virtual void DrawDebug(ImDrawList& dl);
	virtual void UpdateEnemy(GameData& data,bool& erase);

	virtual void Heal(GameData& data);


	 enemy();
	 ~enemy();

private:

};

