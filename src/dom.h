#ifndef DOM_H
#define DOM_H

#include <iostream>
#include <map>
#include <vector>

#include "constants.h"

typedef std::map<std::string, std::string> Attrs;

namespace dom {

/*
 * Represents a node in the DOM tree. Can be either TextNode or ElementNode.
 */
class Node {
 private:
  std::vector<std::unique_ptr<Node>> children_;

 public:
  // Constructors
  Node(){};
  Node(std::vector<std::unique_ptr<Node>> children) {
    children_ = std::move(children);
  };
  // Delete copy constructor
  Node(const Node &node) = delete;
  Node &operator=(const Node &node) = delete;

  // Getters
  std::vector<std::reference_wrapper<Node>> get_children() const {
    std::vector<std::reference_wrapper<Node>> children;
    for (auto const &child : children_) {
      children.push_back(*child);
    }
    return children;
  };

  virtual std::string toLogStr() const { return ""; };
};

/*
 * Represents raw text.
 */
class TextNode : public Node {
  std::string text_;

 public:
  // Constructors
  // Delete copy constructor
  TextNode(const TextNode &node) = delete;
  TextNode(const std::string &text) { text_ = text; }
  TextNode(const std::string &text, std::vector<std::unique_ptr<Node>> children)
      : Node(std::move(children)) {
    text_ = text;
  }
  // Getters
  std::string get_text() const { return text_; }

  std::string toLogStr() const;
};

/*
 * Represents any non-text node of the DOM.
 */
class ElementNode : public Node {
 private:
  std::string tag_name_;
  std::map<std::string, std::string> attrs_;

 public:
  // Constructors
  ElementNode(const ElementNode &node) = delete;

  ElementNode(const std::string &tag_name, Attrs attrs) {
    tag_name_ = tag_name;
    attrs_ = attrs;
  };
  ElementNode(const std::string &tag_name, Attrs attrs,
              std::vector<std::unique_ptr<Node>> children)
      : Node(std::move(children)) {
    tag_name_ = tag_name;
    attrs_ = attrs;
  };

  // Getters
  std::string get_id() const;
  std::string get_tag() const { return tag_name_; };
  std::vector<std::string> get_classes() const;

  // Returns whether this node is one that is displayed to the screen,
  // or something like <head>, <meta> that are used for metadata only
  bool isDisplayable() const;
  // Return the provided attribute. Returns the provided default_value
  // if the attribute is not present.
  std::string getAttr(
      const std::string &property,
      const std::string &default_value = constants::DEFAULT) const;
  std::string toLogStr() const;
};

}  // namespace dom

#endif
