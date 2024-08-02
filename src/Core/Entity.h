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
	};
}