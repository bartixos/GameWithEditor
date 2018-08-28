#include <SFML/Graphics.hpp>
#include <iostream>
#include "imgui-master/imgui.h"
#include "imgui-sfml-master/imgui-SFML.h"
#include "Utility/Define.h"
#include "Core/Resource/FontManager.h"
#include "Core/Resource/Resources.h"
#include "Core/Math/Vector2.h"

int main()
{
	LOG(1);
	TextureManager::GetInstance();
	auto resources = TextureManager::GetInstance();
	auto font = FontManager::GetInstance();

	auto tex = resources->LoadResource("Player", "statek.png");

	sf::Texture textue = *resources->GetResource("Player");

	UniquePtr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
	sprite->setTexture(*tex);

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

		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::Begin("Hello, world!", (bool*)0, ImGuiWindowFlags_::ImGuiWindowFlags_NoMove | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize);
		ImGui::SetWindowPos({ 0,20 });
		ImGui::SetWindowSize({ 200,800 });

		if (ImGui::Button("Change Title"))
		{
			LOG(cos.ToString());
		}

		window.setView(view);
		ImGui::Image(*resources->GetResource("Player"));
		ImGui::InputFloat2("Vector", &cos.x);

		ImGui::End();

		window.clear();

		window.draw(*sprite);
		ImGui::SFML::Render(window);
		window.display();
	}
	ImGui::SFML::Shutdown();
	return 0;
}