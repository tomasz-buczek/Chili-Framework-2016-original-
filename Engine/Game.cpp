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
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
			dy-=2;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			dy+=2;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
			dx+=2;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
			dx-=2;
	}
	if (wnd.kbd.KeyIsPressed(VK_SHIFT)) {
		dx = 0;
		dy = 0;
	}
	
	
	

	x += dx;
	y += dy;

	if (x < 1 || x>789) {
		dx *= -1;
		x += dx;
	}
	if (y < 1 || y>589)
	{
		dy *= -1;
		y += dy;
	}


	dx *= 0.9999;
	dy *= 0.9999;


}

void Game::ComposeFrame()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			gfx.PutPixel(x + i, y + j, 2 * j + 3 , j - 8*i+y , i + 8*j+x);
		}
	}
}