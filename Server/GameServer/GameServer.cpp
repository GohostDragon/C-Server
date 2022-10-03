#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <Windows.h>
#include "ThreadManager.h"

int main()
{
	/*
	shared_ptr : RefCount 0이 되면 소멸(shared 0), 하지만 서로 참조하는 경우
	해제를 못하는 경우가 있어 메모리 릭이 생긴다
	weak_ptr : 서로s 참조 에러를 해결하기 위해 weakCount 숫자를 올리도록 한다
	shared 포인트가 없어지면 소멸하지만 weakCount가 남아있을 경우
	RefCountBlock이 존재한다!

	[T*][RefCountBlock(shared, weakCount)]
	*/
}