//
// Created by Thomas on 2018-01-18.
//

#include "Investment.h"

Investment::Investment(const std::vector<double> &currencyValues) : currencyValues(currencyValues) {}

const std::vector<double> &Investment::getCurrencyValues() const {
    return currencyValues;
}

std::vector<double> Investment::calculateStaticInvestment(double startingFunds) {
    unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> uniform_dist(1.0, 4.0);
    double percentage =
            round(uniform_dist(generator) * 10) / 10;    /* zaokraglenie do 1 miejsca po przecinku */

    std::vector<double> funds = {startingFunds};

    for (auto &value : getCurrencyValues()) {
        funds.push_back(round((((funds.back() / value) * ((percentage + 100) / 100)) * value) * 1000) / 1000);
    }

    return funds;
}

std::vector<double> Investment::calculateChangingInvestment(double startingFunds) {
    double percentage = 2.5;

    std::vector<double> funds = {startingFunds};
    double previousValue = this->getCurrencyValues().front();

    for (auto &value : getCurrencyValues()) {
        if (previousValue > value) {
            if (percentage >= 4) {
                funds.push_back(round((((funds.back() / value) * ((percentage + 100) / 100)) * value) * 1000) / 1000);
            } else {
                percentage += 0.3;
                funds.push_back(round((((funds.back() / value) * ((percentage + 100) / 100)) * value) * 1000) / 1000);
            }
        } else if (previousValue < value) {
            if (percentage <= 1) {
                funds.push_back(round((((funds.back() / value) * ((percentage + 100) / 100)) * value) * 1000) / 1000);
            } else {
                percentage -= 0.3;
                funds.push_back(round((((funds.back() / value) * ((percentage + 100) / 100)) * value) * 1000) / 1000);
            }
        } else { /* Rowne */
            funds.push_back(round((((funds.back() / value) * ((percentage + 100) / 100)) * value) * 1000) / 1000);
        }
    };

    return funds;
}

std::vector<double> Investment::calculatePartitionedInvestment(double startingFunds) {
    unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine generator(seed);
    double percentage = 0;

    std::vector<double> funds = {startingFunds};

    for (auto &value : this->getCurrencyValues()) {
        std::uniform_real_distribution<double> uniform_dist(1.0, 4.0);
        percentage = round(uniform_dist(generator) * 10) / 10;

        funds.push_back(round((((funds.back() / value) * ((percentage + 100) / 100)) * value) * 1000) / 1000);
    };

    return funds;
}