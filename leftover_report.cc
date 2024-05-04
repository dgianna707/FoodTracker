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

std::vector<std::string> LeftoverReport::MostCommonlLeftover() {
  std::map<std::string, int> common_leftover_map = {};
  for(LeftoverRecord record : leftover_records_){
    common_leftover_map.insert({record.GetFoodName(), 0});
    common_leftover_map[record.GetFoodName()]++;

    int leftover_count = 0; 
    for(auto& it : common_leftover_map){
      if(it.second > leftover_count){
        leftover_count = it.second;
      }
    }

    for(auto& it : common_leftover_map){
      if(it.second == common_leftover_map){
        most_common_leftover_.pushback(it.first);
      }
    }
    return most_common_leftover_;
  }
}

std::vector<std::string> LeftoverReport::MostCostlyLeftoverProducingMeals()
    const {
  return std::vector<std::string>();
}

double LeftoverReport::TotalCostOfLeftover() const { return total_cost_of_leftovers_; }

std::vector<std::string> LeftoverReport::MostCommonLeftoverReasons() const {
  return std::vector<std::string>();
}

std::vector<std::string> LeftoverReport::MostCommonDisposalMechanisms() const {
  return std::vector<std::string>();
}

std::vector<std::string> LeftoverReport::SuggestLeftoverReductionStrategies()
    const {
  return std::vector<std::string>();
}
