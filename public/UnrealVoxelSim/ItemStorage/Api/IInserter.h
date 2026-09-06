#pragma once

#include <expected>
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/ItemStorage/Api/StoreError.h"

namespace UnrealVoxelSim::ItemStorage::Api
{
	// Synchronous, simulation-thread-affine capability. Implementations add no implicit locking.
	class IInserter
	{
	public:
		virtual ~IInserter() = default;

		// Requires ItemComponent. Establishes/transfers containment and removes PositionComponent.
		// Does not enforce subtype acceptance or capacity. Same-container storage succeeds unchanged.
		// Commits the transition coherently; failure preserves the original state.
		[[nodiscard]] virtual std::expected<void, StoreError> Store(Ecs::Api::EntityId item,
																	Ecs::Api::EntityId container) = 0;
	};
}
