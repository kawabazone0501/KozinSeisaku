#pragma once

#include<DxLib.h>
#include "Model.h"

class MikuObject
{
public:
	VECTOR GetMikuPos();
	VECTOR GetMikuFrontVector();

	void InitializedMiku();
	void UpdateMiku();
	void DrawMiku();

private:
	VECTOR Move01();


	AnimationModel model;
};


