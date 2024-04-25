#pragma once

enum TexturKind
{
	TexturKindTitle,		//タイトル
	TexturKindMax,			//テクスチャの種類の最大
};

enum SceneType
{
	SceneTypeGame,	//GameScene
	SceneTypeTitle,//TitleScene
};

enum SceneStep
{
	SceneStepInit,		//初期化
	SceneStepRun,		//実行
	SceneStepFinish		//終了
};
