#include "support.h"
#include "core/ocgapi.h"

namespace ri {

int main(attr_unused const Str_List &args)
{
  RiLogI("Hello Proj Ri!");

  const auto duel = create_duel(0);
  end_duel(duel);

  return 0;
}

} // namespace ri

