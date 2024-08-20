#pragma once 

#include "src/Core/World.h"
#include "src/Core/Utils/Transformations.h"

namespace SWGame {
	class BaseEntity;

	class MenuWorld : public World {
	protected:

		enum EMenuSelect {
			Play = 0,
			Score,
			Exit,
			Last = Exit,
			Count = Last + 1
		};

		const VecF m_selectorPositions[3] = {
			{ 300, 350 },
			{ 300, 400 },
			{ 300, 450 }
		};

		EMenuSelect m_eSelectedEntry;
		BaseEntity* m_selector;
	public:
		virtual void OnInit() override;
		virtual void ReInit() override;
		virtual void Load() override;
		virtual void Update(float dt) override;
	protected:
		void HandleConfirmation();
	};
}