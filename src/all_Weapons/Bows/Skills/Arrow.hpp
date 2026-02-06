#pragma once

#include "Projectile.hpp"

class Arrow : public Projectile {
	private:
		std::string _name;
	
	public:
		Arrow(float speed, float startX, float startY, float targetX, float targetY);
		~Arrow();
	
		std::string getName() const;
		Arrow* clone() const override;
};
