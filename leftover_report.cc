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
  std::unordered_map<std::string, int> mealCount;

  // counting occurences of each meal's cost
  for(LeftoverRecord meal : leftover_records_) {
    mealCount[meal.GetMeal()]++;
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
  std::unordered_map<std::string, int>::iterator::CommonLeftoverCount;
  
  // counting occurence of each leftover
  for(LeftoverRecord record : leftover_records_) {
    CommonLeftoverCount[record.GetFoodName()]++;
  }

  // need to find our max
  int max = 0;
  for(auto& pair : CommonLeftoverCount) {
    if (pair.second > max) {
     max = pair.second; 
    }
  }

  for(auto& pair : MostCommonLeftover) {
    if (pair.second == max) {
      MostCommonLeftover.push_back(pair.second);
    }
  }
  return MostCommonLeftover;

}

std::vector<std::string> LeftoverReport::MostCommonDisposalMechanisms() const {
  std::vector<std::string> MostCommonDisposal;
  std::unordered_map<std::string, int> CommonDisposalCount;
}

std::vector<std::string> LeftoverReport::SuggestLeftoverReductionStrategies()
    const {
  return std::vector<std::string>();
}


