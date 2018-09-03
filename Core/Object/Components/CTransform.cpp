#include "CTransform.h"

#include <cereal/types/polymorphic.hpp>
CTransform::CTransform(GameObject * owner) :
	AComponent(owner)
{
	componentType = ComponentType::Transformable;
	//name = "TransformComponent";
}

CTransform::CTransform()
{
	componentType = ComponentType::Transformable;
}

void CTransform::Initialize()
{
	componentType = ComponentType::Transformable;
}