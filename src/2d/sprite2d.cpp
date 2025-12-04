#include "sprite2d.h"

#include "scene.h"

Sprite2D::Sprite2D(uint8_t id, Node ** children, uint16_t children_count, SpriteSheet sprite_sheet, uint8_t frame_count, uint8_t initial_frame)
 : Node2D(id, children, children_count), sprite_sheet(sprite_sheet), frame_count(frame_count), frame(initial_frame) {}


void Sprite2D::update(Scene * scene, Arduboy2 & arduboy, const Sprites & sprites) {
  Transform2D global_transform = this->transform.get_global_transform();

  sprites.drawOverwrite(global_transform.position.x, global_transform.position.y, sprite_sheet, frame);
  frame += 1;
  if (frame >= frame_count) {
    frame = 0;
  }
  
  Node2D::update(scene, arduboy, sprites); // update children next
}

uint8_t Sprite2D::get_width() {
  // TODO make get current frame width.
  return pgm_read_byte(&(sprite_sheet[0]));
}

uint8_t Sprite2D::get_height() {
  // TODO make get current frame height.
  return pgm_read_byte(&(sprite_sheet[1]));
}