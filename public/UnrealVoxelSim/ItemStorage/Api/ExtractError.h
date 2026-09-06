#pragma once

namespace UnrealVoxelSim::ItemStorage::Api
{
	enum class ExtractError
	{
		ItemNotAlive,
		ItemDestroying,
		NotItem,
		NotContained,
	};
}
