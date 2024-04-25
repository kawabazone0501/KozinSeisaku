#include "SceneFactory.h"

SceneBase* SceneFactory::Create(SceneBase::Type type_)
{
	SceneBase* new_scene = nullptr;

	switch (type_)
	{
	case SceneBase::Type::Title:
		break;
	case SceneBase::Type::Game:
		break;
	}

	return new_scene;
}
