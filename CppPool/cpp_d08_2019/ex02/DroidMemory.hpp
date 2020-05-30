/*
** EPITECH PROJECT, 2020
** CppPool - D08
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <iostream>

class DroidMemory {
	private:
		size_t _exp;
		size_t _finger;
	public:
		DroidMemory();
		~DroidMemory();

		void setFingerprint(size_t);
		void setExp(size_t);

		size_t getFingerprint() const;
		size_t getExp() const;

		DroidMemory &operator<<(DroidMemory const &right);
		DroidMemory &operator>>(DroidMemory &right);

		DroidMemory &operator+=(DroidMemory &right);
		DroidMemory &operator+=(size_t add);

		DroidMemory operator+(DroidMemory &right) const;
		DroidMemory operator+(size_t add) const;

		bool operator==(DroidMemory &right) const;
		bool operator!=(DroidMemory &right) const;

		bool operator>=(DroidMemory &right) const;
		bool operator<=(DroidMemory &right) const;
		bool operator<(DroidMemory &right) const;
		bool operator>(DroidMemory &right) const;
		bool operator>=(size_t right) const;
		bool operator<=(size_t right) const;
		bool operator<(size_t right) const;
		bool operator>(size_t right) const;
};

std::ostream &operator<<(std::ostream &out, const DroidMemory &droid);

#endif /* !DROIDMEMORY_HPP_ */
