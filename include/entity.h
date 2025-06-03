#pragma once
#include <string>
#ifndef ENTITY_H
#define ENTITY_H

class Entity {
private:
	Entity* p_sibling = __nullptr;
	Entity* p_child = __nullptr;
	
	std::string name;
	float pos_x = 0.0f;
	float pos_y = 0.0f;
	float pos_z = 0.0f;
	bool is_active = true;

public:
	Entity();
	virtual ~Entity();

	Entity* GetSibling() const { return p_sibling; }
	Entity* GetChild() const { return p_child; }
	std::string GetName() const { return name; }
	void SetSibling(Entity* s) { p_sibling = s; }
	void SetChild(Entity* c) { p_child = c; }
	void SetName(const std::string& name_) { name = name_; }

		
	float X() const { return pos_x; }
	float Y() const { return pos_y; }
	float Z() const { return pos_z; }

	void SetXYZ(float x, float y, float z) {
		pos_x = x;
		pos_y = y;
		pos_z = z;
	}

	void Add(Entity* p);
	void AddChild(Entity* p);

	virtual void Start() = 0;
	virtual void Update() = 0;
};

#endif // !ENTITY_H
