#include "Unit.h"

Unit::Unit(const std::string& name, State *state, BaseAttack *bAttack, UnitType type, UnitType stateType) {
    this->name = name;
    this->state = state;
    this->baseAttack = bAttack;
    this->type = type;
    this->stateType = stateType;
    this->altState = NULL;
    
    debugPrint("Unit created", this->name);
}

Unit::~Unit() {
    delete this->state;
    delete this->baseAttack;
    
    if ( this->altState ) {
        delete this->altState;
    }
    
    debugPrint("Unit destroyed", this->name);
}

bool Unit::isAlive() {
    return this->state->getHitPoints() > 0;
}

void Unit::esureIsAlive() {
    if ( !isAlive() ) {
        throw UnitIsDead();
    }
}

const std::string& Unit::getName() const {
    return this->name;
}

const State& Unit::getState() const {
    return *(this->state);
}

int Unit::getDamage() const {
    return this->state->getDamage();
}


UnitType Unit::getType() const {
    return this->type;
}

UnitType Unit::getStateType() const {
    return this->stateType;
}

void Unit::addHitPoints(int hp) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
        return;
    }
    
    this->state->addHitPoints(hp);
}

void Unit::setName(const std::string& name) {
    this->name = name;
}

void Unit::takeDamage(int dmg) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
        return;
    }
    
    this->state->takeDamage(dmg);
}

void Unit::takeMagicDamage(int dmg) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead" << std::endl;
        return;
    }
    
    this->state->takeMagicDamage(dmg);
}

void Unit::attack(Unit& enemy) {
    if ( !isAlive() ) {
        std::cout << "Unit " << this->name << " is dead and can't attack" << std::endl;
        return;
    }
    
    if ( &enemy == this ) {
        std::cout << "Self attack!" << std::endl;
        return;
    }
    
    this->baseAttack->attack(*this, enemy);
}
void Unit::counterAttack(Unit& enemy) {
    this->baseAttack->counterAttack(*this, enemy);
}

void Unit::useAbility() {}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "\033[30m" << unit.getName();
    
    if ( unit.getType() != UnitType::DEMON ) {
        out << " " << unit.getType();
    }
    
    out << " [";
    out << unit.getState() << "]";
    
    return out;
}

std::ostream& operator<<(std::ostream& out, const UnitType& type) {
    switch (type) {
        case UnitType::SOLDIER:
            out << "Soldier";
            break;
        case UnitType::ROGUE:
            out << "Rogue";
            break;
        case UnitType::BERSERKER:
            out << "Berserker";
            break;
        case UnitType::VAMPIRE:
            out << "Vampire";
            break;
        case UnitType::WEREWOLF:
            out << "Werewolf";
            break;
        case UnitType::WOLF:
            out << "Wolf";
            break;
        case UnitType::WIZARD:
            out << "Wizard";
            break;
        case UnitType::HEALER:
            out << "Healer";
            break;
        case UnitType::PRIEST:
            out << "Priest";
            break;
        case UnitType::WARLOCK:
            out << "Warlock";
            break;
        case UnitType::DEMON:
            out << "Demon";
            break;
        default:
            out << "Unknown";
            break;
    }
    return out;
}
