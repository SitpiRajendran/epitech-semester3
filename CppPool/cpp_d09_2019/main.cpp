#include "Character.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Priest.hpp"
#include <iostream>

int main ()
{
    Character c("poney", 42);
    Character const_("get_pranked", 99);
    c.TakeDamage (50);
    c.TakeDamage (200);
    c.TakeDamage (200);
    std::cout << const_.getLvl() << std::endl;
    std::cout << const_.getName() << const_.getPower() << std::endl;
    std::cout << const_.RangeAttack() << std::endl;
    std::cout << const_.CloseAttack() << std::endl;
    std::cout << c.getPv() << std::endl;
    c.Heal();
    c.Heal();
    c.RestorePower();
    std::cout << c.getPv() << " " << c.getPower() << std::endl  << std::endl;

    Warrior pol("NOP", 99, "hammer");
    std::cout << pol.getPv() << " " << pol.getPower() << std::endl;
    std::cout << pol.getLvl() << std::endl;
    std::cout << pol.getName() << std::endl;
    std::cout << pol.RangeAttack() << std::endl;
    std::cout << pol.CloseAttack() << std::endl;
    pol.TakeDamage(100);
    pol.Heal();
    std::cout << pol.getPv() << " " << pol.getPower() << std::endl  << std::endl;

    Mage nrv("dragi", 99);
    std::cout << nrv.getPv() << " " << nrv.getPower() << std::endl;
    std::cout << nrv.getLvl() << std::endl;
    std::cout << nrv.getName() << std::endl;
    std::cout << nrv.RangeAttack() << std::endl;
    std::cout << nrv.CloseAttack() << std::endl;
    nrv.TakeDamage(100);
    nrv.Heal();
    std::cout << nrv.getPv() << " " << nrv.getPower() << std::endl << std::endl;

    Priest hihi("flixis", 99);
    std::cout << hihi.getPv() << " " << hihi.getPower() << std::endl;
    std::cout << hihi.getLvl() << std::endl;
    std::cout << hihi.getName() << std::endl;
    std::cout << hihi.RangeAttack() << std::endl;
    std::cout << hihi.CloseAttack() << std::endl;
    hihi.TakeDamage(100);
    hihi.Heal();
    std::cout << hihi.getPv() << " " << hihi.getPower() << std::endl << std::endl;
}