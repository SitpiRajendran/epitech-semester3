/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <iostream>

class Character {
	public:
		Character(const std::string &name, int level);
		~Character();

        std::string _name;
        int _level;
        int  _power;
        enum AttackRange {
            CLOSE,
            RANGE,
        };
        AttackRange Range;

        const std::string &getName() const {return _name;};
        int getLvl() const {return _level;};
        int getPv() const {return _health;};
        int getPower() const {return _power;};
        int getHeath() const {return _health;};
        int getStrenght() const {return _strength;};
        int getStamina() const {return _stamina;};
        int getIntelligence() const {return _intelligence;};
        int getSpirit() const {return _spirit;};
        int getAgility() const {return _agility;};

        virtual int CloseAttack();
        virtual int RangeAttack();
        virtual void Heal();
        virtual void RestorePower();
        virtual void TakeDamage(int damage);
	protected:
        int _health;
        int _strength;
        int _stamina;
        int _intelligence;
        int _spirit;
        int _agility;
};

#endif /* !CHARACTER_HPP_ */
