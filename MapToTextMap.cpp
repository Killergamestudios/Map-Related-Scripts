// SFML-Template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

int main()
{ 
	// Initialisation
	Image map; // Image to load 
	ofstream myfile; // File to write the outcome

	int red, green, blue, alpha; //Variables to temporarily save pixel colour 

	int row, col; // rows, columns
	int width, height; // Size of the image.


	//Accessing the Image.
	if (!map.loadFromFile("map.png")) //Checks if map can't open.
	{
		cout << "Error loading the image with a filename \"map.png\" \n";
		return -1;
	}

	//Accessing the text file to export our data.
	myfile.open("mapTextCode.txt");

	//Getting Image Size
	width = map.getSize().x;
	height = map.getSize().y;

	// Checking each tile of the image (Tiles are 64x64 pixels)
	for (row = 1; row < height; row = row + 64)
	{
		for (col = 1; col < width; col = col + 64)
		{
			alpha = map.getPixel(col, row).a;
			cout << "Column: " << col << ". Row: " << row;
			if (alpha == 0) //Transparent Color, gives 0;
			{
				cout << " 0 ";
				myfile << '0';
			}
			//COLOR LIST CAN BE FOUND HERE
			else 
			{
				red = map.getPixel(col, row).r;
				green = map.getPixel(col, row).g;
				blue = map.getPixel(col, row).b;


				if (red == 255 && green == 0 && blue == 0) // RED COLOR =1
				{
					myfile << '1';
				}
				else if (red == 0 && green == 255 && blue == 0) // GREEN COLOR =2
				{
					myfile << '2';
				}
				else if (red == 0 && green == 0 && blue == 255) // BLUE COLOR =3
				{
					myfile << '3';
				}
				else if (red == 255 && green == 255 && blue == 0) //YELLOW COLOR = 4
				{
					myfile << '4';
				}
				else if (red == 255 && green == 0 && blue == 255) // PURPLE COLOR = 5
				{
					myfile << '5';
				}
				else if (red == 0 && green == 255 && blue == 255) //TEAL COLOR = 6
				{
					myfile << '6';
				}
				else if (red == 0 && green == 0 && blue == 0) // BLACK COLOR = 7
				{
					myfile << '7';
				}
				else if (red == 255 && green == 255 && blue == 255) // WHITE COLOR = 8
				{
					myfile << '8';
				}
				else if (red == 128 && green == 128 && green == 128) // GRAY COLOR = 9
				{
					myfile << '9';
				}

			}
		}
		cout << '\n';
		myfile << '\n';
	}

	myfile.close();
    return 0;
}

