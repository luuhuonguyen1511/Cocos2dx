#include "Model.h"

Model::Model()
{
}

Model::~Model()
{
}

bool Model::IsAlive()
{
	return mIsAlive;
}

void Model::SetAlive(bool status)
{
	mIsAlive = status;
	mSprite->setVisible(mIsAlive);
}
