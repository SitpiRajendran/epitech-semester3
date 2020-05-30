/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** nibbler
*/


#include <fstream>
#include <iostream>
#include "nibbler.hpp"

extern "C" arcade::ICoreGame *entryPoint()
{
	return new arcade::Snake();
}

extern "C" void destroyGame(arcade::ICoreGame *game)
{
	delete dynamic_cast<arcade::Snake *>(game);
}

void arcade::Snake::SendInput(Input &input)
{
}

void arcade::Snake::restartGame()
{
	
}

CoreGame_t *arcade::Snake::getData()
{
	CoreGame_t *data;
	data->end = _gameOver;
	data->restart = false;
	data->pause = false;
	data->score = _score;
	return data;
}

arcade::Snake::Snake()
{

}

arcade::Snake::~Snake() = default;