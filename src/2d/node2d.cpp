#include "node2d.h"
#include "scene.h"

Node2D::Node2D(uint8_t id, Node ** children, uint16_t children_count) : Node(id, children, children_count) {
  transform.node = this;
}

void Node2D::update(Scene * scene, Arduboy2 & arduboy, const Sprites & sprites) {  
  Node::update(scene, arduboy, sprites); // update children next
}