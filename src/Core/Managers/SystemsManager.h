#pragma once

#include <vector>

namespace sf {
	class Drawable;
}

namespace SWGame {
	class BaseSystem;

	class SystemsManager {
	protected:
		std::vector<BaseSystem*> m_aSystems;
	public:
		void Update(float dt);
		/**
		* Returns first found Component of a given type, null otherwise
		*/
		template<typename TSys>
		TSys* FindSystem() const {
			for (BaseSystem* sys: m_aSystems) {
				if (TSys* tsys = dynamic_cast<TSys*>(sys))
					return tsys;
			}
			return nullptr;
		}

		void GatherDraw(std::vector<sf::Drawable*>& retVal);

		void AddSystem(BaseSystem* sys);

	};
}