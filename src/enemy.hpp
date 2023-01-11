#pragma once
#include<iostream>
#include "entity.hpp"
#include "imgui_utils.hpp"

struct GameData;




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






	virtual void DrawDebug(ImDrawList& dl);
	virtual void UpdateEnemy(GameData& data);

	virtual void Heal(GameData& data);


	 enemy();
	 ~enemy();

private:

};

