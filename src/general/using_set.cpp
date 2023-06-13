#include <iostream>
#include <set>

int main() {
  // Create a set of integers
  std::set<int> mySet;

  // Insert elements into the set
  mySet.insert(3);
  mySet.insert(1);
  mySet.insert(5);
  mySet.insert(2);
  mySet.insert(4);

  // Iterate over the set and print its elements
  std::cout << "Set elements: ";
  for (const auto& element : mySet) {
    std::cout << element << " ";
  }
  std::cout << "\n";

  // Check if an element exists in the set
  int target = 2;
  if (mySet.count(target) > 0) {
    std::cout << target << " exists in the set\n";
  } else {
    std::cout << target << " does not exist in the set\n";
  }

  // Remove an element from the set
  int toRemove = 4;
  mySet.erase(toRemove);

  // Print the updated set
  std::cout << "Updated set elements: ";
  for (const auto& element : mySet) {
    std::cout << element << " ";
  }
  std::cout << "\n";

  return 0;
}