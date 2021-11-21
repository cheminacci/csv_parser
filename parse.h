#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

template<typename T>
auto Average(T& value)
{
	auto temp = 0 ;
	for(size_t i : value)
	{ temp+=i; }
	return (temp/value.size());
}

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
