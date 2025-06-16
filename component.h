#pragma once
#include <functional>
#include <iostream>
#include <vector>

template <typename T>
class ComponentManager {
private:
	std::unordered_map<ComponentTypeID, ComponentPoolBase*>
		componentPools;
public:
	template <typename T>
	void RegisterComponent()
	{
		ComponentTypeID typeID = GetComponentTypeID<T>();
		componentPools[typeID] = new ComponentPool<T>();
	}
	template <typename T>
	void AddComponent(EntityID entity, const T& component)
	{
		auto pool = static_cast<ComponentPool<T>*>(
			componentPools[GetComponentTypeID<T>()]);
		pool->Insert(entity, component);
	}

	template <typename T>
	T* GetComponent(EntityID entity)
	{
		auto pool = static_cast<ComponentPool<T>*>(
			componentPools[GetComponentTypeID<T>()]);
		return pool->Get(entity);
	}
	~ComponentManager()
	{
		for (auto& [_, pool] : componentPools) {
			delete pool;
		}
	}
};
