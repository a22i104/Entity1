#include "scene.h"
#include "entity.h"

Scene::Scene() {}

Scene::~Scene() {}

void Scene::AddEntity(Entity* p) {
	if (p_entity == nullptr) {
		p_entity = p;
	}
	else {
		Entity* ppp = p_entity;
		while (ppp->GetSibling() != nullptr) {
			ppp = ppp->GetSibling();
		}
		ppp->SetSibling(p);
	}
}

void Scene::Start() {

	Entity* ppp = p_entity;
	Start2(ppp);
}

void Scene::Update() {

	Entity* ppp = p_entity;
	Update2(ppp);
}
void Scene::Start2(Entity* p) {
	if (p == nullptr)
	{
		return;
	}
	p->Start();
	Start2(p->GetChild());
	Start2(p->GetSibling());


}

void Scene::Update2(Entity* p) {
	
	if (p == nullptr)
	{
		return;
	}
	p->Update();
	Update2(p->GetChild());
	Update2(p->GetSibling());


}
//テンプレ7ページ目の続きを作る、リスト末尾の追加、消去、先頭の追加、先頭の消去　プッシュバック、プッシュフロント、ポップバッグ、ポップフロント
