#ifndef LEFTOVER_REPORT_H_
#define LEFTOVER_REPORT_H_

// <Gianna Davila>
// <CPSC 121L-15> (e.g. CPSC 121L-01)
// <2/26/24>
// <dgianna@csu.fullerton.edu>
// <dgianna707>
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>

#include "leftover_record.h"

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
  LeftoverReport(const std::vector<LeftoverRecord> &leftover_records);
  std::vector<std::string> MostCommonlLeftover() const;
  std::vector<std::string> MostCostlyLeftoverProducingMeals() const;
  double TotalCostOfLeftover() const;
  std::vector<std::string> MostCommonLeftoverReasons() const;
  std::vector<std::string> MostCommonDisposalMechanisms() const;
  std::vector<std::string> SuggestLeftoverReductionStrategies() const;
  bool operator<(const LeftoverReport &other) const;
};

#endif
