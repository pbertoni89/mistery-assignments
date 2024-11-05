/*
 * Author: Patrizio Bertoni patrizio.bertoni.89@gmail.com
 * This file is intended for assestment purposes, and had been forked from
 * https://github.com/pbertoni89/mystery-assignments.
 * You should receive a copy of this, either as a pdf or raw text.
 * In no way this content shall suggest you the "mistery" behind the code.
 * Good luck!
 */

#include <cstring>
#include <utility>
#include <iostream>
#include <sstream>
#include <bitset>

template <typename D>
struct Mystery
{
	D d;
	struct Mystery * l, * r;

	explicit Mystery(const D & _d) :
		d(_d), l(nullptr), r(nullptr)
	{}

	[[nodiscard]] decltype(auto) wizard(const D & x) const
	{
		auto rv = (d == x);
		if (rv)
			return true;
		if (l != nullptr)
			rv |= l->wizard(x);
		if (r != nullptr)
			rv = rv or r->wizard(x);
		return rv;
	}
};


/**
 * <-- What's the purpose of mystery program ? -->
 */
int main(int argc, char ** argv)
{
	using MagicUint = Mystery<unsigned int>;

	auto hello_world = new MagicUint(1);

	hello_world->l = new MagicUint(2);
	hello_world->r = new MagicUint(5);
	hello_world->l->l = new MagicUint(3);

	MagicUint leaf = std::move(MagicUint(4));
	hello_world->l->r = &leaf;

	std::stringstream ss;
	for (auto a : {2, 6, 5, 0, 3, 11})
		ss << (hello_world->wizard(a) ? '1' : '0');

	std::bitset<8> rv;
	ss >> rv;
	std::cout << "the answer to every problem is " << rv.to_ulong() << std::endl;

	return 0;
}
