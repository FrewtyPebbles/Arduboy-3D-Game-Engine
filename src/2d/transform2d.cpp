#include "transform2d.h"
#include "node2d.h"
#include "utility.h"

Transform2D::Transform2D(Node2D * node)
  : node(node) {}
Transform2D::Transform2D(Node2D * node, Vec2I position, Vec2I scale, int16_t rotation)
  : node(node), position(position), scale(scale), rotation(Utility::wrap_euler_angle(rotation)) {}

Transform2D Transform2D::get_global_transform() {
  Node2D * parent = this->node;
  Transform2D global_transform = Transform2D(this->node, position, scale, rotation);
  while ((parent = (Node2D *)parent->get_parent()) != nullptr) {
    global_transform.scale *= parent->transform.scale;
    global_transform.rotate(parent->transform.get_rotation());

    //position
    Vec2I scaled_offset = global_transform.position * parent->transform.scale;
    Vec2I rotated_offset = scaled_offset.rotate(parent->transform.rotation);
    global_transform.position = parent->transform.position + rotated_offset;
  }
  return global_transform;
}

void Transform2D::rotate(int16_t angle_rad) {
  this->rotation += Utility::wrap_euler_angle(angle_rad);
}

void Transform2D::set_rotation(int16_t angle_rad) {
  this->rotation = Utility::wrap_euler_angle(angle_rad);
}

uint16_t Transform2D::get_rotation() {
  return this->rotation;
}