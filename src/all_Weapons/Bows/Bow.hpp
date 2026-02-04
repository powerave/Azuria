#include "../../Weapon.hpp"

class Bow : public Weapon {
    public:
        Bow(std::string name, std::string type, int dmg, int range, int as, int hands);
        void attack(Hero &target) override;
        ~Bow() override;
        Weapon* clone() const override;
};
