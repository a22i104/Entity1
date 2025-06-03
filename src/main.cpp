#include <iostream>
#include <chrono>
#include <thread>

#include "scene.h"
#include "player.h"

int main()
{
	Scene* scene = new Scene();

	Player* player = new Player();
	player->SetName("Player1");

	Player* player2 = new Player();
	player2->SetName("Player2");

	Player* child1 = new Player();
	child1->SetName("Player1Child1");

	Player* child2 = new Player();
	child2->SetName("Player2Child1");

	Player* child1_2 = new Player();
	child1_2->SetName("GAKIGAKI");

	Player* child2_2 = new Player();
	child2_2->SetName("2GAKIGAKI");


	player->AddChild(child1);
	player2->AddChild(child2);

	child1->Add(child1_2);
	child2->Add(child2_2);

	scene->AddEntity(player);
	scene->AddEntity(player2);

	scene->Start();

	using clock = std::chrono::steady_clock;
	using time_point = clock::time_point;
	using duration = clock::duration;

	const auto frame_duration = std::chrono::duration_cast<duration>(
		std::chrono::duration<double>(2.0)
	);

	time_point next_frame = clock::now();

	while (true) {
		scene->Update();

		std::cout << "Tick at "
			<< std::chrono::duration<double>(clock::now().time_since_epoch()).count()
			<< " sec\n";

		next_frame += frame_duration;
		std::this_thread::sleep_until(next_frame);
	}

	return 0;
}
