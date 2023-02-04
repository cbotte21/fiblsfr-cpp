#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <boost/test/unit_test.hpp>
#include <string>
#include <vector>
#include <utility>
using namespace std;

const std::string example_param = "1011011000110110";

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

    FibLFSR l("1011011000110110");
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);

    FibLFSR l2("1011011000110110");
    BOOST_REQUIRE(l2.generate(9) == 51);
}

//Test step values based off spec sheet
BOOST_AUTO_TEST_CASE(step) {
    FibLFSR flfsr(example_param);

    vector<pair<bool, string>> spec;
    spec.push_back(make_pair(0, string("0110110001101100")));
    spec.push_back(make_pair(0, string("1101100011011000")));
    spec.push_back(make_pair(0, string("1011000110110000")));
    spec.push_back(make_pair(1, string("0110001101100001")));
    spec.push_back(make_pair(1, string("1100011011000011")));
    spec.push_back(make_pair(0, string("1000110110000110")));
    spec.push_back(make_pair(0, "0001101100001100"));
    spec.push_back(make_pair(1, "0011011000011001"));
    spec.push_back(make_pair(1, "0110110000110011"));
    spec.push_back(make_pair(0, "1101100001100110"));

    for (int i = 0; i < spec.size(); i++) {
        BOOST_CHECK_EQUAL(flfsr.step(), spec[i].first);
        BOOST_CHECK_EQUAL(flfsr, spec[i].second);
    }
}

//Test generated values based off spec sheet
BOOST_AUTO_TEST_CASE(generator) {
    FibLFSR flfsr(example_param);

    vector<pair<int, string>> spec;
    spec.push_back(make_pair(3, "1100011011000011"));
    spec.push_back(make_pair(6, "1101100001100110"));
    spec.push_back(make_pair(14, "0000110011001110"));
    spec.push_back(make_pair(24, "1001100111011000"));
    spec.push_back(make_pair(1, "0011101100000001"));
    spec.push_back(make_pair(13, "0110000000101101"));
    spec.push_back(make_pair(28, "0000010110111100"));


    for (int i = 0; i < spec.size(); i++) {
        BOOST_CHECK_EQUAL(flfsr.generate(5), spec[i].first);
        BOOST_CHECK_EQUAL(flfsr, spec[i].second);
    }
};