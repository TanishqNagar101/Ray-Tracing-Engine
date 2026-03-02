#pragma once

#include "vec3.h"
#include <iosfwd>

using color = vec3;
void write_colour(std::ostream&, const vec3&);
