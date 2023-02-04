#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class FibLFSR {
	vector<bool> bits;
	static const int TAP_COUNT = 3;
	static constexpr int TAPS[TAP_COUNT] = { 10, 12, 13 };

	static bool isTap(int index) {
		for (int i = 0; i < TAP_COUNT; i++)
			if (TAPS[i] == index)
				return true;
		return false;
	}

	static bool XOR(bool x, bool y) {
		return (x || y) && (!x || !y);
	}
	
	int toDecimal(vector<bool> bits) const;

	public:
		FibLFSR(string seed);

		int step();
		
		int generate(int k);
		
		friend std::ostream& operator<< (std::ostream& out, const FibLFSR& lfsr);
		friend bool operator==(const FibLFSR& lfsr, const std::string& str);
};