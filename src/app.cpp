
#include "app.hpp"



App::App()
{
	towerGame.GameInit();
}

App::~App()
{
}

void App::Update()
{
	towerGame.UpdateAndDraw();
}
