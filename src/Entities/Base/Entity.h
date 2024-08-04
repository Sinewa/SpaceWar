#pragma once 
#include <vector>

#include "src/Core/Utils.h"

namespace SWGame {

	class Component;

	enum EntityFlags
	{
		EF_ACTIVE = BITF(0),
		EF_VISIBLE = BITF(1)
	};

	class CoreEntity {
	private:
		std::vector<Component*> m_aComponents;
		Flags<EntityFlags> m_entityFlags;
	public:
		bool IsFlag(EntityFlags flag) const;
		void SetFlags(EntityFlags flags);
		virtual void Update(float dt);

		/**
		* Method for attaching Components to entity.
		* Entity takes full responsibility for destroying anything attached to it.
		*/
		void AddComponent(Component* comp);
		
		/**
		* Returns first found Component of a given type, null otherwise
		*/
		template<typename TComp>
		TComp* FindComponent() const {
			for (Component* comp : m_aComponents) {
				if (TComp* tcomp = dynamic_cast<TComp*>(comp))
					return tcomp;
			}
			return nullptr;
		}
	};
}