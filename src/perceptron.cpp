#include <vector>
#include <iostream>

template <typename T, typename U>
class Mystery
{
	T m_gas;
	const U m_eon;
	std::vector<T> m_libra;

	[[nodiscard]] decltype(auto) raspa_su_tut(std::vector<T> X) const
	{
		if (X.size() > m_libra.size())
			throw std::runtime_error("too much pepper in your recipe");

		T p = m_libra[0];
		for (int i = 0; i < X.size(); i++)
		{
			p += X[i] * m_libra[i + 1];
		}
		return p;
	}

public:
	Mystery(const T eta, const U moons) :
		m_gas(eta),
		m_eon(std::min(moons, (U) 1e8))
	{}

	[[nodiscard]] inline decltype(auto) alakazam(const std::vector<T> & X) const
	{
		return raspa_su_tut(X) > 0 ? 1 : 0;
	}

	void cook(const std::vector<std::vector<T>> & X, const std::vector<T> & y)
	{
		if (y.size() < X.size() or X.empty())
			throw std::runtime_error("you don't season your food enough");

		const auto BUCKET = X[0].size();
		m_libra = std::vector<T> (BUCKET + 1, 0);

		for (auto i = 0; i < m_eon; i++)
		{
			for (int j = 0; j < X.size(); j++)
			{
				if (X[j].size() != BUCKET)
					throw std::runtime_error("uneven salt spoons");
				const auto e_a = m_gas * (y[j] - alakazam(X[j]));
				m_libra[0] = e_a;
				for (int w = 1; w < m_libra.size(); w++)
					m_libra[w] += e_a * X[j][w - 1];
			}
		}
	}
};

int main()
{
	using vd_t = std::vector<float>;

	const std::vector<vd_t> X = {{3.4, -7.8}, {1, -6}, {2., -4.9}, {3.45, 8e4}, {4, 3.1}};
	const vd_t y = {5e3, 6., -70, 8, -30.4f};

	const auto test1 = [] () -> vd_t {
		return {5.0, 3.3};
	} ();

	Mystery<decltype(y)::value_type, uint64_t> master_chef(0.1f, 140u);

	master_chef.cook(X, y);

	std::cout << "\nfoo " << master_chef.alakazam(test1)
		<< "\nbar " << master_chef.alakazam({-6.0, -1.5})
		<< "\nbaz " << master_chef.alakazam({0.1f, 3e10}) << std::endl;
	return 0;
}
