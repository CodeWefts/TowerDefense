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


	 enemy();
	 ~enemy();

private:

};
