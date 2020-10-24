#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>

#include "Vector.h"
#include "Event.h"
#include "Animation.h"
namespace df
{

	// Types of solidness of Object.
	enum Solidness 
	{
		HARD,       // Object causes collisions and impedes.        //block
		SOFT,       // Object causes collision, but doesn't impede. //overlap
		SPECTRAL,   // Object doesn't cause collisions.				//ignore
	};


	class Object
	{
	private:
		int m_id;

		std::string m_type;

		Vector m_position;

		Vector m_velocity;

		Vector m_direction;

		float m_speed;

		int m_altitude;

		Solidness m_solidness;

		Animation m_animation;

		

	public:
		Object();

		virtual ~Object();

		virtual int eventHandler(const Event* p_e);

		void setId(int new_id);

		inline int getId() const { return m_id; }

		void setType(std::string new_type);

		inline std::string getType() const { return m_type; }

		void setPosition(Vector new_pos) ;

		inline Vector getPosition() const { return m_position; }

		inline void setAltitude(int new_altitude) { m_altitude = new_altitude; }

		inline int getAltitude() const { return m_altitude; }

		// Set speed of Object.
		void setSpeed(float new_speed) { m_speed = new_speed; }

		// Get speed of Object.
		float getSpeed() const { return m_speed; }

		// Set direction and speed of Object.
		void setVelocity(Vector new_velocity) { m_velocity = new_velocity; }

		// Get velocity of Object based on direction and speed.
		Vector getVelocity() const { return m_velocity; }

		// Predict Object position based on speed and direction.
		// Return predicted position.
		Vector predictPosition();

		// Set direction of Object.
		void setDirection(Vector new_direction);

		// Get direction of Object.
		Vector getDirection() const { return m_direction; }

		// Set solidness of Object, with checks for consistency.  
		// Return 0 if ok, else -1.
		int setSolidness(Solidness new_solid);

		// Return True if Object is HARD or SOFT, else false.
		bool isSolid() const;

		// Return solidness of Object.
		Solidness getSolidness() const { return m_solidness; }





		//// Set bounding box of Object.
		//void setBox(Box new_box);

		//// Get bounding box of Object.
		//Box getBox() const;

		// Set Sprite for this Object to animate.
		// Return 0 if ok, else -1.
		int setSprite(std::string sprite_label);

		// Set Animation for this Object to new one.
		// Set bounding box to size of associated Sprite.
		void setAnimation(Animation new_animation);

		// Get Animation for this Object.
		Animation getAnimation() const;

		virtual int draw();

	};

}




#endif