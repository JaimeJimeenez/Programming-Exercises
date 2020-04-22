#pragma once

#include "Matrix.h"

template <typename A>
A add(const A& firstOperand, const A& secondOperand) {
	return firstOperand + secondOperand;
}

template <typename S>
S substract(const S& firstOperand, const S& secondOperand) {
	return firstOperand - secondOperand;
}

template <typename M>
M multiply(M& firstOperand, M& secondOperand) {
	return firstOperand * secondOperand;
}