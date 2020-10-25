//
// Box - A 2-d bounding box.
//
// Copyright 2017 by Mark Claypool and WPI
// All Rights Reserved
//

#ifndef __BOX_H__
#define __BOX_H__

#include "Vector.h"

namespace df 
{

	class Box 
	{

	private:
		Vector m_corner;         // Upper left corner of box.
		float m_horizontal;	   // Horizontal dimension.
		float m_vertical;	   // Vertical dimension.

	public:
		// Create box with (0,0) for corner, and 0 for horiz and vert.
		Box() = default;

		// Create box with upper-left corner, horiz and vert sizes.
		Box(Vector init_corner, float init_horizontal, float init_vertical);

		// Set upper left corner of box.
		void setCorner(Vector new_corner) { m_corner = new_corner; }

		// Get upper left corner of box.
		Vector getCorner() const { return m_corner; }

		// Set horizontal size of box.
		void setHorizontal(float new_horizontal) { m_horizontal = new_horizontal; }

		// Get horizontal size of box.
		float getHorizontal() const { return m_horizontal; }

		// Set vertical size of box.
		void setVertical(float new_vertical) { m_vertical = new_vertical; }

		// Get vertical size of box.
		float getVertical() const { return m_vertical; }
	};

} // end of namespace df

#endif
