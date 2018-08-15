#include "debug.h"

namespace ri {
namespace details {

Str tracef_text_impl(const Str &header,
                     const Str &content)
{
  constexpr int nice_length = 25;

  auto pad_length  = header.length() < nice_length ? nice_length - header.length() : 0;
  auto nice_header = pad_right(header, pad_length)  + " :";
  auto cont_line   = pad_right("", header.length()) + " |";
  auto lines       = split(content, "\n");

  Str  tracef_text = "";
  bool first_line  = true;

  for (auto &&line : lines)
  {
    tracef_text += first_line ? nice_header : cont_line;

    if (!line.empty())
      tracef_text += " " + line;

    tracef_text += "\n";

    first_line = false;
  }

  return tracef_text;
}


Str shortify_path(const Str &path)
{
  auto last_slash = path.find_last_of("/");

  if (last_slash == path.npos)
    return path;
  else
    return path.substr(last_slash + 1);
}


} // namespace details
} // namespace ri

