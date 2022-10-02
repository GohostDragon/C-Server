#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <Windows.h>

thread_local int32 LThread = 0;

void ThreadMain(int32 threadid)
{
    LThread = threadid;

    while (true)
    {
        cout << "Hi I am Thread " << LThread << endl;
        this_thread::sleep_for(1s);
    }
}

int main()
{
    vector<thread> threads;

    for (int32 i = 0; i < 10; i++)
    {
        int32 threadId = i + 1;
        threads.push_back(thread(ThreadMain, threadId));
    }

    for (thread& t : threads)
    {
        t.join();
    }
}