#include "Music.h"

df::Music::Music()
	:m_label("")
{
}

int df::Music::loadMusic(std::string filename)
{
	if (m_music.openFromFile(filename) == false)
	{
		return -1;
	}
	return 0;
}

void df::Music::play(bool loop)
{
	m_music.setLoop(loop);
	m_music.play();
}

void df::Music::stop()
{
	m_music.stop();
}

void df::Music::pause()
{
	m_music.pause();
}
