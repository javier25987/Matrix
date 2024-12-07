#pragma once
#include<iostream>
class fraction
{
	int _numerator;
	int _denumerator;
	void reduce();
public:
	fraction(int numerator = 0, int denumerator = 1);
	friend std::ostream& operator<<(std::ostream& os, const fraction& f);

	// присваивающие операции
	fraction& operator+=(const fraction& that);
	fraction& operator-=(const fraction& that);
	fraction& operator*=(const fraction& that);
	fraction& operator/=(const fraction& that);

	// унарная оперция -
	fraction operator-() const;

	// арифметические оперции
	fraction operator+(const fraction& that) const;
	fraction operator-(const fraction& that) const;
	fraction operator*(const fraction& that) const;
	fraction operator/(const fraction& that) const;

	// преобразование в double
	operator double() const;
};

// арифметические оперции
fraction operator+(int number, const fraction& that);
fraction operator-(int number, const fraction& that);
fraction operator*(int number, const fraction& that);
fraction operator/(int number, const fraction& that);

