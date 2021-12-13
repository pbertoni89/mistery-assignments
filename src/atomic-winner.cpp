
// constructing atomics
#include <iostream>       // std::cout
#include <atomic>         // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <thread>         // std::thread, std::this_thread::yield
#include <vector>         // std::vector


std::atomic<bool> fire(false);

std::atomic_flag winner = ATOMIC_FLAG_INIT;


// using tci_t = std::pair<int, int>;
// std::atomic<tci_t> atci;


template <typename T>
T mystery(const T id)
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
};


template <typename D>
void wizard(const size_t N)
{
	std::vector<std::future<D>> threads;
	std::cout << "spawning 10 threads that count to 1 million..." << std::endl;

	for (int i = 0; i < N; i++)
	{
		threads.push_back(std::thread(mystery, i));
	}

	fire = true;

	for (auto & th : threads)
	{
		th.join();
	}
}


int main()
{
	return wizard<int>(10);
}
