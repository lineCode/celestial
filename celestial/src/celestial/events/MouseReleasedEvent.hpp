///
/// MouseReleasedEvent.hpp
/// celestial
///
/// Refer to LICENSE.txt for more details.
///

#ifndef CELESTIAL_MOUSERELEASEDEVENT_HPP_
#define CELESTIAL_MOUSERELEASEDEVENT_HPP_

///
/// Core namespace.
///
namespace celestial
{
	///
	/// Contains data relating to a mouse released event.
	///
	struct MouseReleasedEvent final
	{
		///
		/// Default constructor.
		///
		MouseReleasedEvent() noexcept;

		///
		/// Constructor.
		///
		/// \param x x-pos of event.
		/// \param y y-pos of event.
		/// \param button Button code pressed.
		///
		MouseReleasedEvent(const int x, const int y, const unsigned int button) noexcept;

		///
		/// Default destructor.
		///
		~MouseReleasedEvent() = default;

		///
		/// Mouse x position.
		///
		int m_x;

		///
		/// Mouse y position.
		///
		int m_y;

		///
		/// Mouse button released.
		///
		unsigned int m_button;
	};
}

#endif