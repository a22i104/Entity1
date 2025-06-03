#pragma once

#ifndef CHILD_H
#define CHILD_H

#include "entity.h"

class Child : public Entity {
private:

public:
	Child();
	virtual ~Child();

	void Start();
	void Update();
};


#endif // !PLAYER_H
