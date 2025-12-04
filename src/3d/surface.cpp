#include <math.h>
#include <stdint.h>
#include "surface.h"
#include "utility.h"

Vertex::Vertex() {}

void DefaultVertex::set_data(uint16_t offset, int16_t* vertex_data_buffer) {
  offset = offset * sizeof(DefaultVertex);
  position = Vec3I16B(vertex_data_buffer[offset], vertex_data_buffer[offset+1], vertex_data_buffer[offset+2]);
  normal = Vec3I8B(vertex_data_buffer[offset+3], vertex_data_buffer[offset+4], vertex_data_buffer[offset+5]);
  texture_id = static_cast<uint8_t>(vertex_data_buffer[offset+5]);
}

_SurfaceMaterialBase::_SurfaceMaterialBase(SpriteSheet * texel_palette, uint8_t texel_palette_size)
 : texel_palette(texel_palette), texel_palette_size(texel_palette_size) {}

uint8_t _SurfaceMaterialBase::get_texel_size() {
  if (texel_palette != nullptr)
    return texel_palette[0][0];
  return 0;
}


void _SurfaceMaterialBase::vertex_shader(Vertex * vertex, Vec3I16B & out_position, void * out_data) {

}
void _SurfaceMaterialBase::fragment_shader(Vertex * vertex, Arduboy2 & arduboy, const Sprites & sprites) {

}

Surface2D::Surface2D(uint8_t id, Node ** children, uint16_t children_count = 0, _SurfaceMaterialBase * material, Vec2I dimensions, Vec2F origin)
 : Node2D(id, children, children_count), material(material), dimensions(dimensions), origin(origin){}

void Surface2D::update(Scene * scene, Arduboy2 & arduboy, const Sprites & sprites) {
  material->render(vertex_data_buffer, vertex_buffer_size, scene, arduboy, sprites);
  Node2D::update(scene, arduboy, sprites);
}

