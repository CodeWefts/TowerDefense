#pragma once
#include<iostream>
#include "entity.hpp"
#include "imgui_utils.hpp"

struct GameData;


#define IsIncenter 4.0




class enemy : public entity
{
public:

	bool erase = false;

	int maxHealt;
	int currentHealth;
	int damageToPlayer;

	std::string name;
	Texture texture;
	float velocity;


	int destinationIndex;
	int roadChoice;

	float2 healBoxSize;

	float2 ReturnCheckPoint(GameData& data, int& checkPoint);


	void DrawSlider(ImDrawList& dl);
	virtual void DrawDebug(ImDrawList& dl);
	virtual void UpdateEnemy(GameData& data, bool& erase);

	virtual void Heal(GameData& data);


	enemy();
	~enemy();

protected:
	void pathFollow(GameData& data, bool& erase);



private:

};

