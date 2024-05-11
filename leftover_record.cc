// <Gianna Davila>
// <CPSC 121L-15> (e.g. CPSC 121L-01)
// <2/26/24>
// <dgianna@csu.fullerton.edu>
// <dgianna707>
//

#include "leftover_record.h"

// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement
// the member functions declared in the header (leftover_record.h), only
// if you didn't implement them inline within leftover_record.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the LeftLeftoverRecord
// class.
// ===================================================================

// Mutators
void LeftoverRecord::SetDate(const std::string &date) {
  date_ = std::move(date);
}
void LeftoverRecord::SetMeal(const std::string &meal) {
  meal_ = std::move(meal);
}
void LeftoverRecord::SetFoodName(const std::string &food_name) {
  food_name_ = std::move(food_name);
}
void LeftoverRecord::SetQuantityInOz(double qty_in_oz) {
  qty_in_oz_ = std::move(qty_in_oz);
}
void LeftoverRecord::SetLeftoverReason(const std::string &leftover_reason) {
  leftover_reason_ = std::move(leftover_reason);
}
void LeftoverRecord::SetDisposalMechanism(
    const std::string &disposal_mechanism) {
  disposal_mechanism_ = std::move(disposal_mechanism);
}
void LeftoverRecord::SetCost(double cost) { cost_ = std::move(cost); }

// Accessors
std::string LeftoverRecord::GetDate() const { return date_; }
std::string LeftoverRecord::GetMeal() const { return meal_; }
std::string LeftoverRecord::GetFoodName() const { return food_name_; }
double LeftoverRecord::GetQuantityInOz() const { return qty_in_oz_; }
std::string LeftoverRecord::GetLeftoverReason() const {
  return leftover_reason_;
}
std::string LeftoverRecord::GetDisposalMechanism() const {
  return disposal_mechanism_;
}
double LeftoverRecord::GetCost() const { return cost_; }