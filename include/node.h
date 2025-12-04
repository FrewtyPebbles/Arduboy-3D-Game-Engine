#include <stdint.h>
#pragma once

#include <Arduboy2.h>

class Scene;

class Node {
public:
  Node(uint8_t id, Node ** children = nullptr, uint16_t children_count = 0);
  uint16_t id;

  virtual void update(Scene * scene, Arduboy2 & arduboy, const Sprites & sprites);

  Node * get_parent();

  bool insert_child(Node * child);
  
  bool remove_child(Node * child);
  
  Node ** children;
  uint16_t children_count = 0;

private:
  Node * parent = nullptr;
};