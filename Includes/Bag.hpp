#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

class Gear;
class Weapon;

class Bag {
    private:
        std::vector<Weapon*> _all_weapons;
        std::vector<Gear*> _all_gears;
    public:
        Bag() = default;
        ~Bag();
        Bag(const std::vector<Weapon*> &all_weapons, const std::vector<Gear*> &all_gears);
        Bag(const Bag &other);
        Bag& operator=(const Bag &other);

        const std::vector<Weapon*> &getAll_weapons() const;
        const std::vector<Gear*> &getAll_gears() const;

        std::vector<Weapon*> &getAll_weapons();
        std::vector<Gear*> &getAll_gears();

        void add_weapon(Weapon *new_weapon);
        void add_gear(Gear *new_gear);
		template<typename T>
		void remove_item(std::vector<T*> &items, T* item) {
			auto it = std::find(items.begin(), items.end(), item);
			if (it != items.end()) {
				std::cout << "Dropped " << item->getName() << std::endl;
				items.erase(it);
			}
		}
};
