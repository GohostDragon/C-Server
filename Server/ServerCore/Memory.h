#pragma once
#include "Allocator.h"

class MemoryPool;

/*-----------
	Memory
------------*/

class Memory
{
	enum
	{
		// ~1024까지 32단위, ~2048까지 128단위, ~4096까지 256단위
		POOL_COUNT = (1024 / 32) + (1024 / 126) + (2048 / 256),
		MAX_ALLOC_SIZE = 4096
	
	};
public:
	Memory();
	~Memory();

	void*	Allocate(int32 size);
	void	Release(void* ptr);

private:
	vector<MemoryPool*> _pools;

	// 메모리 크기 <-> 메모리 풀
	// O(1) 빠르게 찾기 위한 테이블
	MemoryPool* _poolTable[MAX_ALLOC_SIZE + 1];
};

template<typename Type, typename... Args>
Type* xnew(Args&&... args)
{
	Type* memory = static_cast<Type*>(PoolAllocator::Alloc(sizeof(Type)));
	new(memory)Type(forward<Args>(args)...); // placement new (생성자 호출)
	return memory;
}

template<typename Type>
void xdelete(Type* obj)
{
	obj->~Type(); // 소멸자 호출
	PoolAllocator::Release(obj);
}

template<typename Type>
shared_ptr<Type> MakeShared()
{
	return shared_ptr<Type>{xxnew<Type>(), xdelete<Type>};
}