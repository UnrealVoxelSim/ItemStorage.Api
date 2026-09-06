# UnrealVoxelSim.ItemStorage.Api

Header-only `IInserter::Store` and `IRemover::Extract` contracts for generic item storage transitions.

`Store` requires an item marker, transfers containment, and removes the item's world position. `Extract` requires a
contained item, removes containment, and establishes the supplied position. Each transition is coherent and preserves
original state on failure. Storing in the current container succeeds without change. Queries use `Containers.Api`.

Subtype acceptance and capacity belong to specialized wrappers. Composition supplies this inserter only to those
wrappers; its implementation receives the lower-level containment capabilities. Those implementation dependencies do
not need to be public dependencies of this interface-only target.

All capabilities are synchronous and confined to the owning simulation thread. Returned query containers are owned
snapshots. Entity references are non-owning and scoped to one registry; they are not persistent save identities.
Components are public read contracts; composition grants mutation authority only to the owning domain.

## Build validation

Use a Visual Studio developer environment with CMake, Ninja, and `VCPKG_ROOT` available:

```powershell
cmake --preset windows-msvc-debug
cmake --build --preset windows-msvc-debug
cmake --preset windows-msvc-release
cmake --build --preset windows-msvc-release
```

The default build compiles each public header in isolation and verifies that interfaces remain abstract with virtual
destructors. This module contains no runtime implementation or behavioral tests yet. Linux Clang presets are also provided.
