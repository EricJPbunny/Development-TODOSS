#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)

}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map


	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if(ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data
	}

	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
	

	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything
	}

	map_loaded = ret;

	return ret;
}
bool j1Map::LoadMap(const pugi::xml_node& node) 
{
	Map newMap;
	if (node.attribute("orientation").as_string() == "orthogonal") {
		newMap.perspective = ORTHOGONAL;
	}
	else if (node.attribute("orientation").as_string() == "isometric") {
		newMap.perspective = ISOMETRIC;
	}
	else {
		newMap.perspective = NO_ORIENTATION;
	}
	if (node.attribute("orientation").as_string() == "right-up") {
		newMap.tilepainting = RIGHT_UP;
	}
	else if (node.attribute("orientation").as_string() == "right-down") {
		newMap.tilepainting = RIGHT_DOWN;
	}
	else if (node.attribute("orientation").as_string() == "left-up") {
		newMap.tilepainting = LEFT_UP;
	}
	else if (node.attribute("orientation").as_string() == "left-down") {
		newMap.tilepainting = LEFT_DOWN;
	}
	else {
		newMap.tilepainting = NO_RENDERORDER;
	}
	newMap.tilepainting;
	newMap.width = node.attribute("width").as_int();
	newMap.height = node.attribute("height").as_int();
	newMap.tile_height = node.attribute("tilewidth").as_int();
	newMap.tile_width = node.attribute("tileheight").as_int();
	mapList.push_back(newMap);
	return true;

};
bool j1Map::LoadTilesets(pugi::xml_node &node) {
	for (pugi::xml_node tileset = node.child("tileset"); tileset; tileset = tileset.next_sibling("tileset")) {
		Tileset newTileset;
		newTileset.tilesetImage = App->tex->Load(tileset.child("image").attribute("source").as_string());
		newTileset.firstGid = tileset.attribute("firstgid").as_int();
		newTileset.name = tileset.attribute("name").as_string();
		newTileset.tileWidth = tileset.attribute("tilewidth").as_int();
		newTileset.tileHeight = tileset.attribute("tileheight").as_int();
		newTileset.spacing = tileset.attribute("spacing").as_int();
		newTileset.margin = tileset.attribute("margin").as_int();
		tilesetList.push_back(newTileset);

	}
	return true;
}
