#include "CARenderer.h"
#include "Core/Object/GameObject.h"
#include <cereal/types/polymorphic.hpp>

CARenderer::CARenderer(GameObject * owner) :
	AComponent(owner)
{
	componentType = ComponentType::Renderer;
}

void CARenderer::Initialize()
{
}

//void CARenderer::Draw(sf::RenderWindow & window)
//{
//}