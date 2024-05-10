// <Gianna Davila>
// <CPSC 121L-15> (e.g. CPSC 121L-01)
// <2/26/24>
// <dgianna@csu.fullerton.edu>
// <dgianna707>
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include<unordered_map>

#include "leftover_report.h"
// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement
// the member functions declared in the header (leftover_report.h), only
// if you didn't implement them inline within leftover_report.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the LeftoverReport
// class.
// ===================================================================

LeftoverReport::LeftoverReport(
    const std::vector<LeftoverRecord>& leftover_records)
     : leftover_records_(leftover_records) {}

std::vector<std::string> LeftoverReport::MostCommonlLeftover() const{
  std::map<std::string, int> common_leftover_map = {};
  for(LeftoverRecord record : leftover_records_){
    common_leftover_map.insert({record.GetFoodName(), 0});
    common_leftover_map[record.GetFoodName()]++;
  }
    int leftover_count = 0; 
    std::vector<std::string> temp_common_leftover;
    for(auto& it : common_leftover_map){
      if(it.second > leftover_count){
        leftover_count = it.second;
      }
    }

    for(auto& it : common_leftover_map){
      if(it.second == leftover_count){
        temp_common_leftover.push_back(it.first);
      }
    }
    return temp_common_leftover;
 }

std::vector<std::string> LeftoverReport::MostCostlyLeftoverProducingMeals() const {
  // making vector to keep track of the meals
  std::vector<std::string> MostCostlyLeftOverMeals;
  // creating our map to look for tally counts of costly meals
  std::map<std::string, int> mealCount;

  // counting occurences of each meal's cost
  for(LeftoverRecord meal : leftover_records_) {
    mealCount[meal.GetMeal()] += meal.GetCost();
  }

  // finding our max count
  int max = 0;
  for(auto& pair : mealCount) {
    if (pair.second > max) {
      max = pair.second;
    }
  }
  // finding the meal w/ the max count 
  for (auto& pair : mealCount) {
    if (pair.second == max){
      MostCostlyLeftOverMeals.push_back(pair.first);
    }
  }

  return MostCostlyLeftOverMeals;

}

double LeftoverReport::TotalCostOfLeftover() const { 
  double totalCost = 0.0; 

  for(LeftoverRecord record : leftover_records_){
    totalCost += record.GetCost(); 
  }
  return totalCost; 
}

std::vector<std::string> LeftoverReport::MostCommonLeftoverReasons() const {
  std::vector<std::string> MostCommonLeftover; 
  std::map<std::string, int> CommonLeftoverCount;
  
  // counting occurence of each leftover
  for(LeftoverRecord record : leftover_records_) {
    CommonLeftoverCount.insert({record.GetLeftoverReason(), 0});
    CommonLeftoverCount[record.GetLeftoverReason()]++;
  }

  // need to find our max
  int max = 0;
  for(const auto& pair : CommonLeftoverCount) {
    if (pair.second > max) {
     max = pair.second; 
    }
  }

  for(const auto& pair : CommonLeftoverCount) {
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
  for(LeftoverRecord record : leftover_records_) {
    CommonDisposalCount.insert({record.GetDisposalMechanism(), 0});
    CommonDisposalCount[record.GetDisposalMechanism()]++;
  }

  // need to find our max
  int max = 0;
  for(const auto& pair : CommonDisposalCount) {
    if (pair.second > max) {
     max = pair.second; 
    }
  }

  for(const auto& pair : CommonDisposalCount) {
    if (pair.second == max) {
      MostCommonDisposal.push_back(pair.first);
    }
  }
  return MostCommonDisposal;
}

std::vector<std::string> LeftoverReport::SuggestLeftoverReductionStrategies()
    const {
        std::vector<std::string> MostCommonLeftover; 
        std::vector<std::string> SuggestedStrategies;
        std::map<std::string, int> DuplicateChecker;
  std::map<std::string, int> CommonLeftoverCount;
  
  // counting occurence of each leftover
  for(LeftoverRecord record : leftover_records_) {
    CommonLeftoverCount.insert({record.GetLeftoverReason(), 0});
    CommonLeftoverCount[record.GetLeftoverReason()]++;
  }

  // need to find our max
  int max = 0;
  for(const auto& pair : CommonLeftoverCount) {
    if (pair.second > max) {
     max = pair.second; 
    }
  }

  for(const auto& pair : CommonLeftoverCount) {
    if (pair.second == max) {
      MostCommonLeftover.push_back(pair.first);
    }
  }

  for(const auto& it : MostCommonLeftover) {
    if(it == "Expired") {
      DuplicateChecker.insert({"Donate before expiration", 0});
      //SuggestedStrategies.push_back("Donate before expiration");
    }
    if(it == "Tastes bad") {
      DuplicateChecker.insert({"Buy less food", 0});
     // SuggestedStrategies.push_back("Buy less food");
    }
    if(it == "Too much left overs") {
      DuplicateChecker.insert({"Buy less food", 0});
      DuplicateChecker.insert({"Cook small servings", 0});
      //SuggestedStrategies.push_back("Buy less food");
      //SuggestedStrategies.push_back("Cook small servings");
    }
    if(it != "Expired") {
      DuplicateChecker.insert({"Recycle left overs", 0});
      //SuggestedStrategies.push_back("Recycle left overs");
    }
  }

  for(const auto& pair : DuplicateChecker) {
      SuggestedStrategies.push_back(pair.first);
  }
  
  if (SuggestedStrategies.size() == 4){
    SuggestedStrategies.pop_back();
    SuggestedStrategies.pop_back();
    SuggestedStrategies.push_back("Recycle left overs");
  }


  return SuggestedStrategies;

}


