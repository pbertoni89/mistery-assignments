#include <cstring>
#include <utility>
#include <iostream>
#include <sstream>
#include <bitset>


template <typename D>
struct Mistery
{
	D d;
	struct Mistery * l, * r;

	explicit Mistery(const D & _d) :
		d(_d), l(nullptr), r(nullptr)
	{}

	decltype(auto) wizard(const D & x) const
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
 * <-- What does main do? -->
 */
int main(int argc, char ** argv)
{
	using MagicUint = Mistery<unsigned int>;

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
