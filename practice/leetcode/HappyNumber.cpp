#include <map>
#include <set>
 
bool happy(int number) {
/*this is static map to cache result of previous calculation*/
  static std::map<int, bool> cache;
 
  std::set<int> cycle;
  while (number != 1 && !cycle.count(number)) {
    if (cache.count(number)) {
      number = cache[number] ? 1 : 0;
      break;
    }
    cycle.insert(number);
    int newnumber = 0;
    while (number > 0) {
      int digit = number % 10;
      newnumber += digit * digit;
      number /= 10;
    }
    number = newnumber;
  }
  /*to break the loop above , we have 
    1, number == 1 that this is happy number 
    2. cyce.count(number>1) that we cencouter loop this is not happy number
  */
  bool happiness = number == 1;
	/*update all number that we encounter in the this round to ther correct      result */
  for (std::set<int>::const_iterator it = cycle.begin();
       it != cycle.end(); it++)
    cache[*it] = happiness;
  return happiness;
}
 
#include <iostream>
 
int main() {
  for (int i = 1; i < 50; i++)
    if (happy(i))
      std::cout << i << std::endl;
  return 0;
}
