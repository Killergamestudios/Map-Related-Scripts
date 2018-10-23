void drawMapLayer(int mapIndex, int layerIndex)
{
	ifstream myfile;
	string mapAddress;
	string lineReader;
	int w; //Width of the Map
	int y; // Current Row that is being checked.
	int printX; // X coordinate to print.
	int printY; // Y coordinate to print.
	const int TILE_SIZE = 64;
	string objToCreate;

	mapAddress = "mapText_" + to_string(mapIndex) + "_L-" + to_string(layerIndex) + ".txt"; // Building the Address of the map text file to fetch.
	myfile.open(mapAddress);

	y = 0; // First Row to Check is the 0.
	while (getline(myfile, lineReader))
	{
		//NEEDS TO BREAK OUT IN CASE OF END OF FILE
		w = lineReader.length(); //Needs to do this only once- NEEDS EDITING
		for (int x = 0; x < w; x++) // x goes from colum to column starting from 0 and reaching the final column.
		{
			//lineReader[x] -> The Symbol of the Item in Column- x and Row - y.
			if (lineReader[x] != '0')
			{
				printX = x * TILE_SIZE; // Calculating the X- Coordinate of where an image should be printed
				printY = y * TILE_SIZE; // Calculating the Y- Coordinate of where an image should be printed
			}
		}
		y++; // Going to the next Row. 

	}

}
