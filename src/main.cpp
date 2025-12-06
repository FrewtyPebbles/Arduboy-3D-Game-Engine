#include <Arduboy2.h>
#include <Sprites.h>
#include "bitmaps.h"
#include "scene.h"
#include "node2d.h"
#include "sprite2d.h"
#include "vec2.h"
#include "surface.h"
#include "fraction.h"
#include "fraction_utilities.h"

Arduboy2 arduboy;
Sprites sprites;

Scene main_scene = Scene();

Node * root_node_children[1];
Node2D root_node = Node2D(0, root_node_children, 1);

Node * game_root_children[3];
Node2D game_root = Node2D(1, game_root_children, 3);

Sprite2D cursor = Sprite2D(2, nullptr, 0, BitMaps::shades::size4x4::p25, 1, 0);
Sprite2D block = Sprite2D(3, nullptr, 0, BitMaps::shades::size4x4::p75, 1, 0);

// SURFACE

SpriteSheet texel_palette[] = {
  BitMaps::shades::size4x4::p0,
  BitMaps::shades::size4x4::p25,
  BitMaps::shades::size4x4::p50,
  BitMaps::shades::size4x4::p75,
  BitMaps::shades::size4x4::p100
};
SurfaceMaterial<> surface_mat = SurfaceMaterial<>(texel_palette, 5);
Surface2D surface = Surface2D(4, nullptr, 0, &surface_mat, Vec2I(5,5));

// game values
F64B direction(0);

void setup() {
  // put your setup code here, to run once:
  
  arduboy.begin();
  arduboy.setFrameRate(10);

  Serial.begin(9600);
    
  main_scene.root_node = &root_node;
  root_node.insert_child(&game_root);
  game_root.insert_child(&cursor);
  game_root.insert_child(&block);
  game_root.insert_child(&surface);
  block.transform.position.x = WIDTH / 2;
  block.transform.position.y = HEIGHT;

}

void update();

void loop() {
  if (!(arduboy.nextFrame()))
    return;
  
  arduboy.clear();
  update();
  main_scene.render(arduboy, sprites);

  arduboy.display();
}
Vec2I dir(1, 0);

void update() {
  int8_t vel = 0;
  
  if (direction <= F64B(-1, 1000)) {
    direction += F64B(1, 1000);
  }
  if (direction >= F64B(1, 1000)) {
    direction -= F64B(1, 1000);
  }
  if (arduboy.pressed(UP_BUTTON)) {
    vel = -1;
  }
  if (arduboy.pressed(DOWN_BUTTON)) {
    vel = 1;
  }
  if (arduboy.pressed(LEFT_BUTTON)) {
    direction += F64B(2, 1000);
  }
  if (arduboy.pressed(RIGHT_BUTTON)) {
    direction -= F64B(2, 1000);
  }
  direction = Utility::wrap_euler_angle_radians(direction);

  char buf[30];
  direction.to_string(buf);
  Serial.println(buf);

  dir = dir.rotate(direction);
  
  block.transform.position.y -= 1;
  if (block.transform.position.y < -(int8_t)block.get_height()) {
    block.transform.position.y = HEIGHT;
  }

  cursor.transform.position += dir * vel;
}
