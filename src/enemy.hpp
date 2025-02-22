#pragma once
#include<iostream>
#include "entity.hpp"
#include "imgui_utils.hpp"

struct GameData;


#define IsIncenter 4.0

enum EnemyType : int
{
	WEAKLING = 1,
	HEALER,
	HEAVY,
	NULLENEMY = 255

};


class Enemy : public Entity
{
public:

	bool erase = false;

	int maxHealt;
	int currentHealth;
	int damageToPlayer;
	int coinsToPlayer;

	Texture texture;
	float velocity;


	int destinationIndex;
	int roadChoice;

	float animationMinX;
	float animationMinY;
	float animationMaxX;
	float animationMaxY;

	float vecMaxX;
	float vecMaxY;

	float timeMove;
	EnemyType type;

	float2 ReturnCheckPoint(GameData& data, int& checkPoint);


	void DrawSlider(ImDrawList& dl);
	virtual void DrawDebug(ImDrawList& dl);
	virtual void UpdateEnemy(GameData& data, bool& erase);

	virtual void Heal(GameData& data);


	Enemy();
	~Enemy();

protected:
	void pathFollow(GameData& data, bool& erase);



private:

};

