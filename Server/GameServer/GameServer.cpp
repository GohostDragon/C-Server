#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <Windows.h>

atomic<bool> flag;

int main()
{
    flag = false;

    // flag = true
    flag.store(true);

    //bool val = flag
    bool val = flag.load();

    // 이전 flag 값을 prev에 넣고 flag 값을 수정
    {
        bool prev = flag.exchange(true);
        //bool prev =flag;
        //flag = true;
    }

    // CAS (Compare-And_Swap) 조건부 수정
    {
        bool expected = false;
        bool desired = true;
        flag.compare_exchange_strong(expected, desired);
        /*
        if (flag == expected)
        {
            flag = desired;
            return true;
        }
        else
        {
            expected = flag;
            return false;
        }
        */

        bool expected = false;
        bool desired = true;
        // strong이랑 기본적으로 똑같지만 중간에 다른 스레드의 인터럽트를 받아서 중간에 실패할 수 있음
        flag.compare_exchange_weak(expected, desired);
    }
}