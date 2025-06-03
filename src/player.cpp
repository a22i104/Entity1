#include <iostream>

#include "player.h"

Player::Player()
	:Entity()
{
	
}

Player::~Player()
{
}

void Player::Start()
{
	std::cout << "call"<<GetName()<<"::Start" << std::endl;
}

void Player::Update()
{
	std::cout << "call"<<GetName()<<"::Update" << std::endl;
}
