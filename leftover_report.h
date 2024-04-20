#ifndef LEFTOVER_REPORT_H_
#define LEFTOVER_REPORT_H_

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
#include "leftover_record.h"
// ======================= YOUR CODE HERE =======================
// Write the LeftoverReport class here. Refer to your class design for the
// member variables, constructors, and member functions needed.
//
// Note: mark functions that do not modify the member variables
// as const, by writing `const` after the parameter list.
// Pass objects by const reference when appropriate.
// Remember that std::string is an object!
// ===============================================================
class LeftoverReport {
 private:
  const std::vector<LeftoverRecord> &leftover_records_;
  std::vector<std::string> most_common_leftover_;
  std::vector<std::string> most_costly_leftover_producing_meals_;
  double total_cost_of_leftovers_;
  std::vector<std::string> most_common_leftover_reasons_;
  std::vector<std::string> most_common_disposal_mechanisms_;
  std::vector<std::string> suggested_strategies_to_reduce_leftovers_;

 public:
  /// @brief 
  /// @param leftover_records 
  LeftoverReport(const std::vector<LeftoverRecord> &leftover_records);
  std::vector<std::string> MostCommonlLeftover() const;
  std::vector<std::string> MostCostlyLeftoverProducingMeals() const;
  double TotalCostOfLeftover() const;
  std::vector<std::string> MostCommonLeftoverReasons() const;
  std::vector<std::string> MostCommonDisposalMechanisms() const;
  /// @brief 
  /// @return 
  std::vector<std::string> SuggestLeftoverReductionStrategies() const;
};

#endif
