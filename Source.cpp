//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include "Utility/Define.h"
//#include "Core/Resource/FontManager.h"
//#include "Core/Resource/Resources.h"
//#include "Core/Math/Vector2.h"
//#include "imgui-master/imgui.h"
//#include "imgui-master/imgui-SFML.h"
//#include "Core/Object/GameObject.h"
//
//#include "cereal/archives/binary.hpp"
//#include "cereal/types/memory.hpp"
//#include <fstream>
//#include "Core/Object/Components/RenderComponent/CSpriteRenderer.h"
//int main()
//{
//	UniquePtr<GameObject> object = std::make_unique<GameObject>();
//	object->ComponentInitialize();
//
//	object->Initialize();
//
//	//int a = 20;
//	std::string file = "Save4.txt";
//	std::ofstream save(file);
//	{
//		cereal::BinaryOutputArchive archive(save);
//		object->SetTag("Kappa123");
//		object->SetName("Gracz 123");
//		object->GetTransform()->SetPosition(200, 300);
//
//		archive(CEREAL_NVP(object));
//	}
//	save.close();
//	UniquePtr<GameObject> object2;
//
//	{
//		std::ifstream load;
//		load.open(file);
//		if (load.is_open())
//		{
//			cereal::BinaryInputArchive archive(load);
//			archive(object2);
//
//			LOG(object2->GetName());
//			LOG(object2->GetTag());
//			LOG(object2->GetComponent<CSpriteRenderer>()->GetOffsetPosition().ToString());
//			LOG(object2->GetComponent<CSpriteRenderer>()->GetTextureName());
//			LOG(object2->GetComponent<CSpriteRenderer>()->GetTexturePath());
//			LOG(object2->GetComponentNumber());
//			load.close();
//		}
//	}
//
//	LOG(object2->GetName());
//	LOG(object2->GetTag());
//	LOG(object2->GetComponentNumber());
//	LOG(object2->GetComponent<CSpriteRenderer>()->GetOffsetPosition().ToString());
//	LOG(object2->GetComponent<CSpriteRenderer>()->GetTextureName());
//	LOG(object2->GetComponent<CSpriteRenderer>()->GetTexturePath());
//	LOG(object2->GetComponent<CSpriteRenderer>()->GetOffsetPosition().ToString());
//
//	object2->Initialize();
//	object2->ComponentInitialize();
//	LOG(object2->GetName());
//	LOG(object2->GetTag());
//	LOG(object2->GetComponent<CSpriteRenderer>()->GetOffsetPosition().ToString());
//	LOG(object2->GetComponent<CSpriteRenderer>()->GetTextureName());
//	LOG(object2->GetComponent<CSpriteRenderer>()->GetTexturePath());
//
//	LOG(1);
//
//	auto trans = object->GetComponent<CSpriteRenderer>();
//
//	sf::RenderWindow window(sf::VideoMode(1280, 800), "ImGui + SFML = <3");
//	window.setFramerateLimit(60);
//	ImGui::SFML::Init(window);
//
//	Vector2 cos;
//
//	object2->GetTransform()->SetPosition(400, 500);
//	sf::Clock deltaClock;
//
//	object2->SetComponentsOwner();
//	while (window.isOpen()) {
//		sf::Event event;
//		while (window.pollEvent(event)) {
//			ImGui::SFML::ProcessEvent(event);
//
//			if (event.type == sf::Event::Closed) {
//				window.close();
//			}
//		}
//
//		object2->Update(0.001f);
//		object2->ComponentUpdate(0.001f);
//
//		ImGui::SFML::Update(window, deltaClock.restart());
//
//		ImGui::Begin("Hello, world!", (bool*)0, ImGuiWindowFlags_::ImGuiWindowFlags_NoMove | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize);
//		ImGui::SetWindowPos({ 0,20 });
//		ImGui::SetWindowSize({ 200,800 });
//
//		if (ImGui::Button("Change Title"))
//		{
//			LOG(cos.ToString());
//		}
//
//		//	ImGui::Image(*resources->GetResource("Player"));
//		ImGui::InputFloat2("Vector", &cos.x);
//
//		ImGui::End();
//
//		window.clear();
//
//		object2->Draw(window);
//		//object->Draw(window);
//		ImGui::SFML::Render(window);
//		window.display();
//	}
//	ImGui::SFML::Shutdown();
//
//	//todo: do culling oclusion with window view
//	return 0;
//}

#include "Core/Game.h"

int main()
{
	UniquePtr<Game> game = std::make_unique<Game>();
	game->Initialize();
	return 0;
}