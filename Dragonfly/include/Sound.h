//
// Sound - A wrapper for SFML sound.
// 
// Copyright 2017 by Mark Claypool and WPI
// All Rights Reserved
//

#ifndef __SOUND_H__
#define __SOUND_H__

// System includes.
#include <string>
#include <SFML/Audio.hpp>

namespace df 
{

	class Sound 
	{

	private:
		sf::Sound m_sound;	          // SFML sound.
		sf::SoundBuffer m_sound_buffer; // SFML sound buffer associated with sound.
		std::string m_label;	          // Text label to identify sound.

	public:

		// Constructor.
		Sound();

		// Destructor.
		~Sound();

		// Load sound buffer from file.
		// Return 0 if ok, else -1.
		int loadSound(std::string filename);

		// Set label associated with sound.
		void setLabel(std::string new_label) { m_label = new_label; }

		// Get label associated with sound.
		std::string getLabel() const { return m_label; }

		// Play sound.
		// If loop is true, repeat play when done.
		void play(bool loop = false);

		// Stop sound.
		void stop();

		// Pause sound.
		void pause();

		// Return SFML sound.
		sf::Sound getSound() const { return m_sound; }
	};

} // end of namespace df
#endif // __SOUND_H__
