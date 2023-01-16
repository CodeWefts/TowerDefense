#include "tower_game.hpp"
#include "calc.hpp"
#include "Healer.hpp"
#include "heavy.hpp"
#include "weakling.hpp"


using namespace std;


Asset::Asset()
{
	//Grass
	textureGrass = ImGuiUtils::LoadTexture("assets/map/grass.png");

	//Path
	textureDirt = ImGuiUtils::LoadTexture("assets/map/dirt.png");
	texturePathBottom = ImGuiUtils::LoadTexture("assets/map/pathBottom.png");
	texturePathBottomANDLeft = ImGuiUtils::LoadTexture("assets/map/pathBottomANDLeft.png");
	texturePathBottomANDRight = ImGuiUtils::LoadTexture("assets/map/pathBottomANDRight.png");
	texturePathBottomLeft = ImGuiUtils::LoadTexture("assets/map/pathBottomLeft.png");
	texturePathBottomRight = ImGuiUtils::LoadTexture("assets/map/pathBottomRight.png");
	texturePathLeft = ImGuiUtils::LoadTexture("assets/map/pathLeft.png");
	texturePathRight = ImGuiUtils::LoadTexture("assets/map/pathRight.png");
	texturePathTop = ImGuiUtils::LoadTexture("assets/map/pathTop.png");
	texturePathTopANDLeft = ImGuiUtils::LoadTexture("assets/map/pathTopANDLeft.png");
	texturePathTopANDRight = ImGuiUtils::LoadTexture("assets/map/pathTopANDRight.png");
	texturePathTopLeft = ImGuiUtils::LoadTexture("assets/map/pathTopLeft.png");
	texturePathTopRight = ImGuiUtils::LoadTexture("assets/map/pathTopRight.png");

	//ENNEMY 1 : GRINGALET
	textureGringalet = ImGuiUtils::LoadTexture("assets/ennemies/gringalet.png");

	//ENNEMY 2 : SOIGNEUR
	textureSoigneur = ImGuiUtils::LoadTexture("assets/ennemies/soigneur.png");

	//ENNEMY 3 : COSTAUD
	textureCostaud1 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud1.png");
	textureCostaud2 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud2.png");
	textureCostaud3 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud3.png");
	textureCostaud4 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud4.png");
	textureCostaud5 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud5.png");
	textureCostaud6 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud6.png");
	textureCostaud7 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud7.png");
	textureCostaud8 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud8.png");
	textureCostaud9 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud9.png");
	textureCostaud10 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud10.png");
	textureCostaud11 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud11.png");
	textureCostaud12 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud12.png");

	//TOWER 1 : TOWER
	textureTowerClassique = ImGuiUtils::LoadTexture("assets/tower/classique.png");

	//INVENTORY HUD
	textureTowerSideLeft = ImGuiUtils::LoadTexture("assets/hud/SideLeft.png");
	textureTowerSideRight = ImGuiUtils::LoadTexture("assets/hud/SideRight.png");
	textureTowerCase = ImGuiUtils::LoadTexture("assets/hud/TowerCase.png");
	PlayerHeart = ImGuiUtils::LoadTexture("assets/hud/pixel-heart-png.png");


	//MENU : START GAME
	textureAnimation = ImGuiUtils::LoadTexture("assets/menu/Animation.png");




}


GameData::GameData()
{
	this->acceleRateTime = 0;
	this->acceleRateTimeBuffer = 0;

	this->addEnemy = false;
	this->playerStopTime = false;

	this->acceleRateTime = 1;
	this->enableDebug = false;



	this->deltatime = 0.f;
	this->dl = nullptr;

	this->currentScene = Menu;
	this->currentWave = 0;
	this->currentLevel = 0;
	this->timerLevel = TimerLevel;
	this->timerWave = TimerWave;

	for (int i = 0; i < nbrOfLevel; i++)
	{
		level[i].nbrOfWave = 3 + (i * 2);
		level[i].nbrOfWeakling = 10 + (i * 5);
		level[i].nbrOfHealer = 2 + (i * 2);
		level[i].nbrOfHeavy = 3 + (i * 4);
		level[i].timerBetweenSpawn = 0;
	}

}

GameData::~GameData()
{
	for ( auto it = enemyVector.begin();  it != enemyVector.end();  it++)
	{
		delete *it;
	}

}


//this->font = io.Fonts->AddFontFromFileTTF("C:\Data\Isart\Projet\C++\2022_tower_gp2027_tower-debon\src\3X5_____.TTF", 16.f, NULL, io.Fonts->GetGlyphRangesDefault());
//this->font = nullptr;



void TowerGame::GameInit()
{



}

void TowerGame::Debug()
{


	ImGui::Text("Time %f", gameData.deltatime);
	ImGui::Text("vectorsise %d", gameData.enemyVector.size());
	ImGui::Text(" Press V gameData.listOfRoad[0] = %d", gameData.listOfRoad[0].size());
	ImGui::Text(" Press B gameData.listOfRoad[1] = %d", gameData.listOfRoad[1].size());
	ImGui::Text(" Press N gameData.listOfRoad[2] = %d ", gameData.listOfRoad[2].size());
	ImGui::Text("TimerLevel = %f ", gameData.timerLevel);
	ImGui::Text("Wavetimer = %f ", gameData.timerWave);
	ImGui::Text("nbr of weakling = %d ", gameData.level->nbrOfWeakling);
	ImGui::Text("nbr of Heavy %d ", gameData.level->nbrOfHeavy);
	ImGui::Text("nbr of Healer %d ", gameData.level->nbrOfHealer);





	if (ImGui::IsKeyPressed(ImGuiKey_S, false))
	{
		/*
		for (int i = 0; i < gameData.map.map.size(); i++)
		{
			gameData.map.map.pop_back();
		}
		*/
		for (auto it = gameData.enemyVector.begin(); it != gameData.enemyVector.end(); it++)
		{
			enemy* current = *it;
			current->currentHealth -= 10;
		}

	}
	if (ImGui::IsKeyPressed(ImGuiKey_E, false))
	{
		//PlaySound(gameData.asset.SoundTest);
	
		ifstream file;
		file.open("src/checkPointData/lvl1.txt", std::ios::in);  // write
		
		if (file.is_open())
		{
			
			for (int i = 0; i < 3;i++)
			{
				int size = 0;
				file >> size;

				
			
			
				for (int  k = 0; k < size; k++)
				{
					float2 ptr = { 0,0 };
					file >> ptr.x;

					file >> ptr.y;
					gameData.listOfRoad[i].push_back(ptr);
				}
				

				
				
				
					
			}
			file.close();
		}
	}

	if (ImGui::IsKeyPressed(ImGuiKey_Z, false))
	{
		//Load Data 
		ofstream file;
		file.open("src/checkPointData/lvl1.txt", std::ios::out);  // write

		if (file.is_open())
		{
			for (int i = 0; i < 3; i++)
			{
				file << gameData.listOfRoad[i].size() << std::endl;
				for (auto it = gameData.listOfRoad[i].begin(); it != gameData.listOfRoad[i].end(); it++)
				{
					file << it->x << std::endl;
					file << it->y << std::endl;
				}
				//file << EndOfVector << std::endl;
			}
			file.close();
		}
	
		
	}


	// work
	if (ImGui::IsKeyPressed(ImGuiKey_A,false))
	{
		enemy* enemy1 = new Healer();

		enemy1->pos = ReturnCenterTile(0, 6, gameData.map);
		enemy1->roadChoice = Path0;

		gameData.enemyVector.push_back(enemy1);

	}

	if (ImGui::IsKeyPressed(ImGuiKey_Q, false))
	{
		enemy* enemy1 = new Weakling();

		enemy1->pos = ReturnCenterTile(0, 6, gameData.map);
		enemy1->roadChoice = Path0;

		gameData.enemyVector.push_back(enemy1);

	}


	if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft, false))
	{
		if (ImGui::IsKeyDown(ImGuiKey_V))
		{
			gameData.listOfRoad[0].push_back(float2(ImGui::GetMousePos().x, ImGui::GetMousePos().y));
		}
		if (ImGui::IsKeyDown(ImGuiKey_B))
		{
			gameData.listOfRoad[1].push_back(float2(ImGui::GetMousePos().x, ImGui::GetMousePos().y));
		}
		if (ImGui::IsKeyDown(ImGuiKey_N))
		{
			gameData.listOfRoad[2].push_back(float2(ImGui::GetMousePos().x, ImGui::GetMousePos().y));
		}

	}

	if (ImGui::Begin("CheckPoint",nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::Text("ROAD 0");
		for (auto it = gameData.listOfRoad[0].begin(); it != gameData.listOfRoad[0].end(); it++)
		{
			ImGui::Text(" Road 1 x = %f , y = %f ", it->x, it->y);
			

		}
		ImGui::Text("  \n ");
		ImGui::Text("ROAD 1");
		for (auto it = gameData.listOfRoad[1].begin(); it != gameData.listOfRoad[1].end(); it++)
		{
			ImGui::Text(" Road 2 x = %f , y =  %f ", it->x, it->y);
		}
		ImGui::Text("  \n ");
		ImGui::Text("ROAD 2");
		for (auto it = gameData.listOfRoad[2].begin(); it != gameData.listOfRoad[2].end(); it++)
		{
			ImGui::Text("Road 3 x = %f , y = %f", it->x, it->y);
		}
	};
	ImGui::End();
	

}

void TowerGame::UpdateAndDraw()
{

	srand(time(NULL));
	ImGuiIO& io = ImGui::GetIO();
	gameData.deltatime = io.DeltaTime * gameData.acceleRateTime;
	this->gameData.dl = ImGui::GetBackgroundDrawList();

	if (gameData.currentScene == Menu)
	{
		renderer.DrawMenu(gameData);
	}
	else if (gameData.currentScene == Game)
	{

		gameData.map.CreateMap();
		enemyManager.ManageEnemy(gameData);

		renderer.RendererGame(gameData);

		gameData.player.PlayerTile(gameData);
		gameData.player.PlayerInput(gameData);

		renderer.HudInventory(gameData);
		//gameData.player.DragAndDrop(gameData);

		Debug();
	}
	else if (gameData.currentScene == Option)
	{

	}












}


TowerGame::TowerGame()
{
	this->gameData.dl = nullptr;

}
TowerGame::~TowerGame()
{

}


