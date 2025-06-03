#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity {
private:

public:
	Player();
	virtual ~Player();

	void Start();
	void Update();
};


#endif // !PLAYER_H
