#pragma once
#include "prelude.h"

namespace ri {

struct CommandLineOptions
{
  Opt<Str> replay_file_path;
  Opt<Str> ygopro_root_path;
  Opt<Str> output_file_path;
  bool     display_usage_only   = false;
  bool     display_version_only = false;

  static const char *usage;
  static const char *version;
};

Opt<CommandLineOptions>
parse_command_line_options(int argc, const char **argv);

} // namespace ri
