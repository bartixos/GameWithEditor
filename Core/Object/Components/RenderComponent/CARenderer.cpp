#include "CARenderer.h"
#include "Core/Object/GameObject.h"
CARenderer::CARenderer(GameObject * owner) :
	AComponent(owner)
{
	componentType = ComponentType::Renderer;
}

void CARenderer::Initialize()
{
}