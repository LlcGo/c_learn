#include <kernel.h>
#include <klib.h>

/// @brief 
/// @return 
int main() {
  os->init();
  mpe_init(os->run);
  return 1;
}
