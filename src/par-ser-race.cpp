/**
 * Given the following source code, which sentence is not true at all.
 * 1. `lk` variable is inefficient in a `ser` call
 * 2. `lk` variable is useless in a `par` call, because each thread mantains its own file handlers
 * 3. by construction, `parallel` won't benefit in terms of speed
 * 4. the range-based loop while joining threads is more efficient than index-based access to `vt` elements
 */

#include <iostream>
#include <mutex>
#include <fstream>
#include <thread>
#include <vector>

constexpr int TRIALS = 100000;
std::mutex __mut;

auto cnt(int match) {
    int a, occ = 0;
    std::lock_guard<std::mutex> lk(__mut);
    std::ifstream ifs("./my.txt");
    while (ifs >> a)
        occ += (match == a);
    return occ;
}

void ser() {
    for (int i=0; i<TRIALS; i++)
        cnt(5);
}

void par() {
    std::vector<std::thread> vt;
    for (int i =0; i < TRIALS; i++)
        vt.emplace_back(cnt, 5);
    for (auto & t : vt)
        t.join();
}

int main(int argc, char**argv) {
    if (argc == 2)
        par();
    else
        ser();
    return 0;
}
