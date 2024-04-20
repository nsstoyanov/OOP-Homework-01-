#include <iostream>

const int MAX_BUCKET_SIZE = sizeof(uint8_t) * 8;
unsigned firstIndxOfNumber(const uint8_t& num, unsigned _kBits) {
	return (num * _kBits) % MAX_BUCKET_SIZE;
}

unsigned getStartingBucketIndex(unsigned num, unsigned kBits)
{
	return (num * kBits) / MAX_BUCKET_SIZE;
}

int getBit(uint8_t number, int idx) {
	return (number >> (MAX_BUCKET_SIZE -1) - idx) & 1;
}

void printBucketInBinary(uint8_t bucket) {
	for (int i = 0; i < MAX_BUCKET_SIZE; i++) {
		std::cout << getBit(bucket, i);
	}
	std::cout << std::endl;
}

uint8_t flipBits(uint8_t num, uint8_t kBits) {
	std::cout << "Number before flipping: ";
	printBucketInBinary(num);
	uint8_t reversed = 0;
	for (int i = 0; i < MAX_BUCKET_SIZE; ++i) {
		reversed <<= 1;
		reversed |= num & 1;
		num >>= 1;
	}
	std::cout << "Before shifting " << reversed << std::endl;
	printBucketInBinary(reversed);
	reversed = reversed >> (MAX_BUCKET_SIZE - kBits);
	std::cout << "After shifting " << reversed << std::endl;
	printBucketInBinary(reversed);
	std::cout << std::endl;
	return reversed;
}


uint8_t getNumberOccurrences(const uint8_t num,uint8_t _kBits, uint8_t* bucket) {
	std::cout << std::endl;

	uint8_t count = 0;
	uint8_t idx= firstIndxOfNumber(num, _kBits);
	std::cout << "Index of " << num << ": " << idx << std::endl;

	int currentBucket = bucket[getStartingBucketIndex(num, _kBits)];
	printBucketInBinary(currentBucket);

	for (size_t i = 0; i < _kBits;idx++, i++)
	{
		int currentBit = getBit(currentBucket, idx);
		std::cout << "Curr bit    : " << currentBit << std::endl;
		currentBit <<= i;
		std::cout << "New curr bit: " << currentBit << std::endl;
		count |= currentBit;
		std::cout << "Count       : " << count << std::endl;

		if (idx>sizeof(uint8_t)* 8 - 1)
		{
			std::cout << "Entered a new bucket :)" << std::endl;
			currentBucket++;
			idx = -1;
		}
		std::cout << std::endl;
	}
	uint8_t res = flipBits(count, _kBits);
	std::cout << res << std::endl;
	return res;
}
int setBit(uint8_t number, uint8_t idx, int bit) {

	int mask = 1 << idx;
	return ((number & ~mask) | (bit << idx));
}
//int addNum(const int& num, int _kBits, int* bucket)
//{
//
//}

int main()
{
	// 00010100 | 00000101 | 00010011
	uint8_t* buckets = new uint8_t[8];
	buckets[0] = 20;
	buckets[1] = 5;
	buckets[2] = 19;

	//printBucketInBinary(flipBits(buckets[2], 8));

	//std::cout << "Fliped 20: " << flipBits(buckets[0], 8) << std::endl;
	std::cout << "Fliped 244: " << flipBits(244, 6) << std::endl;
	//std::cout << "Fliped 20: " << flipBits(6, 3) << std::endl;



	/*std::cout << "Index of 0 with kBits=3: " << getStartingBucketIndex(0, 3) << std::endl;
	std::cout << "Index of 1 with kBits=3: " << getStartingBucketIndex(1, 3) << std::endl;
	std::cout << "Index of 5 with kBits=3: " << getStartingBucketIndex(5, 3) << std::endl;
	std::cout << "Index of 2 with kBits=5: " << getStartingBucketIndex(2, 5) << std::endl;
	std::cout << "Index of 6 with kBits=5: " << getStartingBucketIndex(6, 5) << std::endl;
	std::cout << "Index of 8 with kBits=4: " << getStartingBucketIndex(8, 4) << std::endl;



	std::cout << "#ocurrences of 0 with k=3 (exp:0): " << getNumberOccurrences(0, 3, buckets) << std::endl;
	std::cout << "#ocurrences of 1 with k=3 (exp:5): " << getNumberOccurrences(1, 3, buckets) << std::endl;
	std::cout << "#ocurrences of 4 with k=3 (exp:2): " << getNumberOccurrences(4, 3, buckets) << std::endl;
	std::cout << "#ocurrences of 6 with k=3 (exp:2): " << getNumberOccurrences(6, 3, buckets) << std::endl;
	*/
	uint8_t res = getNumberOccurrences(0, 4, buckets);
	std::cout << "#ocurrences of 0 with k=4 (exp:1): "<< static_cast<unsigned int>(res) << std::endl;
	printBucketInBinary(getNumberOccurrences(0, 4, buckets));
	printBucketInBinary(1);
	/*
	std::cout << "#ocurrences of 1 with k=4 (exp:4): " << getNumberOccurrences(1, 4, buckets) << std::endl;
	std::cout << "#ocurrences of 3 with k=4 (exp:5): " << getNumberOccurrences(3, 4, buckets) << std::endl;

	std::cout << "#ocurrences of 2 with k=6 (exp:12): " << getNumberOccurrences(4, 3, buckets) << std::endl;


	*/
}
//bool DynamicSet::contains(unsigned num) const
//{
//	unsigned bucketIndex = getBucketIndex(num);
//	unsigned bitIndex = num % elementsInBucket;
//
//	uint8_t mask = 1 << bitIndex;
//
//	return buckets[bucketIndex] & mask;
//}
//
//void DynamicSet::print() const
//{
//	std::cout << '{';
//	for (int i = 0; i <= N; i++)
//	{
//		if (contains(i))
//			std::cout << i << " ";
//	}
//
//	std::cout << '}' << std::endl;
//}