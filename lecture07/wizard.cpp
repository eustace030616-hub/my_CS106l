/* File: wizard.cpp
 * Author: Preston Seay
 * 
 * This file contains practice for implementing a wizard
 * and spellbook class, as well as provides a main function
 * that can run some methods of the classes for you.
 * 
 * As an exercise, implement the wizard and spellbook
 * classes and run the program.
 */
#include <iostream>
#include <string>
#include <map>
#include "wizard.h"

// ==========================
// =     CLASS 1: Wizard    =
// ==========================

// This constructor creates a new wizard, storing it's name
// and starting energy.
Wizard::Wizard(const std::string& name, int energy) {
    this->name = name;
    this->energy = energy;
}

// This function will try to use `amount` of energy.
// If the wizard has enough energy to decrease by
// amount and still be non-zero, then it will subtract
// from energy and return true. Otherwise, the energy
// should remain unchanged and it will return false.
bool Wizard::useEnergy(int amount) {
    auto cur_energy = Wizard::getEnergy();
    auto diff = cur_energy - amount;
    if (diff > 0) {
        std::cout << "sufficient energy1" << std::endl;
        energy = diff;
        return true;
    } else {
        std::cout << "insufficient energy1" << std::endl;
        return false;
    }
}

// This function should simply return the amount of energy
// the wizard has left.
int Wizard::getEnergy() const {
    return energy;
}

// This should simply return the name of the wizard.
std::string Wizard::getName() const {
    return name;
}

// ==========================
// =   CLASS 2: SpellBook   =
// ==========================

// Add this spell to the spellbook.
void SpellBook::addSpell(const std::string& name, int cost) {
    spells.insert({name, cost});
}

// Try to have the wizard cast all of the spells they can.
void SpellBook::castAll(Wizard& w) {
    auto it = spells.begin();
    
    if (spells.begin() == spells.end()) {
        std::cout << "no spells to cast" << std::endl;
        return;
    }
    
    for (it; it != spells.end(); ++it) {
        auto [spellname, cost] = *it;
        if (w.useEnergy(cost)) {
        std::cout << w.getName() << " casts: " << spellname << " successfully" << "\n";
        } else {
            std::cout << w.getName() << " casts: " << spellname << " failed" << "\n";
        }
    }
    std::cout << "all spells avaliable casted" << std::endl;
    return;
}

// ==========================
// =        MAIN TEST       =
// ==========================
int main() {
    Wizard w("Merlin", 50);
    SpellBook book;

    book.addSpell("Fireball", 20);
    book.addSpell("Ice", 35);
    book.addSpell("Storm", 15);

    book.castAll(w);

    std::cout << w.getName()
              << " has " << w.getEnergy()
              << " energy left\n";
}