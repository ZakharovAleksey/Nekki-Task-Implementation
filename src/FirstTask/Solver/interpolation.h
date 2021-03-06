#pragma once

#ifndef INTERPOLATION
#define INTERPOLATION

#include"iInterpolation.h"

#include<vector>

// Structure which store pair:
// - agr (argument or x-coordinate of the dot)
// - value (value or y = f(x) of this dot)
template<typename T>
struct Pair
{
	T arg;
	T value;

	Pair() : arg(T()), value(T()) { }
	Pair(T point, T value) : arg(point), value(value) { }
};

// Comparator for further std::sort procedure
template<typename T>
bool PairComparator(const Pair<T> & left, const Pair<T> & right)
{
	return (left.arg < right.arg) ? true : false;
}


// Parent for all Interpolation Solver classes
template<typename T>
class InterpolationSolver : public iInterpolation<T>
{
public:
	InterpolationSolver();
	virtual ~InterpolationSolver();

	// Get pairs from manager : Pair = ( x(Id = 0), y=f(x) (Id = 2))
	void SetInutPairs(const std::vector<Pair<T>> & inputPairs);

	// Get dots for further interpolation from manager
	void SetOutputPoints(const std::vector<T> & outputPoints);
	
	void BuildInterpolation() override;
	std::vector<Pair<T>> FindAllInterpolationValues() override;
	T FindInterpolationValue(T const x) override;

protected:
	// Store pairs from first input file
	std::vector<Pair<T>>  inputPairs_;
	// Store dots for interpolation from second input file
	std::vector<T>  dotsForInterpolation_;
};


#include"interpolation_impl.h"

#endif // !INTERPOLATION