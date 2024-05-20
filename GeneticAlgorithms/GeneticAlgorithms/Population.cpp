#include "Population.h"

#include <random>

Population::Population(int nr, int k, const std::pair<float, float>& x, const std::pair<float, float>& y)
	:m_population(std::vector<Chromosome>(nr, Chromosome(k)))
	, m_x(x)
	, m_y(y) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);

	for (int i = 0; i < nr; ++i) {
		for (int j = 0; j < k; ++j) {
			m_population[i][j] = dis(gen);
		}
	}
}

float Population::FitnessFunction(const Chromosome& chromosome) const {

	std::pair<float, float> values = _binaryToDecimal(chromosome);

	values.first = m_x.first + values.first * (m_x.second - m_x.first) / (1 << chromosome.size() - 1);
	values.second = m_y.first + values.second * (m_y.second - m_y.first) / (1 << chromosome.size() - 1);

	return 3.0f + abs(log(3.0f + sin(values.first) * 5.0f + tan(values.second)));
}

std::vector<Population::Chromosome> Population::GetChromosomes() const {
	return m_population;
}

std::pair<int, int> Population::_binaryToDecimal(const Chromosome& chromosome) const {

	int power = 1;
	int x = 0;
	int y = 0;

	for (int i = chromosome.size() / 2 - 1; i >= 0; --i) {
		x += power * chromosome[i];
		y += power * chromosome[i + chromosome.size() / 2];
		power *= 2;
	}

	return { x, y };
}