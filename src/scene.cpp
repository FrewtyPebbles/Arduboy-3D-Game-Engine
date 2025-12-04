#include "scene.h"
#include "node.h"

Scene::Scene() {}
Scene::Scene(Node * root_node) : root_node(root_node) {}

void Scene::render(Arduboy2 & arduboy, const Sprites & sprites) {
  root_node->update(this, arduboy, sprites);
}