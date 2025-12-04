#pragma once

#include <Arduboy2.h>
#include <Sprites.h>

class Node;

class Scene {
public:
  Scene();
  Scene(Node * root);
  void render(Arduboy2 & arduboy, const Sprites & sprites);
  Node *root_node;
};