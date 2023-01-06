#pragma once
#include<iostream>
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


	char baseChekcpoint = 'a';
	char destination = 'b';



	 enemy();
	 ~enemy();

private:

};
