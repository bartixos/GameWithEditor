#include "WindowManager.h"
#include <SFML/Graphics.hpp>

sf::RenderWindow * WindowManager::CreateWindow(Vector2 size, const std::string & title) noexcept
{
	if (!window)
	{
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode(static_cast<unsigned int>(size.x), static_cast<unsigned int>(size.y)), title);
	}
	return window.get();
}

sf::RenderWindow * WindowManager::GetWindow() noexcept
{
	if (!window)
	{
		return CreateWindow();
	}
	return window.get();
}

void WindowManager::ResizeWindow(Vector2 size) noexcept
{
	if (window)
	{
		window->setSize(static_cast<sf::Vector2u>(size));
	}
}

void WindowManager::SetTitle(const std::string & _title) noexcept
{
	if (window)
	{
		window->setTitle(_title);
	}
}

void WindowManager::SetFrameLimit(int frameLimit) noexcept
{
	if (window)
	{
		window->setFramerateLimit(frameLimit);
	}
}