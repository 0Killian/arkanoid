/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> cDist(0, sizeof(colors) / sizeof(Color) - 1);

	for (int y = 0; y < nBricksX; y++)
	{
		bricks.push_back(std::vector<Brick>());
		for (int x = 0; x < nBricksY; x++)
			bricks[y].push_back(Brick(Vec2i(x * Brick::width, y * Brick::height), colors[cDist(rng)]));
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.mouse.LeftIsPressed())
	{
		if (bricks.size() != 0 && !old)
		{
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> yDist(0, (int)bricks.size() - 1);
			std::vector<Brick>::iterator b;

			int y;

			do
			{
				y = yDist(rng);
			} while (bricks[y].size() == 0);

			std::uniform_int_distribution<int> xDist(0, (int)bricks[y].size() - 1);

			do
			{
				const int x = xDist(rng);
				b = std::find(bricks[y].begin(), bricks[y].end(), bricks[y][x]);
			} while (b == bricks[y].end());

			bricks[y].erase(b);
			if (bricks[y].size() == 0)
				bricks.erase(bricks.begin() + y);
		}

		old = true;
	}
	else
		old = false;
}

void Game::ComposeFrame()
{
	for (const std::vector<Brick>& vec : bricks)
		for (const Brick& b : vec)
			b.Draw(gfx);
}
