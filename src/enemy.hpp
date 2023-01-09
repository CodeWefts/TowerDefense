#pragma once
#include<iostream>
#include"calc.hpp"
#include "entity.hpp"
#include "imgui_utils.hpp"





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

	

	 enemy();
	 ~enemy();

private:

};
