#pragma once
#include<iostream>
#include "entity.hpp"
#include "imgui_utils.hpp"

struct GameData;


#define IsIncenter 2.0


class enemy : public entity
{
public:

	int maxHealt;
	int currentHealth;


	std::string name;
	Texture texture;
	float velocity;
	float offsetCheckPoint;

	char baseChekcpoint = 'a';
	char destination = 'b';



	float2 healBoxSize;




	virtual void DrawSlider(ImDrawList& dl);

	virtual void DrawDebug(ImDrawList& dl);
	virtual void UpdateEnemy(GameData& data,bool& erase);

	virtual void Heal(GameData& data);


	 enemy();
	 ~enemy();

private:

};

