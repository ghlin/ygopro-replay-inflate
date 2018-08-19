#include "file-io.h"
#include <cstdio>

namespace ri {

Buffer read_file(const Str &path)
{
  std::FILE *file = std::fopen(path.c_str(), "rb");
  if (!file) {
    std::fprintf(stderr, "[ERROR] failed to open file %s for read\n", path.c_str());
    throw std::runtime_error("failed to open file");
  }

  u8 read_buffer[1024];
  Buffer buffer;

  while (true) {
    const auto bytes_read = std::fread(read_buffer, 1, sizeof read_buffer, file);

    buffer.insert(buffer.end(), read_buffer, read_buffer + bytes_read);

    if (bytes_read < sizeof read_buffer)
      break;
  }

  std::fclose(file);

  return buffer;
}

void write_file(const Str &path, const Buffer &buffer)
{
  std::FILE *file = std::fopen(path.c_str(), "wb");

  if (!file) {
    std::fprintf(stderr, "[ERROR] failed to open file %s for read\n", path.c_str());
    throw std::runtime_error("failed to open file");
  }

  std::fwrite(&buffer.front(), 1, buffer.size(), file);
  std::fclose(file);
}

} // namespace ri

