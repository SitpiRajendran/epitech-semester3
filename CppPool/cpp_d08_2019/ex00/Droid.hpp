/*
** EPITECH PROJECT, 2020
** CppPool - D08
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>

class Droid {
	private:
        const size_t _attack;
        const size_t _toughness;
        size_t _energy;
        std::string _id;
        std::string *_status;
	public:
		Droid(std::string serial);
        Droid(Droid const &to_copy);
        Droid& operator=(const Droid&to_copy);
        Droid(void);
		~Droid();

        void setId(std::string value);
        void setEnergy(size_t value);
        void setStatus(std::string *value);

        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;

        bool operator==(const Droid &) const;
        bool operator!=(const Droid &) const;
        Droid &operator<<(size_t &add);
};

std::ostream &operator<<(std::ostream &out, const Droid &droid);
#endif /* !DROID_HPP_ */