#pragma once

#include <expected>
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/ItemStorage/Api/ExtractError.h"
#include "UnrealVoxelSim/Spatial/Api/Position.h"

namespace UnrealVoxelSim::ItemStorage::Api
{
	// Synchronous, simulation-thread-affine capability. Implementations add no implicit locking.
	class IRemover
	{
	public:
		virtual ~IRemover() = default;

		// Requires a contained item. Removes containment and establishes the supplied world position.
		// Commits both changes coherently; failure preserves the original state.
		[[nodiscard]] virtual std::expected<void, ExtractError> Extract(Ecs::Api::EntityId item,
																		Spatial::Api::Position position) = 0;
	};
}
