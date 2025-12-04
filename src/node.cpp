#include "node.h"

#include "scene.h"


Node::Node(uint8_t id, Node ** children = nullptr, uint16_t children_count = 0) : id(id), children(children), children_count(children_count) {
  for (uint16_t i = 0; i < children_count; ++i) {
    children[i] = nullptr;
  }
  parent = nullptr;
}

bool Node::insert_child(Node * child) {
  for (size_t i = 0; i < children_count; ++i) {
    if (children[i] == nullptr) {
      child->parent = this;
      children[i] = child;
      return true;
    }
  }
  return false;
}
  
bool Node::remove_child(Node * child) {
  for (size_t i = 0; i < children_count; ++i) {
    if (children[i] != nullptr && children[i]->id == child->id) {
      child->parent = nullptr;
      children[i] = nullptr;
      return true;
    }
  }
  return false;
}

Node * Node::get_parent() {
  return parent;
}

void Node::update(Scene *scene, Arduboy2 & arduboy, const Sprites & sprites) {
  
  for (size_t i = 0; i < children_count; ++i) {
    if (children[i] != nullptr) {
      children[i]->update(scene, arduboy, sprites);
    }
  }
}
