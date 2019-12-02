///
/// UITheme.cpp
/// celestial
///
/// Refer to LICENSE.txt for more details.
///

#include "UITheme.hpp"

namespace celestial
{
	UITheme::UITheme(ResourceLoader* resourceLoader)
		:m_resourceLoader(resourceLoader), m_font(nullptr), m_colour(nullptr), m_master(nullptr)
	{
	}

	UITheme::~UITheme()
	{
		m_font.reset();
		m_colour.reset();
		m_master.reset();

		// Cleanup, etc...
		m_widgetRegions.clear();
	}

	void UITheme::setMasterTexture(const std::string& texture)
	{
		m_master = m_resourceLoader->loadTexture(texture);
	}

	void UITheme::setFont(const std::string& font)
	{
		m_font = m_resourceLoader->loadFont(font);
	}
	
	void UITheme::defineWidgetTexture(const std::string& id, const celestial::Rect<int>& dim)
	{
		m_widgetRegions.emplace(id, dim);
	}

	TexturePtr UITheme::extractWidgetTexture(const std::string& id)
	{
		celestial::Rect<int> region = m_widgetRegions[id];
		return m_resourceLoader->loadSubBitmap(id, region);
	}

	const Font* UITheme::font() const noexcept
	{
		return m_font.get();
	}

	const celestial::Colour* UITheme::colour() const noexcept
	{
		return m_colour.get();
	}

	ResourceLoader* UITheme::loader() const noexcept
	{
		return m_resourceLoader;
	}
}