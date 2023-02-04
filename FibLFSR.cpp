#include "FibLFSR.h"
	
int FibLFSR::toDecimal(vector<bool> bits) const {
	int sum = 0;
	for (int i = bits.size()-1; i >= 0; i--) {
		if (bits.at(i)) {
			sum += pow(2, bits.size()-i-1);
		}
	}
	return sum;
}

FibLFSR::FibLFSR(string seed) { // constructor to create LFSR with the given initial seed
	for (int i = 0; i < seed.size(); i++) {
		string s = "";
		s += seed.at(i);
		bits.push_back(stoi(s));
	}
}

int FibLFSR::step() { // simulate one step and return the new bit as 0 or 1
	bool ans = bits[0];
	for (int i = 1; i < bits.size(); i++) { //taps
			int currReversed = bits.size()-1-i;
			if (isTap(currReversed)) {
				ans = XOR(ans, bits[i]);
			}
	}
	for (int i = 1; i < bits.size(); i++) { //shift
		bits.at(i-1) = bits.at(i);
	}
	bits[bits.size()-1] = ans;
	return ans;
}
		
int FibLFSR::generate(int k) { // simulate k steps and return 
	vector<bool> tmp;
	for (int i = 0; i < k; i++)		     // k-bit integer
		tmp.push_back(step());
	return toDecimal(tmp);
}

std::ostream& operator<< (std::ostream& out, const FibLFSR& lfsr)
{
	for (int i = 0; i < lfsr.bits.size(); i++)
		out << lfsr.bits.at(i);
	return out;
}

bool operator==(const FibLFSR& lfsr, const std::string& str) {
	string s = "";
	for (int i = 0; i < lfsr.bits.size(); i++)
		s += lfsr.bits.at(i) ? "1" : "0";
	return s == str;
}