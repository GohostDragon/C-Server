#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <Windows.h>
#include "ThreadManager.h"
#include "Memory.h"

class Player
{
public:
	Player() {}
	virtual ~Player() {}
};

class Knight : public Player
{
public:
	Knight() {}
	~Knight() {}

	int32 _hp = 100;
	int32 _mp = 10;
};

int main()
{
	Vector<int32> v;
	string
}