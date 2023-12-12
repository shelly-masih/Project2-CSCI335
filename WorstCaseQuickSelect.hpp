#include <vector>

  std::vector<int> worstCaseQuickSelect (void){const int size = 20000;
                                              std::vector<int> worstCaseVector(size);
                                              // Generate a sorted vector from 1 to 20000
                                              for (int i = 1; i <= size; ++i) {
                                                worstCaseVector[i - 1] = i;
                                              }
                                              // Shuffle the vector to make it harder for quickselect
                                              std::random_shuffle(worstCaseVector.begin(), worstCaseVector.end());
                                              return worstCaseVector;}



