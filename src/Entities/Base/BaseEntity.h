#pragma once 
#include <vector>

#include "src/Core/Utils/Utils.h"
#include "src/Core/Utils/Transformations.h"

namespace sf {
	class Drawable;
}

namespace SWGame {

	class Component;

	enum EntityFlags
	{
		EF_ACTIVE = BITF(0),
		EF_VISIBLE = BITF(1),
		EF_DELETE = BITF(2)
	};
	inline EntityFlags operator|(EntityFlags a, EntityFlags b)
	{
		return static_cast<EntityFlags>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
	}

	class BaseEntity {
	private:
		std::vector<Component*> m_aComponents;
		Flags<EntityFlags> m_entityFlags;
		Transformation m_transform;

	public:
		virtual void Init();

		bool IsFlag(EntityFlags flag) const;
		void SetFlags(EntityFlags flags);
		virtual void Update(float dt);
		virtual void GatherDraw(std::vector<sf::Drawable*>& retVal);

		void SetTranslation(const VecF& translation);
		const VecF& GetTranslation() const;
		void SetTransform(const Transformation& transform);
		const Transformation& GetTransform() const;



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