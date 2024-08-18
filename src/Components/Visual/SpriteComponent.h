#pragma once
#include <iostream>

#include "src/Components/Base/Component.h"
#include "src/Core/Utils/Transformations.h"

namespace sf {
	class Texture;
	class Sprite;
}

namespace SWGame {
	class SpriteComponent : public Component {
		sf::Sprite* m_sprite;
	public:
		virtual void OnInit(BaseEntity* owner) override;
		SpriteComponent();
		SpriteComponent(const std::string& fileName);

		virtual void Update(BaseEntity* owner, float dt) override;
		virtual void GatherDraw(std::vector<sf::Drawable*>& retVal) override;

		unsigned int GetSize() const;
		VecF GetOrigin() const;
	protected:
		bool LoadTexture(const std::string& fileName);
	};
}