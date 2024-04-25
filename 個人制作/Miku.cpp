#include <math.h>
#include <DxLib.h>
#include "Model.h"
#include "Miku.h"


MikuObject g_Miku;

VECTOR MikuObject::GetMikuPos()
{
	return model.pos;
}

VECTOR MikuObject::GetMikuFrontVector()
{
	return model.frontVector;
}

void MikuObject::InitializedMiku()
{
	model.pos = VGet(0.0f, 0.0f, 0.0f);
	model.scale = VGet(0.5f, 0.5f, 0.5f);
	model.rotateAngle = VGet(0.0f, 0.0f, 0.0f);
	model.modelKind = ModelKind::Miku;
	model.animTimer = 0.0f;
	model.animTime = 0.0f;
	model.animType = AnimType::Wait;
	model.frontVector = VGet(0.0f, 0.0f, -1.0f);

	ChangeAnimation(GetModelHandle(model.modelKind), AnimType::Wait, model.animType, model.animTimer, model.animTime);
}

void MikuObject::UpdateMiku()
{
	float roate_speed = 3.0f;
	float add_rotate = 0.0f;
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		add_rotate -= roate_speed;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		add_rotate += roate_speed;
	}

	if (add_rotate != 0.0f)
	{
		model.rotateAngle.y += add_rotate;

		float rad = model.rotateAngle.y * (DX_PI / 180.0f);
		float front_vec_x = -sinf(rad);
		float front_vec_y = -cosf(rad);
		model.frontVector = VGet(front_vec_x, 0.0f, front_vec_y);
	}

	float move_speed = 0.5f;
	//移動キー入力
	if (CheckHitKey(KEY_INPUT_UP))
	{
		VECTOR new_pos = Move01();
		new_pos.y += 1.0f;

		MV1_COLL_RESULT_POLY result = MV1CollCheck_Line(
			GetModelHandle(ModelKind::Island),
			-1,
			new_pos,
			VGet(new_pos.x, new_pos.y - 100.0f, new_pos.z)
		);

		if (result.HitFlag == 1)
		{
			new_pos.y = result.HitPosition.y;
			model.pos = new_pos;
		}

		if (model.animType != AnimType::Run)
		{
			ChangeAnimation(GetModelHandle(model.modelKind), AnimType::Run, model.animType, model.animTimer, model.animTime);
		}
	}
	else
	{
		if (model.animType != AnimType::Wait)
		{
			ChangeAnimation(GetModelHandle(model.modelKind), AnimType::Wait, model.animType, model.animTimer, model.animTime);

		}
	}

	if (PlayAnimation(model.animTimer, model.animTime) == true)
	{
		// タイマーをリセット
		model.animTimer = 0.0f;
	}
}

void MikuObject::DrawMiku()
{
	DrawAnimationModel(&model);
}

VECTOR MikuObject::Move01()
{
	float move_speed = 0.5f;
	VECTOR new_pos = model.pos;
	new_pos.x += model.frontVector.x * move_speed;
	new_pos.z += model.frontVector.z * move_speed;
	return new_pos;
}

