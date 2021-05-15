#include <iostream>

#include <gflags/gflags.h>

#include "util.h"
#include "parse/css.h"
#include "parse/html.h"
#include "render/text.h"
#include "style.h"

DEFINE_string(html_file, "examples/demo.html", "HTML file to load");
DEFINE_string(css_file, "examples/demo.css", "CSS file to load");

int main(int argc, char **argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  const std::string source = io::readFile(FLAGS_html_file);
  const std::string css = io::readFile(FLAGS_css_file);
  std::unique_ptr<dom::Node> root = html_parser::parseHtml(source);
  const std::unique_ptr<css::StyleSheet const> stylesheet = css::parseCss(css);

  text_render::FontRegistry *registry =　text_render::FontRegistry::getInstance();
  std::unique_ptr<style::StyledNode> styled_node = style::styleTree(*root, stylesheet, style::PropertyMap());
  return 0;
}