///
/// An animation for a sprite
/// 

#ifndef __ANIMATION_H__
#define __ANIMATION_H__

// System includes.
#include <string>

// Engine includes.
//#include "Box.h"
#include "Sprite.h"

namespace df 
{

	class Animation
	{

	private:
		Sprite* m_p_sprite;    ///< Sprite associated with Animation.
		int m_index;           ///< Current index frame for Sprite.
		int m_slowdown_count;  ///< Slowdown counter (-1 means stop).
		std::string m_name;    ///< Sprite name in ResourceManager.

	public:
		/// Animation constructor
		Animation();

		/// Set associated Sprite to new one.
		/// Note, Sprite is managed by ResourceManager.
		/// Set Sprite index to 0 (first frame).
		void setSprite(Sprite* p_new_sprite);

		/// Return pointer to associated Sprite.
		Sprite* getSprite() const { return m_p_sprite; }

		/// Set Sprite name (in ResourceManager).
		void setName(std::string new_name) { m_name = new_name; }

		/// Get Sprite name (in ResourceManager).
		std::string getName() const { return m_name; }

		/// Set index of current Sprite frame to be displayed.
		void setIndex(int new_index) { m_index = new_index; }

		/// Get index of current Sprite frame to be displayed.
		int getIndex() const { return m_index; }

		/// Set animation slowdown count (-1 means stop animation).
		void setSlowdownCount(int new_slowdown_count) { m_slowdown_count = new_slowdown_count; }

		/// Set animation slowdown count (-1 means stop animation).
		int getSlowdownCount() const { return m_slowdown_count; }

		///// Get bounding box of associated Sprite.
		//Box getBox() const;

		/// Draw single frame centered at position (x,y).
		/// Drawing accounts for slowdown, and advances Sprite frame.
		/// Return 0 if ok, else -1.
		int draw(Vector position);
	};

} // end of namespace df
#endif // __ANIMATION_H__
