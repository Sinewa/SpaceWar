#pragma once

#include <vector>

namespace sf {
	class Drawable;
}

namespace SWGame {
	class World;

	class BaseSystem {
		World* m_pWorld;
	public:
		virtual void Init(World* world);
		virtual void Load() {}
		virtual void Update(float dt) {}
		virtual void OnDiag(float dt) {}

		virtual void GatherDraw(std::vector<sf::Drawable*>& retVal) {}

		World* GetWorld() const;
	};
}