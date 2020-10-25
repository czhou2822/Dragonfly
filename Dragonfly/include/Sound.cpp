#include "Sound.h"

df::Sound::Sound()
	:m_label("")
{
}

df::Sound::~Sound()
{
	m_sound.resetBuffer();
}

int df::Sound::loadSound(std::string filename)
{

	if (m_sound_buffer.loadFromFile(filename) == false)
	{
		return -1;
	}

	m_sound.setBuffer(m_sound_buffer);

	return 0;
}

void df::Sound::play(bool loop)
{
	m_sound.setLoop(loop);
	m_sound.play();
}

void df::Sound::stop()
{
	m_sound.stop();
}

void df::Sound::pause()
{
	m_sound.pause();
}
