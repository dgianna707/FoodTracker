#ifndef LEFTOVER_TRACKER_H_
#define LEFTOVER_TRACKER_H_
#include <iostream>
#include <vector>

#include "leftover_record.h"
#include "leftover_report.h"

// <Gianna Davila>
// <CPSC 121L-15> (e.g. CPSC 121L-01)
// <2/26/24>
// <dgianna@csu.fullerton.edu>
// <dgianna707>
//

class LeftoverTracker {
 private:
  std::vector<LeftoverRecord> leftover_records_;

 public:
  bool AddRecord(const LeftoverRecord &record);
  bool DeleteRecord(const LeftoverRecord &record);
  const std::vector<LeftoverRecord> &GetRecords() const;
  LeftoverReport GetLeftoverReport() const;
};

#endif
