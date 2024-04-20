#include "zad.h"
#include <iostream>

MultiSet::MultiSet(){
	_buckets = nullptr;
	_bucketCount=0;
	_kBits=0;
	_elementsInBucket=0;
	_maxNumber=0;
	_maxCount=0;
}
MultiSet::MultiSet(unsigned maxNumber, unsigned kBits) {
	_maxNumber = maxNumber;
	if (kBits < 1 || kBits > 8)
	{
		std::cout << "Please enter a valid number between 1 and 8";
		kBits = 0;
		return;
	}
	else
	{
		_kBits = kBits;
	}
	_elementsInBucket = sizeof(uint8_t) * 8 / kBits + (sizeof(uint8_t) * 8 % kBits != 0);
	_bucketCount = maxNumber / _elementsInBucket + 1;
	_buckets = new uint8_t[_bucketCount];
	_maxCount = 2 ^ kBits - 1;
}
unsigned MultiSet::getKBits()const {
	return _kBits;
}
unsigned MultiSet::getMaxNumber()const {
	return _maxNumber;
}
void MultiSet::free()
{
	delete[] _buckets;
	_bucketCount = 0;
	_buckets = nullptr;
}
void MultiSet::copy(const MultiSet& other) {
	_buckets = new uint8_t[other._bucketCount];
	for (size_t i = 0; i < other._bucketCount; i++)
		_buckets[i] = other._buckets[i];
	_bucketCount = other._bucketCount;
	_kBits = other._kBits;
	_elementsInBucket = other._elementsInBucket;
	_maxNumber = other._maxNumber;
	_maxCount = other._maxCount;
}
MultiSet::MultiSet(const MultiSet& other) {
	copy(other);
}
MultiSet& MultiSet::operator=(const MultiSet& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}
unsigned MultiSet::getLastInd(const int& num) {
	return (((num + 1) * _kBits) % (sizeof(uint8_t) * 8)) - 1;
}
void MultiSet::addToArray(const int& num) {
	int size = _kBits;
	uint8_t* arr = new uint8_t[size];
	unsigned lastIndOfNum = getLastInd(num);
	for (size_t i = size; i > 0; i--)
	{
		arr[i] = lastIndOfNum;
		lastIndOfNum--;
	}
}
void MultiSet::addNumber(const int& num) {
	if (num>_maxNumber)
	{
		return;
	}
	unsigned whichBucket = num / _elementsInBucket;


}
//int main() {
//	MultiSet p(3,30);
//	std::cout<<p.getLastInd(5);
//}