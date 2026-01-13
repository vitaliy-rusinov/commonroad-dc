#include "collision/narrowphase/detail/aabb.h"

#include "collision/solvers/sat2d/aabb_sat2d.h"
#include "collision/narrowphase/rectangle_aabb.h"

namespace collision {

/*!
 \brief Returns if the AABB collides with another AABB

 \param[in] other - other AABB

*/

AABB::AABB(const RectangleAABB& aabb_rect) {
   x_min = aabb_rect.min()[0];
   y_min = aabb_rect.min()[1];
   x_max = aabb_rect.max()[0];
   y_max = aabb_rect.max()[1];
};

bool AABB::collides(const AABB& other) {
  collision::detail::AABB_SAT2D a(*this);
  collision::detail::AABB_SAT2D b(*this);
  return a.collides(b);
};
}  // namespace collision
