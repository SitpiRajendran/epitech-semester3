/*
** EPITECH PROJECT, 2020
** CppPool - d6
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include "KoalaDoctor.hpp"

class SickKoalaList {
	public:
        SickKoala *patient;
        SickKoalaList *next;
		SickKoalaList(SickKoala *patient);
		~SickKoalaList();
        bool SickKoalaList::isEnd();
        void SickKoalaList::append(SickKoalaList *newkoala);
        SickKoala *SickKoalaList::getFromName(std::string name);
        SickKoala *SickKoalaList::removeFromName(std::string name);
        SickKoala *SickKoalaList::getContent();
        SickKoalaList *SickKoalaList::getNext();
        void SickKoalaList::dump(void);
	protected:
	private:
};

#endif /* !SICKKOALALIST_HPP_ */
