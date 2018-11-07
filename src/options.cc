#include "options.h"

namespace ri {

const char *CommandLineOptions::usage = R"(replay-inflate: translate ygopro's yrp file into json format.

usage: replay-inflate [-r] REPLAY_FILE
                      [-p YGOPRO_FOLDER]
                      [-o OUTPUT_FILE]
                      [-h | --help]
                      [-v | --version]

options:
  -h,--help        Show this help text

  -v,--version     Show version

  -r               Specify the yrp file you want to translate,
                   defaults to <YGOPRO>/replay/_LastReplay.yrp

  -p               Specify YGOPRO's installation directory,
                   defaults to . (current dir)

  -o               Set the file name of the output file,
                   leave this empty to print to stdout)";

const char *CommandLineOptions::version = R"(replay-inflate   v0.0.1
ocgcore version  *TODO*)";

enum P_STATE
{
  P_REPLAY_FILE_PATH,
  P_YGOPRO_ROOT_PATH,
  P_OUTPUT_FILE_PATH
};

Opt<CommandLineOptions>
parse_command_line_options(int argc, const char **argv)
{
  P_STATE state = P_REPLAY_FILE_PATH;

  CommandLineOptions options;

  for (int i = 1 /* ignore $0 */; i != argc; ++i) {
    Str arg = argv[i];

    if (arg.empty()) continue;

    if (arg[0] == '-') {
      if (arg == "-r")
        state = P_REPLAY_FILE_PATH;
      else if (arg == "-o")
        state = P_OUTPUT_FILE_PATH;
      else if (arg == "-p")
        state = P_YGOPRO_ROOT_PATH;
      else if (arg == "-h" || arg == "--help")
        options.display_usage_only = true;
      else if (arg == "-v" || arg == "--version")
        options.display_version_only = true;
      else // unknown argument.
        return { };
    } else {
      switch (state) {
      case P_REPLAY_FILE_PATH: options.replay_file_path = arg; break;
      case P_YGOPRO_ROOT_PATH: options.ygopro_root_path = arg; break;
      case P_OUTPUT_FILE_PATH: options.output_file_path = arg; break;
      }

      state = P_REPLAY_FILE_PATH;
    }
  }

  return { options };
}

} // namespace ri
