#include <SFML/Graphics.hpp>
#include <iostream>
#include "Utility/Define.h"
#include "Core/Resource/FontManager.h"
#include "Core/Resource/Resources.h"
#include "Core/Math/Vector2.h"
#include "imgui-master/imgui.h"
#include "imgui-master/imgui-SFML.h"
#include "Core/Object/GameObject.h"

int main()
{
	UniquePtr<GameObject> object = std::make_unique<GameObject>();
	object->ComponentInitialize();
	object->Initialize();
	LOG(1);

	auto trans = object->GetComponent<CSpriteRenderer>();

	sf::RenderWindow window(sf::VideoMode(1280, 800), "ImGui + SFML = <3");
	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);

	Vector2 cos;

	sf::View view({ 200,50 }, { 800, 600 });

	sf::Clock deltaClock;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		object->Update(0.001f);
		object->ComponentUpdate(0.001f);

		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::Begin("Hello, world!", (bool*)0, ImGuiWindowFlags_::ImGuiWindowFlags_NoMove | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize);
		ImGui::SetWindowPos({ 0,20 });
		ImGui::SetWindowSize({ 200,800 });

		if (ImGui::Button("Change Title"))
		{
			LOG(cos.ToString());
		}

		window.setView(view);
		//	ImGui::Image(*resources->GetResource("Player"));
		ImGui::InputFloat2("Vector", &cos.x);

		ImGui::End();

		window.clear();

		//window.draw(*sprite);
		object->Draw(window);
		ImGui::SFML::Render(window);
		window.display();
	}
	ImGui::SFML::Shutdown();
	return 0;
}