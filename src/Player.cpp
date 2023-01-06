#include "Player.hpp"
#include"TowerGame.hpp"


void Player::PlayerTile(GameData& gamedata)
{
	ImGuiIO& io2 = ImGui::GetIO();

	int MouseX = io2.MousePos.x;
	int MouseY = io2.MousePos.y;

	int TileSize = gamedata.map.Tilesize;

	int TileMouseX = (MouseX / TileSize) % 18;
	int TileMouseY = MouseY / TileSize;


	int TileMinX = TileMouseX * 72;
	int TileMaxX = TileMouseX * 72 + 72;

	int TileMinY = TileMouseY * 72;
	int TileMaxY = TileMouseY * 72 + 72;



	ImGui::Text("Coord Mouse X : %d ", MouseX);
	ImGui::Text("Coord Mouse Y : %d ", MouseY);

	ImGui::Text("Tile Mouse X : %d ", TileMouseX);
	ImGui::Text("Tile Mouse Y : %d ", TileMouseY);

	ImGui::Text("Tile min {X ; Y} : {%d ; %d} ", TileMinX, TileMinY);

	ImGui::Text("Tile max {X ; Y} :  {%d ; %d} ", TileMaxX, TileMaxY);

	ImVec2 TileX = { (float)TileMinX,  (float)TileMinY };
	ImVec2 TileY = { (float)TileMaxX,  (float)TileMaxY };

	gamedata.dl->AddRect(TileX, TileY, IM_COL32(255, 255, 0, 255), 0);
	

}




void Player::PlayerInput(GameData& gamedata)
{

	if(ImGui::IsKeyPressed(ImGuiKey_N,false) )
	{

		gamedata.enableDebug = not gamedata.enableDebug;

	
		std::cout << gamedata.enableDebug << std::endl;
	}


}

Player::Player()
{
	this->coins = 0;
	this->health = 0;

	this->power = 0; 
	this->tower = 0;

	this->score = 0;
	this->wave = 0;

}

Player::~Player()
{
}




