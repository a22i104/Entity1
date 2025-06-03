#pragma once

#ifndef SCENE_H
#define SCENE_H

extern class Entity;

class Scene {
private:
	Entity* p_entity = __nullptr;

public:
	Scene();
	virtual ~Scene();

	void Start();
	void Update();
	void Start2(Entity* p);
	void Update2(Entity* p);

	void AddEntity(Entity* p);
};

#endif // !SCENE_H
