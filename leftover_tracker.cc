// <Gianna Davila>
// <CPSC 121L-15> (e.g. CPSC 121L-01)
// <2/26/24>
// <dgianna@csu.fullerton.edu>
// <dgianna707>
//
#include <iostream>
#include <vector>
#include "leftover_record.h"
#include "leftover_tracker.h"

// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement
// the member functions declared in the header (leftover_tracker.h), only
// if you didn't implement them inline within leftover_tracker.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the LeftoverTracker
// class.
// ===================================================================

bool LeftoverTracker::AddRecord(const LeftoverRecord &record) {
    // Check if the record already exists in a vector
    for (const auto &existing_record : leftover_records_) {
        if (existing_record == record){
             return false;} // Duplicate record found, return false
        }
    // If not a duplicate, adds to vector
    leftover_records_.push_back(record);
    return true;
}

const std::vector<LeftoverRecord>& LeftoverTracker::GetRecords() const {
    return leftover_records_;
}

LeftoverReport LeftoverTracker::GetLeftoverReport() const {
    return LeftoverReport(leftover_records_);
}


