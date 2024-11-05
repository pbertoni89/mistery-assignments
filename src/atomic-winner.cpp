/*
 * Author: Patrizio Bertoni patrizio.bertoni.89@gmail.com
 * This file is intended for assestment purposes, and had been forked from
 * https://github.com/pbertoni89/mystery-assignments.
 * You should receive a copy of this, either as a pdf or raw text.
 * In no way this content shall suggest you the "mistery" behind the code.
 * Good luck!
 */

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <future>

std::atomic<bool> fire(false);

std::atomic_flag winner = ATOMIC_FLAG_INIT;


template <typename T>
[[nodiscard]] T mystery(const T id)
{
	while (not fire)
		std::this_thread::yield();

	constexpr auto MILES = 1e6;
	for (volatile auto i = 0; i<MILES; ++i)
	{}

	if (not winner.test_and_set())
	{
		return id;
	}
	return -1;
}


template <typename D>
void wizard(const size_t N)
{
	std::vector<std::future<D>> threads;
	threads.reserve(N);
	std::cout << "spawning 10 threads that count to 1 million..." << std::endl;

	for (D i = 0; i < N; i++)
		threads.emplace_back(std::async(std::launch::deferred, [i] () { return mystery(i);}));

	fire = true;

	for (auto & th : threads)
	{
		std::cout << "Got " << th.get() << std::endl;
	}
}


/**
 * <-- What's the purpose of mystery program ? -->
 */
int main()
{
	wizard<int>(10);
	return 0;
}
