#include "../../Weapon.hpp"

class Sword : public Weapon {
    public:
        Sword(std::string name, std::string type, int dmg, int range, int as, int hands);
        void attack(Hero &target) override;
        ~Sword() override;
        Weapon* clone() const override;
};
