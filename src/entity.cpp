#include "entity.h"

Entity::Entity() {

}

Entity::~Entity() {

}

void Entity::Add(Entity* p) {
	p_sibling = p;
}

void Entity::AddChild(Entity* p) {
	p_child = p;
}
