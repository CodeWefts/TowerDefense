#include <string>
#include "data.hpp"
#include "healer.hpp"
#include "weakling.hpp"


using namespace std;








void ChangeLevel(GameData& data)
{
	for (auto it = data.towerVector.begin(); it != data.towerVector.end(); it++)
	{
		Tower* currentTower = *it;
		currentTower->target = nullptr;
		delete currentTower;

	}
	data.towerVector.clear();
	for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
	{
		delete* it;
	}
	data.enemyVector.clear();

}





void SaveAllPath(GameData& data)
{
	//Load Data 
	ofstream file;
	std::string pathFileString = "src/checkPointData/lvl0.txt";
	//pathFileString += std::to_string(data.currentLevel);
	//pathFileString += ".txt";

	pathFileString.replace(22, 22, std::to_string(data.currentLevel) + ".txt");

	file.open(pathFileString, std::ios::out);  // write



	if (file.is_open())
	{
		for (int i = 0; i < NbrOfRoad; i++)
		{
			file << data.listOfRoad[i].size() << std::endl;
			for (auto it = data.listOfRoad[i].begin(); it != data.listOfRoad[i].end(); it++)
			{
				file << it->x << std::endl;
				file << it->y << std::endl;
			}

		}
		file.close();
	}


}



void LoadALLPath(GameData& data)
{

	if (data.changeLevel)
	{

		ifstream pathFile;
		std::string pathFileString = "src/checkPointData/lvl0.txt";
		//pathFileString += std::to_string(data.currentLevel);
		//pathFileString += ".txt";


		pathFileString.replace(22, 22, std::to_string(data.currentLevel) + ".txt");
		cout << pathFileString << std::endl;


		pathFile.open(pathFileString, std::ios::in);  // write

		if (pathFile.is_open())
		{


			for (int i = 0; i < NbrOfRoad; i++)
			{
				int size = 0;
				pathFile >> size;
				data.listOfRoad[i].clear();



				for (int k = 0; k < size; k++)
				{
					float2 ptr = { 0,0 };
					pathFile >> ptr.x;

					pathFile >> ptr.y;

					data.listOfRoad[i].push_back(ptr);
				}

			}
			pathFile.close();
		}
		data.changeLevel = false;
	}

}





void Debug(GameData& data)
{


	ImGui::Text("Time %f", data.deltatime);
	ImGui::Text("vectorsise %d", data.enemyVector.size());
	ImGui::Text(" Press V data.listOfRoad[0] = %d", data.listOfRoad[0].size());
	ImGui::Text(" Press B data.listOfRoad[1] = %d", data.listOfRoad[1].size());
	ImGui::Text(" Press N data.listOfRoad[2] = %d ", data.listOfRoad[2].size());
	ImGui::Text("TimerLevel = %f ", data.timerLevel);

	ImGui::Text("WaveTimer = %f ", data.levels.at(data.currentLevel).timerBetweenWave);
	ImGui::Text("timerbetweenSpawn = %f ", data.levels.at(data.currentLevel).waves.at(data.currentWave).timerbetweenSpawn);

	ImGui::Text("CurrentLevel = %d ", data.currentLevel);
	ImGui::Text("nbrOfLevel = %d ", data.levels.size());
	ImGui::Text("MaxWave = %d ", data.levels.at(data.currentLevel).maxWave);
	ImGui::Text("CurrentWave %d", data.currentWave);


	ImGui::Text("EnemyRemaining = %d ", data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy);


	if (ImGui::IsKeyPressed(ImGuiKey_S, false))
	{
		/*
		for (int i = 0; i < data.map.map.size(); i++)
		{
			data.map.map.pop_back();
		}
		*/
		for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
		{
			Enemy* current = *it;
			current->currentHealth -= 10;
		}

	}
	if (ImGui::IsKeyPressed(ImGuiKey_E, false))
	{
		//PlaySound(data.asset.SoundTest);

		ifstream file;
		file.open("src/checkPointData/lvl1.txt", std::ios::in);  // write

		if (file.is_open())
		{

			for (int i = 0; i < 3; i++)
			{
				int size = 0;
				file >> size;




				for (int k = 0; k < size; k++)
				{
					float2 ptr = { 0,0 };
					file >> ptr.x;

					file >> ptr.y;
					data.listOfRoad[i].push_back(ptr);
				}

			}
			file.close();
		}
	}

	if (ImGui::IsKeyPressed(ImGuiKey_Z, false))
	{
		SaveAllPath(data);
	}


	// work
	if (ImGui::IsKeyPressed(ImGuiKey_A, false))
	{
		Enemy* enemy1 = new Healer();

		enemy1->pos = ReturnCenterTile(0, 6, data.map);
		enemy1->roadChoice = Path0;

		data.enemyVector.push_back(enemy1);

	}

	if (ImGui::IsKeyPressed(ImGuiKey_I, false))
	{
		Enemy* enemy1 = new Weakling();

		enemy1->pos = ReturnCenterTile(0, 6, data.map);
		enemy1->roadChoice = Path0;

		data.enemyVector.push_back(enemy1);

	}

	if (ImGui::IsKeyPressed(ImGuiKey_Q, false))
	{
		data.timerLevel = 0;
		data.currentWave++;
	}


	if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft, false))
	{
		if (ImGui::IsKeyDown(ImGuiKey_V))
		{
			data.listOfRoad[0].push_back(float2(ImGui::GetMousePos().x, ImGui::GetMousePos().y));
		}
		if (ImGui::IsKeyDown(ImGuiKey_B))
		{
			data.listOfRoad[1].push_back(float2(ImGui::GetMousePos().x, ImGui::GetMousePos().y));
		}
		if (ImGui::IsKeyDown(ImGuiKey_N))
		{
			data.listOfRoad[2].push_back(float2(ImGui::GetMousePos().x, ImGui::GetMousePos().y));
		}
		if (ImGui::IsKeyDown(ImGuiKey_C))
		{
			data.listOfRoad[3].push_back(float2(ImGui::GetMousePos().x, ImGui::GetMousePos().y));
		}


	}

	if (ImGui::Begin("CheckPoint", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::Text("ROAD 0");
		for (auto it = data.listOfRoad[0].begin(); it != data.listOfRoad[0].end(); it++)
		{
			ImGui::Text(" Road 1 x = %f , y = %f ", it->x, it->y);


		}
		ImGui::Text("  \n ");
		ImGui::Text("ROAD 1");
		for (auto it = data.listOfRoad[1].begin(); it != data.listOfRoad[1].end(); it++)
		{
			ImGui::Text(" Road 2 x = %f , y =  %f ", it->x, it->y);
		}
		ImGui::Text("  \n ");
		ImGui::Text("ROAD 2");
		for (auto it = data.listOfRoad[2].begin(); it != data.listOfRoad[2].end(); it++)
		{
			ImGui::Text("Road 3 x = %f , y = %f", it->x, it->y);
		}
		ImGui::Text("  \n ");
		ImGui::Text("ROAD 3");
		for (auto it = data.listOfRoad[3].begin(); it != data.listOfRoad[3].end(); it++)
		{
			ImGui::Text("Road 3 x = %f , y = %f", it->x, it->y);
		}
	};
	ImGui::End();


}

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
	textureCanineWhite = ImGuiUtils::LoadTexture("assets/enemy/canineWhite.png");

	//ENNEMY 2 : SOIGNEUR
	textureSoigneur = ImGuiUtils::LoadTexture("assets/enemy/soigneur.png");

	//ENNEMY 3 : COSTAUD
	textureNightBorne = ImGuiUtils::LoadTexture("assets/enemy/NightBorne.png");

	//TOWER 1 : TOWER
	textureTowerClassique = ImGuiUtils::LoadTexture("assets/tower/classique.png");
	textureTowerClassicalCanon = ImGuiUtils::LoadTexture("assets/tower/classique_canon.png");
	textureTowerClassicalBase = ImGuiUtils::LoadTexture("assets/tower/classique_base.png");

	//TOWER 2 : SLOWING
	texureSlowing = ImGuiUtils::LoadTexture("assets/tower/Obelisk.png");

	// TOWER 3 : EXPLOSIVE
	textureTowerExplosive = ImGuiUtils::LoadTexture("assets/tower/explosive.png");

	//INVENTORY HUD
	textureTowerSideLeft = ImGuiUtils::LoadTexture("assets/hud/SideLeft.png");
	textureTowerSideRight = ImGuiUtils::LoadTexture("assets/hud/SideRight.png");
	textureTowerCase = ImGuiUtils::LoadTexture("assets/hud/TowerCase.png");
	PlayerHeart = ImGuiUtils::LoadTexture("assets/hud/pixel-heart-png.png");
	textureCoin = ImGuiUtils::LoadTexture("assets/level/coin.png");
	textureButton = ImGuiUtils::LoadTexture("assets/menu/button.png");
	textureUpgradeButton = ImGuiUtils::LoadTexture("assets/hud/button.png");


	//MENU : START GAME
	textureAnimation = ImGuiUtils::LoadTexture("assets/menu/Animation.png");
	textureMenuHUD = ImGuiUtils::LoadTexture("assets/menu/menuHUD.png");
	textureBackGround = ImGuiUtils::LoadTexture("assets/menu/background.png");
	texturePlay = ImGuiUtils::LoadTexture("assets/menu/menuPlay.png");
	textureSettings = ImGuiUtils::LoadTexture("assets/menu/settings.png");
	textureLevels = ImGuiUtils::LoadTexture("assets/menu/levels.png");

	//END

	textureEndBackGround = ImGuiUtils::LoadTexture("assets/end/background.png");
	textureEndLose = ImGuiUtils::LoadTexture("assets/end/lose.png");
	textureEndWin = ImGuiUtils::LoadTexture("assets/end/win.png");
	textureEndOkButton = ImGuiUtils::LoadTexture("assets/end/okButton.png");

	//END

	textureEndBackGround = ImGuiUtils::LoadTexture("assets/end/background.png");
	textureEndLose = ImGuiUtils::LoadTexture("assets/end/lose.png");
	textureEndWin = ImGuiUtils::LoadTexture("assets/end/win.png");


}


GameData::GameData()
{

	this->acceleRateTime = 0;
	this->acceleRateTimeBuffer = 0;

	this->addEnemy = false;
	this->playerStopTime = false;
	this->changeLevel  = true;

	this->acceleRateTime = 1;
	this->enableDebug = false;

	this->deltatime = 0.f;
	this->dl = nullptr;

	this->currentScene = Menu;
	this->currentWave = 0;
	this->currentLevel = 0;

	// for each level
	for (int i = 0; i < nbrOfLevel; i++)
	{
		Level newlevel;
		newlevel.maxWave = 3 + (2 * i);
		newlevel.nbrOfRoad = NbrOfRoad;
		newlevel.waves.resize(newlevel.maxWave);

		// for each wawe of each level we adding a different nbr of enemys
		for (int j = 0; j < newlevel.maxWave; j++)
		{
			newlevel.waves[j].maxEnemy = 3 + (5 * j);
			newlevel.waves[j].nbrOfEnemy = newlevel.waves[j].maxEnemy;
			newlevel.waves[j].timerbetweenSpawn = Calc::randomFloat(1.f, 3.f);

		}

		levels.push_back(newlevel);
	}

	this->timerLevel = TimerLevel;
	this->timerWave = levels.at(currentLevel).timerBetweenWave;


	font = ImGui::GetIO().Fonts->AddFontFromFileTTF("assets/hud/Font.ttf", 20);

	result = ma_engine_init(NULL,&engine);

		

}

GameData::~GameData()
{
	
	for (auto it = towerVector.begin(); it != towerVector.end(); it++)
	{
		Tower* currentTower = *it;
		currentTower->target = nullptr;
		delete currentTower;

	}
	towerVector.clear();
	for (auto it = enemyVector.begin(); it != enemyVector.end(); it++)
	{
		delete* it;
	}
	enemyVector.clear();

	ma_engine_uninit(&engine);




}