#include <iostream>

#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>


template <typename F>
[[nodiscard]] decltype(auto) mystery(F xlow, F xhigh, const uint64_t n_iters)
{
	boost::mt19937 igen;

	typedef boost::normal_distribution<F> distr_t;
	using t_my_gen = boost::variate_generator<boost::mt19937, distr_t>;

	t_my_gen gen(igen, distr_t());

	uint64_t k = 0;

	for (uint64_t i=0; i<n_iters; ++i)
	{
		const auto x = gen();

		if (x>= xlow and x<xhigh)
		{
			k ++;
		}
	}
	return (F) k / (F) n_iters;
}


/**
 * <-- What's the purpose of mystery program ? A possible output is -->
 *
 * Mystery : 0.841625
 * Expected: 0.841345
 */
int main()
{
	constexpr double X_LOW = -14.0, X_HIGH = 1.0;

	const auto RES_EXPECTED = 0.5 * (erf(X_HIGH / sqrt(2.0)) - erf(X_LOW / sqrt(2.0))),
		RES_MISTERY = mystery(X_LOW, X_HIGH, 1000000);

	std::cout << "Mystery : " << RES_MISTERY << "\nExpected: " << RES_EXPECTED << std::endl;
}
