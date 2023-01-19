#include "tower_game.hpp"
#include "calc.hpp"
#include "Healer.hpp"
#include "heavy.hpp"
#include "weakling.hpp"




using namespace std;



void TowerGame::GameInit()
{
	srand(unsigned int(time(NULL)));

}


void TowerGame::UpdateAndDraw()
{


	data.dl = ImGui::GetBackgroundDrawList();
	ImGuiIO& io = ImGui::GetIO();
	data.deltatime = io.DeltaTime * data.acceleRateTime;
	data.currentScene = Game;

	if (data.currentScene == Menu)
	{
		data.dl->AddImage(data.asset.textureBackGround.id, { 0, 0 }, io.DisplaySize);
		data.time += io.DeltaTime;
		renderer.DrawMenu(data);
	}
	else if (data.currentScene == Game)
	{
		LoadALLPath(data);
		
		data.map.CreateMap(data);
		enemyManager.ManageEnemy(data);
		ManageAllTurret(data);	

		
		renderer.RendererGame(data);
		


		Debug(data);
	}
	else if (data.currentScene == Option)
	{

	}
	else if (data.currentScene == GameOver)
	{
		renderer.DrawEnd(data);
	}
}


TowerGame::TowerGame()
{
	this->data.dl = nullptr;

}
TowerGame::~TowerGame()
{

}


