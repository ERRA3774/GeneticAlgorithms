#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <iomanip>

#include "Population.h"

static void OutputChromosomesToFile(const std::string& path, int populationSize, int genesCount, std::pair<float, float> paramX, std::pair<float, float> paramY) {

	Population pop(populationSize, genesCount, paramX, paramY);

	std::ofstream output(path);

	output << "#start\n\n";

	for (int i = 0; i < pop.GetChromosomes().size(); ++i) {

		output << "Generation no. " << i << "\n\n";

		output << "Chromorsome: ";
		for (int j = 0; j < pop.GetChromosomes()[i].size(); ++j) {
			output << pop.GetChromosomes()[i][j];
		}
		output << '\n';

		output << "Value: " << pop.FitnessFunction(pop.GetChromosomes()[i]) << "\n\n";
	}

	output << "#end";
}

static std::string CurrentTimeString() {
	std::time_t now = std::time(nullptr);
	std::tm localTime;
	localtime_s(&localTime, &now);

	std::ostringstream oss;
	oss << std::put_time(&localTime, "%Y%m%d-%H%M%S");
	return oss.str();
}

int main() {
	std::string timeString = CurrentTimeString();
	std::string fileName = "outputs/chromosomes-" + timeString + ".txt";

	OutputChromosomesToFile(fileName, 100, 20, { -5.f, 3.f }, { 2.f, 10.f });

	return 0;
}