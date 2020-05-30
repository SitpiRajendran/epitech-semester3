/*
** EPITECH PROJECT, 2020
** CppPool - D07a
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include <iostream>

class KreogCom {
	private:
        const int m_serial;
        int _x;
        int _y;
        KreogCom *_next;
	public:
		KreogCom(int x, int y, int serial);
		~KreogCom();

        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();

        void ping();
        void locateSquad();
};

#endif /* !KREOGCOM_HPP_ */