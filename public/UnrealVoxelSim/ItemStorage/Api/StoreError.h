#pragma once

namespace UnrealVoxelSim::ItemStorage::Api
{
	enum class StoreError
	{
		ItemNotAlive,
		ContainerNotAlive,
		ItemDestroying,
		ContainerDestroying,
		NotItem,
		ContainmentCycle,
	};
}
