#include <iostream>

bool ok(int x) {
  if (x < 6400)
    return false;
  else 
    return true;
}

auto f(int x) {
    return 8*x - x*x;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int z = 10000;
  int x = -1;

  for (int b = z; b >= 1; b /= 2) {
    while (!ok(x + b)) 
      x += b;
  }

  int k = x + 1;
  std::cout << k << std::endl;


  z = 10000;
  x = -1;
  for (int b = z; b >= 1; b /= 2) {
    while (f(x + b) < f(x + b + 1)) 
      x += b;
  }
  k = x + 1;
  std::cout << k;

  return 0;
}
