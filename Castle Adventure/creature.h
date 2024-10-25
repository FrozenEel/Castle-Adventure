#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <sstream>

class Creature
{
    protected:
        int m_health;
        int m_attackPower;
        int m_defensePower;

        Creature(int h=5, int a=5, int d=5): m_health(h), m_attackPower(a), m_defensePower(d) {}
        virtual ~Creature() {}

    public:
        std::string toString() const 
        { 
            std::ostringstream ss;
            ss << "health: " << m_health << ", attack: " << m_attackPower << ", defense: " << m_defensePower << std::endl;
            return ss.str();
        }
        bool isAlive() const { return m_health > 0; }
        bool isDead() const { return !isAlive(); }
        int getHealth() const  { return m_health; }
        int getAttackPower() const  { return m_attackPower; }
        int getDefensePower() const  { return m_defensePower; }

        virtual void attack(Creature & creature) = 0;
        virtual void takeDamage(int damage) = 0;
};
#endif