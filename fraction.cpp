#include "fraction.h"
#include <stdexcept>

int greatest_common_divisor(int numerator, int denumerator) {
	if (!denumerator)
	{
		return numerator;
	}
	return greatest_common_divisor(denumerator, numerator % denumerator);
}

void fraction::reduce()
{
	if (_denumerator < 0)
	{
		_numerator *= -1;
		_denumerator *= -1;
	}
	const auto gcd = abs(greatest_common_divisor(_numerator, _denumerator));
	_denumerator /= gcd;
	_numerator /= gcd;
}

fraction::fraction(int numerator, int denumerator)
{
	if (!denumerator)
	{
		throw std::range_error("");
	}
	_numerator = numerator;
	_denumerator = denumerator;
	reduce();
}

fraction& fraction::operator+=(const fraction& that)
{
	this->_numerator = this->_numerator * that._denumerator + that._numerator * _denumerator;
	this->_denumerator *= that._denumerator;
	reduce();
	return *this;
}

fraction& fraction::operator-=(const fraction& that)
{
	*this += (-that);
	reduce();
	return *this;
}

fraction& fraction::operator*=(const fraction& that)
{
	_numerator *= that._numerator;
	_denumerator *= that._denumerator;
	reduce();
	return *this;
}

fraction& fraction::operator/=(const fraction& that)
{
	if (!that._numerator)
	{
		throw std::range_error("");
	}
	_numerator *= that._denumerator;
	_denumerator *= that._numerator;
	reduce();
	return *this;
}

fraction fraction::operator-() const
{
	return { -_numerator, _denumerator };
}

fraction fraction::operator+(const fraction& that) const
{
	auto temp = *this;
	return temp += that;
}


fraction fraction::operator-(const fraction& that) const
{
	auto temp = *this;
	return temp -= that;
}

fraction fraction::operator*(const fraction& that) const
{
	auto temp = *this;
	return temp *= that;
}

fraction fraction::operator/(const fraction& that) const
{
	auto temp = *this;
	return temp /= that;
}

fraction::operator double() const
{
	return static_cast<double>(_numerator) / _denumerator;
}

std::ostream& operator<<(std::ostream& os, const fraction& f)
{
	os << f._numerator;
	if (f._denumerator != 1)
	{
		os << "/" << f._denumerator;
	}
	return os;
}

fraction operator+(int number, const fraction& that)
{
	auto temp = that;
	return temp += number;
}

fraction operator-(int number, const fraction& that)
{
	fraction temp = number;
	return temp -= that;
}

fraction operator*(int number, const fraction& that)
{
	return that * fraction(number);
}

fraction operator/(int number, const fraction& that)
{
	fraction temp = number;
	return temp /= that;
}