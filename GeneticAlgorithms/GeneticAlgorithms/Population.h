#pragma once

#include <vector>
#include <string>
#include <ctime>
#include <cmath>

class Population {
	using Chromosome = std::vector<bool>;

public:
	Population(int nr, int k, const std::pair<float, float>& x, const std::pair<float, float>& y);

	float FitnessFunction(const Chromosome& chromosome) const;

	std::vector<Chromosome> GetChromosomes() const;

private:
	std::pair<int, int> _binaryToDecimal(const Chromosome& chromosome) const;

private:
	std::vector<Chromosome> m_population;
	std::pair<float, float> m_x;
	std::pair<float, float> m_y;
};



