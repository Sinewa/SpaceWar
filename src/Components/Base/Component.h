#pragma once 

#include <vector>

namespace sf {
	class Drawable;
}

namespace SWGame {
	class BaseEntity;

	class Component {
	protected:
		BaseEntity* m_pOwner;
	public:
		virtual void Init(BaseEntity* owner);

		virtual void Update(BaseEntity* owner, float dt);
		virtual void GatherDraw(std::vector<sf::Drawable*>& retVal);
	};
}