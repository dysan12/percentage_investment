//
// Created by Thomas on 2018-01-18.
//

#ifndef AET_INVESTMENT_H
#define AET_INVESTMENT_H


#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

class Investment {
private:
    std::vector<double> currencyValues;
public:
    explicit Investment(const std::vector<double> &currencyValues);

    const std::vector<double> &getCurrencyValues() const;

public:
    std::vector<double> calculateStaticInvestment(double startingFunds);

    std::vector<double> calculateChangingInvestment(double startingFunds);

    std::vector<double> calculatePartitionedInvestment(double startingFunds);
};


#endif //AET_INVESTMENT_H
