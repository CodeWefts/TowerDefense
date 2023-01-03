#include "imgui_utils.hpp"
#include"Map.hpp"

using namespace std;

struct GameData
{
	Map map;

	std::vector<Tile> Tiles;
	GameData();

};

class TowerRenderer
{
public:





	ImDrawList* dl;
	ImGuiIO* io;

	

	void RendererGame(const GameData& data);

	TowerRenderer();
	~TowerRenderer();

private:

};


class TowerGame
{
public:

	GameData gameData;

	void GameInit();

	void UpdateAndDraw();


	TowerGame();
	~TowerGame();

private:

	TowerRenderer renderer;
	

};

