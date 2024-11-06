/*
  Given the following source code, which sentence is surely false

  - (Y) "lk" variable is useless in a serial() call, because semaphore is already mutual-exclusive
  - (N) "lk" variable is useless in a parallel() call, because each thread mantains its own file handlers
	terminate called after throwing an instance of 'std::system_error' for more than 1k threads
          what():  Resource temporarily unavailable
  - (Y) parallel() won't benefit in terms of speed
  - (Y) the range-based loop while joining threads is more efficient than index-based access to vector elements
*/

#include <iostream>
#include <mutex>
#include <fstream>
#include <thread>
#include <vector>
#include <sstream> //

constexpr auto TRIALS = 1'000;
std::mutex __mut;


int count_occurrences(int match)
{
	int a, occ = 0;

	std::ifstream ifs("./my.txt");
	std::lock_guard<std::mutex> lk(__mut);

	while (ifs >> a)
		occ += (match == a);

	if (occ != 1)
	{
		std::stringstream ss;
		ss << "count " << match << " -> " << occ << std::endl;
		std::cout << ss.str();
		//throw std::runtime_error(ss.str());
	}
	return occ;
}

void serial()
{
	for (int i=0; i<TRIALS; i++)
		count_occurrences(5);
}

void parallel()
{
        std::vector<std::thread> vt;
        for (int i =0; i < TRIALS; i++)
                vt.emplace_back(count_occurrences, 5);
        for (auto & t : vt)
                t.join();

}


int main()
{
		std::cerr << "SER\n";
	serial();
		std::cerr << "PAR\n";
	parallel();
}
