#pragma once 

#include <vector>

namespace sf {
	class Drawable;
}

namespace SWGame {
	class BaseEntity;
	class World;

	class Component {
	protected:
		BaseEntity* m_pOwner = nullptr;
	public:
		virtual ~Component() = default;

		virtual void OnInit(BaseEntity* owner);
		virtual void OnDelete(BaseEntity* owner);

		virtual void Update(BaseEntity* owner, float dt);
		virtual void GatherDraw(std::vector<sf::Drawable*>& retVal);

		World* GetWorld() const;
	};
}