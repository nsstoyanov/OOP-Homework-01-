#pragma once
class MultiSet {
	uint8_t* _buckets;
	unsigned _bucketCount;
	unsigned _kBits;//k
	unsigned _elementsInBucket;
	unsigned _maxNumber;//n
	unsigned _maxCount;
	
	void free();
	void copy(const MultiSet& other);
	void addToArray(const int& num);

public:
	MultiSet();
	MultiSet(unsigned maxNumber, unsigned kBits);
	MultiSet(const MultiSet& other);
	MultiSet& operator=(const MultiSet& other);
	~MultiSet();


	unsigned getMaxNumber() const;
	unsigned getKBits() const;
	unsigned getLastInd(const int& num);

	void addNumber(const int& num);
};
