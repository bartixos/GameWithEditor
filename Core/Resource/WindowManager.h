#pragma once
#include "Utility/ASingleton.h"
#include "Utility/Define.h"
#include "Core/Math/Vector2.h"
namespace sf
{
	class RenderWindow;
	class View;
}

class WindowManager : public ASingleton<WindowManager>
{
	UniquePtr<sf::RenderWindow> window = nullptr;
public:

	sf::RenderWindow* CreateWindow(Vector2 size = Vector2(800, 600), const std::string& title = "Title") noexcept;
	sf::RenderWindow* GetWindow() noexcept;
	void ResizeWindow(Vector2 size) noexcept;
	void SetTitle(const std::string &_title) noexcept;
	void SetFrameLimit(int frameLimit) noexcept;
};
