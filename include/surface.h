#include <stdint.h>
#pragma once
// This is a surface on which shades can be rendered onto it from the bitmaps.h file
#include "node2d.h"
#include "vec3.h"
#include "bitmaps.h"


class Vertex {
public:
  Vertex();
  virtual void set_data(uint16_t offset, int16_t* vertex_data_buffer) = 0;
};

class DefaultVertex : public Vertex {
public:
  using Vertex::Vertex;
  void set_data(uint16_t offset, int16_t* vertex_data_buffer) override;
  Vec3I16B position;
  Vec3I8B normal;
  uint8_t texture_id;
};

// this is the class that holds the render data and abstract functionality.
class _SurfaceMaterialBase {
public:
  _SurfaceMaterialBase(SpriteSheet * texel_palette = nullptr, uint8_t texel_palette_size = 0);
  
  //texel_palette holds the different texel pallette values to choose from.
  //The index of each texel is its id. The frame buffer will hold a matrix of ids which will then be rendered to the raster surface, replacing each id with a texel.
  SpriteSheet * texel_palette = nullptr;

  // texel_palette_size is the number of textures in the palette.
  uint8_t texel_palette_size = 0;

  //the width and height of every texel are the same.
  uint8_t get_texel_size();

  // renders the material to the screen.
  virtual void render(int16_t* vertex_data_buffer, uint16_t vertex_buffer_size, Scene * scene, Arduboy2 & arduboy, const Sprites & sprites) = 0;

protected:


  // out_data is casted to a struct representing the shape of the data sent to the fragment shader
  // vertex is casted to a derived type containint the public attributes.
  virtual void vertex_shader(Vertex * vertex, Vec3I16B & out_position, void * out_data);
  // this is where the draw commands/functions are called
  virtual void fragment_shader(Vertex * vertex, Arduboy2 & arduboy, const Sprites & sprites);
};

template<typename VertexType = DefaultVertex>
class SurfaceMaterial : public _SurfaceMaterialBase {
  using _SurfaceMaterialBase::_SurfaceMaterialBase;
  void render(int16_t* vertex_data_buffer, uint16_t vertex_buffer_size, Scene * scene, Arduboy2 & arduboy, const Sprites & sprites) override;
};

template<typename VertexType>
void SurfaceMaterial<VertexType>::render(int16_t* vertex_data_buffer, uint16_t vertex_buffer_size, Scene * scene, Arduboy2 & arduboy, const Sprites & sprites) {
  VertexType vertex;
  Vec3I16B out_positions_buffer[3];
  for (uint8_t i = 0; i < static_cast<uint8_t>(vertex_buffer_size / sizeof(VertexType)); ++i) {
    vertex.set_data(i, vertex_data_buffer);
    vertex_shader(&vertex, out_positions_buffer[i % 3], nullptr);
    if (i % 3 == 2) { // is the end of a triangle.
      // render the triangle
      Vec3I16B v1 = out_positions_buffer[i-2];
      Vec3I16B v2 = out_positions_buffer[i-1];
      Vec3I16B v3 = out_positions_buffer[i];
      uint16_t max_x = max(max(v1.x, v2.x), v3.x);
      uint16_t max_y = max(max(v1.y, v2.y), v3.y);
      for (uint16_t x = 0; x < max_x; ++x) {
        for (uint16_t y = 0; y < max_y; ++y) {
          // some logic to check if x and y are within the polygon bounds;
          fragment_shader(&vertex, arduboy, sprites);
        }
      }
    }
  }
}

// This is the class that can be placed into the scene.
class Surface2D : public Node2D {
public:
  Surface2D(uint8_t id, Node ** children = nullptr, uint16_t children_count = 0, _SurfaceMaterialBase * material = nullptr, Vec2I dimensions = Vec2I(0, 0), Vec2F origin = Vec2F(0.5, 0.5));
  
  Vec2F origin;
  
  Vec2I dimensions;

  _SurfaceMaterialBase * material;

  int16_t* vertex_data_buffer;
  uint16_t vertex_buffer_size;

  void update(Scene * scene, Arduboy2 & arduboy, const Sprites & sprites) override;
};
