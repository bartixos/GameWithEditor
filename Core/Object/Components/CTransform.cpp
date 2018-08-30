#include "CTransform.h"

CTransform::CTransform(GameObject * owner) :
	AComponent(owner)
{
	componentType = ComponentType::Transformable;
	//name = "TransformComponent";
}

CTransform::CTransform(const AComponent & comp) :
	AComponent(comp)
{
}

CTransform::CTransform(AComponent && comp) :
	AComponent(std::move(comp))
{
}

void CTransform::Initialize()
{
}