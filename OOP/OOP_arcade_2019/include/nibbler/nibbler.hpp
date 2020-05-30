/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** nibbler
*/


#ifndef NIBLER_HPP_
#define NIBLER_HPP_

#include "../ICoreGame.hpp"
#include "../Core.hpp"

namespace  arcade {

	Color fruit = RED;
	Color wood = BLACK;
	Color green = GREEN;
	Color blue = BLUE;

	int nbPixel = 868;
	int side = 31;

	class Snake : public arcade::ICoreGame {
	public:
		Snake();
		virtual ~Snake();

		void SendInput(Input &input) override;
		void restartGame() override;
		CoreGame_t *getData() override;
	private:
		std::vector<arcade::Element> _map;
		std::vector<std::vector<arcade::Element> >_players;
		arcade::Element _apple;
		std::vector<Input> _currentInput;
		std::vector<Input> _up;
		std::vector<Input> _down;
		std::vector<Input> _left;
		std::vector<Input> _right;
		std::vector<Input> _direction;
		unsigned int _maxScore;
		unsigned int _level;
		unsigned int _score;
		bool _gameOver;
		void move();
	};
}

extern "C" void destroyGame(arcade::ICoreGame *game);
extern "C" arcade::ICoreGame *createGame();

#endif //CPP_ARCADE_SNAKE_HPP
