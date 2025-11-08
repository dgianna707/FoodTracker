#include "leftover_report.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>

LeftoverReport::LeftoverReport(
    const std::vector<LeftoverRecord>& leftover_records)
    : leftover_records_(leftover_records) {}

std::vector<std::string> LeftoverReport::MostCommonlLeftover() const {
  std::map<std::string, int> common_leftover_map = {};
  for (LeftoverRecord record : leftover_records_) {
    common_leftover_map.insert({record.GetFoodName(), 0});
    common_leftover_map[record.GetFoodName()]++;
  }
  int leftover_count = 0;
  std::vector<std::string> temp_common_leftover;
  for (auto& it : common_leftover_map) {
    if (it.second > leftover_count) {
      leftover_count = it.second;
    }
  }

  for (auto& it : common_leftover_map) {
    if (it.second == leftover_count) {
      temp_common_leftover.push_back(it.first);
    }
  }
  return temp_common_leftover;
}

std::vector<std::string> LeftoverReport::MostCostlyLeftoverProducingMeals()
    const {
  // making vector to keep track of the meals
  std::vector<std::string> MostCostlyLeftOverMeals;
  // creating our map to look for tally counts of costly meals
  std::map<std::string, int> mealCount;

  // counting occurences of each meal's cost
  for (LeftoverRecord meal : leftover_records_) {
    mealCount[meal.GetMeal()] += meal.GetCost();
  }

  // finding our max count
  int max = 0;
  for (auto& pair : mealCount) {
    if (pair.second > max) {
      max = pair.second;
    }
  }
  // finding the meal w/ the max count
  for (auto& pair : mealCount) {
    if (pair.second == max) {
      MostCostlyLeftOverMeals.push_back(pair.first);
    }
  }

  return MostCostlyLeftOverMeals;
}

double LeftoverReport::TotalCostOfLeftover() const {
  double totalCost = 0.0;

  for (LeftoverRecord record : leftover_records_) {
    totalCost += record.GetCost();
  }
  return totalCost;
}

std::vector<std::string> LeftoverReport::MostCommonLeftoverReasons() const {
  std::vector<std::string> MostCommonLeftover;
  std::map<std::string, int> CommonLeftoverCount;

  // counting occurence of each leftover
  for (LeftoverRecord record : leftover_records_) {
    CommonLeftoverCount.insert({record.GetLeftoverReason(), 0});
    CommonLeftoverCount[record.GetLeftoverReason()]++;
  }

  // need to find our max
  int max = 0;
  for (const auto& pair : CommonLeftoverCount) {
    if (pair.second > max) {
      max = pair.second;
    }
  }

  for (const auto& pair : CommonLeftoverCount) {
    if (pair.second == max) {
      MostCommonLeftover.push_back(pair.first);
    }
  }
  return MostCommonLeftover;
}

std::vector<std::string> LeftoverReport::MostCommonDisposalMechanisms() const {
  std::vector<std::string> MostCommonDisposal;
  std::map<std::string, int> CommonDisposalCount;

  // counting occurence of each leftover
  for (LeftoverRecord record : leftover_records_) {
    CommonDisposalCount.insert({record.GetDisposalMechanism(), 0});
    CommonDisposalCount[record.GetDisposalMechanism()]++;
  }

  // need to find our max
  int max = 0;
  for (const auto& pair : CommonDisposalCount) {
    if (pair.second > max) {
      max = pair.second;
    }
  }

  for (const auto& pair : CommonDisposalCount) {
    if (pair.second == max) {
      MostCommonDisposal.push_back(pair.first);
    }
  }
  return MostCommonDisposal;
}

std::vector<std::string> LeftoverReport::SuggestLeftoverReductionStrategies()
    const {
  std::vector<std::string> SuggestedStrategies;
  bool Donate{false};
  bool Buylessfood{false};
  bool Cooksmaller{false};
  bool Recycle{true};

  for (std::string reason : MostCommonLeftoverReasons()) {
    if (reason == "Expired") {
      Donate = true;
      Recycle = false;
    }
    if (reason == "Tastes bad") {
      Buylessfood = true;
    }
    if (reason == "Too much left overs") {
      Buylessfood = true;
      Cooksmaller = true;
    }
  }
  if (Donate) {
    SuggestedStrategies.push_back("Donate before expiration");
  }
  if (Buylessfood) {
    SuggestedStrategies.push_back("Buy less food");
  }
  if (Cooksmaller) {
    SuggestedStrategies.push_back("Cook small servings");
  }
  if (Recycle) {
    SuggestedStrategies.push_back("Recycle left overs");
  }
  if (MostCommonLeftoverReasons().empty()) {
    SuggestedStrategies.clear();
  }
  return SuggestedStrategies;
}
