#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <numeric>

template<typename T>
constexpr double moving_average(T& value, size_t period, size_t position)
	{ return (std::accumulate(&value[position], &value[position+period], 0.0) / (double)period ); }

struct Candle 
{
	std::string date;
	std::string time;
	double open;
	double high;
	double low;
	double close;
	double volume;
};

void Parse();
