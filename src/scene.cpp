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
//�e���v��7�y�[�W�ڂ̑��������A���X�g�����̒ǉ��A�����A�擪�̒ǉ��A�擪�̏����@�v�b�V���o�b�N�A�v�b�V���t�����g�A�|�b�v�o�b�O�A�|�b�v�t�����g
