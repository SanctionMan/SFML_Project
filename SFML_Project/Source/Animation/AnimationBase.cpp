#include "AnimationBase.h"

AnimationBase::AnimationBase()
	: m_frameCurrent(0), m_frameStart(0), m_frameEnd(0),
	m_frameRow(0), m_frameTime(0.f), m_elapsedTime(0.f), m_frameActionStart(-1),
	m_frameActionEnd(-1), m_loop(false), m_playing(false) {}

AnimationBase::~AnimationBase()
{

}

// SETTERS
void AnimationBase::SetSpriteSheet(SpriteSheet* l_sheet) { m_spriteSheet = l_sheet; }
void AnimationBase::SetFrame(Frame l_frame)
{
	if ((l_frame >= m_frameStart && l_frame <= m_frameEnd) ||
		(l_frame >= m_frameEnd && l_frame <= m_frameStart))
	{
		m_frameCurrent = l_frame;
	}
}
void AnimationBase::SetStartFrame(Frame l_frame) { m_frameStart = l_frame; }
void AnimationBase::SetEndFrame(Frame l_frame) { m_frameEnd = l_frame; }
void AnimationBase::SetFrameRow(Frame l_row) { m_frameRow = l_row; }
void AnimationBase::SetActionStart(Frame l_frame) { m_frameActionStart = l_frame; }
void AnimationBase::SetActionEnd(Frame l_frame) { m_frameActionEnd = l_frame; }
void AnimationBase::SetFrameTime(float l_time) { m_frameTime = l_time; }
void AnimationBase::SetLooping(bool l_loop) { m_loop = l_loop; }
void AnimationBase::SetName(const std::string& l_name) { m_name = l_name; }

// GETTERS
SpriteSheet* AnimationBase::GetSpriteSheet() { return m_spriteSheet; }
Frame AnimationBase::GetFrame() { return m_frameCurrent; }
Frame AnimationBase::GetStartFrame() { return m_frameStart; }
Frame AnimationBase::GetEndFrame() { return m_frameEnd; }
Frame AnimationBase::GetFrameRow() { return m_frameRow; }
int AnimationBase::GetActionStart() { return m_frameActionStart; }
int AnimationBase::GetActionEnd() { return m_frameActionEnd; }
float AnimationBase::GetFrameTime() { return m_frameTime; }
float AnimationBase::GetElapsedTime() { return m_elapsedTime; }
bool AnimationBase::IsLooping() { return m_loop; }
bool AnimationBase::IsPlaying() { return m_playing; }

bool AnimationBase::IsInAction()
{
	if (m_frameActionStart == -1 || m_frameActionEnd == -1) { return true; }
	return (m_frameCurrent >= m_frameActionStart && m_frameCurrent <= m_frameActionEnd);
}

std::string AnimationBase::GetName()
{
	return m_name;
}

// FUNCTIONS
void AnimationBase::Play() { m_playing = true; }
void AnimationBase::Pause() { m_playing = false; }
void AnimationBase::Stop() { m_playing = false; Reset(); }
void AnimationBase::Reset()
{
	m_frameCurrent = m_frameStart;
	m_elapsedTime = 0.0f;
	CropSprite();
}
void AnimationBase::Update(const float& l_dT)
{
	if (!m_playing) { return; }
	m_elapsedTime += l_dT;
	if (m_elapsedTime < m_frameTime) { return; }
	FrameStep();
	CropSprite();
	m_elapsedTime = 0;
}
