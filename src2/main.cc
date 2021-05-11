#include <iostream>

#include <gflags/gflags.h>

#include "util.h"
#include "parse/html.h"

DEFINE_string(html_file, "examples/demo.html", "HTML file to load");
DEFINE_string(css_file, "examples/demo.css", "CSS file to load");

int main(int argc, char **argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  const std::string source = io::readFile(FLAGS_html_file);
  const std::string css = io::readFile(FLAGS_css_file);

  html_parser::parseHtml(source);
  return 0;
}