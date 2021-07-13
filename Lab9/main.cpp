#include <cassert>
#include "IceCube.h"
#include "ObjectPool.h"
#include "Game.h"

using namespace lab9;

int main()
{
	ObjectPool<IceCube> pool(3);

	assert(pool.GetMaxFreeObjectCount() == 3);
	assert(pool.GetFreeObjectCount() == 0);

	IceCube* i1 = pool.Get();

	i1->Initialize(5);

	IceCube* i2 = pool.Get();
	i2->Initialize(1);

	IceCube* i3 = pool.Get();
	i3->Initialize(4);

	assert(pool.GetFreeObjectCount() == 0);
	i1->Reset();
	pool.Return(i1);
	assert(pool.GetFreeObjectCount() == 1);

	IceCube* i4 = pool.Get();

	assert(i1 == i4);
	assert(!(i4->IsActive()));

	pool.Return(i2);
	pool.Return(i3);
	pool.Return(i4);

	Game game(1, 4);
	const std::vector<IceCube*>& activeGameObjects = game.GetActiveGameObjects();
	assert(activeGameObjects.size() == 0);

	game.Spawn();
	game.Spawn();
	game.Spawn();
	game.Spawn();
	game.Spawn();

	assert(activeGameObjects.size() == 5);
	assert(activeGameObjects[0]->IsActive());
	assert(activeGameObjects[1]->IsActive());
	assert(activeGameObjects[2]->IsActive());
	assert(activeGameObjects[3]->IsActive());
	assert(activeGameObjects[4]->IsActive());

	const IceCube* i5 = activeGameObjects[3];

	game.Update();

	const std::vector<IceCube*>& activeGameObjects2 = game.GetActiveGameObjects();
	assert(activeGameObjects2.size() == 4);
	assert(activeGameObjects[0] == activeGameObjects2[0]);
	assert(activeGameObjects[1] == activeGameObjects2[1]);
	assert(activeGameObjects[2] == activeGameObjects2[2]);
	assert(activeGameObjects[3] == activeGameObjects2[3]);

	auto& op2 = game.GetObjectPool();
	IceCube* i6 = op2.Get();

	assert(i6 == i5);

	op2.Return(i6);
}