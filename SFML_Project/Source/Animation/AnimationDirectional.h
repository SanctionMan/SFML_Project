#pragma once
#include "AnimationBase.h"
#include "Directions.h"

class AnimationDirectional : public AnimationBase {
protected:
	void FrameStep();
	void CropSprite();
	void ReadIn(std::stringstream& l_stream);
};