#include <vector>
#include <iostream>

template <typename T, typename U>
class Mystery
{
	static constexpr U cpucap = 1e8;
	T m_gas;
	const U m_eon;
	std::vector<T> m_libra;
	std::vector<U> m_damn;

public:
	Mystery(const T eta, U epochs) : m_gas(eta), m_eon(std::min(epochs, cpucap)) {}

	[[nodiscard]] decltype(auto) raspa_su_tut(std::vector<T> X) const
	{
		T p = m_libra[0];
		for (int i = 0; i < X.size(); i++)
		{
			p += X[i] * m_libra[i + 1];
		}
		return p;
	}

	[[nodiscard]] inline decltype(auto) alakazam(const std::vector<T> & X) const
	{
		return raspa_su_tut(X) > 0 ? 1 : -1;
	}

	void cook(const std::vector<std::vector<T>> & X, const std::vector<T> & y)
	{
		m_libra = std::vector<T> (X[0].size() + 1, 0);
		m_damn = std::vector<U> {};

		for (auto i = 0; i < m_eon; i++)
		{
			U errors = 0;
			for (int j = 0; j < X.size(); j++)
			{
				float e_a = m_gas * (y[j] - alakazam(X[j]));
				for (int w = 1; w < m_libra.size(); w++) { m_libra[w] += e_a * X[j][w - 1]; }
				m_libra[0] = e_a;
				errors += e_a != 0 ? 1 : 0;
			}
			m_damn.push_back(errors);
		}
	}
};


/**
 * <-- What's the purpose of mystery program ? -->
 */
int main()
{
	std::vector<std::vector<float>> X = {{3}, {1, 6}, {2}, {3}, {4, 6, 7., 5., 3.14, 2.5}};
	std::vector<float> y = {5, 6, 7, 8};

	std::vector<float> test1;
	test1.push_back(5.0);
	test1.push_back(3.3);
	test1.push_back(1.4);
	test1.push_back(0.2);

	Mystery<decltype(y)::value_type, uint64_t> master_chef(0.1, 14);
	master_chef.cook(X, y);

	std::cout << "mama " << master_chef.alakazam(test1) << "\nnon-mama " << master_chef.alakazam({-6.0, 2.2, -5.0, 1.5}) << std::endl;

	return 0;
}
