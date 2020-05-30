#include "Character.hpp"
#include "AWeapon.hpp"
#include "AEnemy.hpp"
#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int  main(){
    const  auto  preda = new  Character("Predator");
    const  auto  prey = new  RadScorpion ();
    std::cout << *preda;
    AWeapon *pr(new  PlasmaRifle ());
    AWeapon *pf(new  PowerFist ());
    preda ->equip(pr);
    std::cout << preda->getName() << " / " << prey->getType() << " / " <<  prey->getHP() << " / " << pr->getAPCost() << " / " <<  pr->getName() << std::endl;
    std::cout  << *preda;
    preda ->equip(pf);
    preda ->attack(prey);
    std::cout  << *preda;
    preda ->equip(pr);
    std::cout  << *preda;
    preda ->attack(prey);
    std::cout  << *preda;
    preda ->attack(prey);
    std::cout  << *preda;

    delete pf;
    delete preda;
    delete pr;
    delete prey;
    return  0;
}