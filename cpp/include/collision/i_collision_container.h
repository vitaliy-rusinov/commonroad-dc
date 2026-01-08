#ifndef COLLISION_COLLISION_CONTAINER_H_
#define COLLISION_COLLISION_CONTAINER_H_

#include "collision/collision_object.h"

namespace collision {

/**
 * \brief Interface with queryContainedObjectIndexList method. Used in fcl_collision_requests.h.
 * ShapeGroup implements this interface.
 *
 */

class ICollisionContainer {
 public:
  ICollisionContainer(){};
  virtual int queryContainedObjectIndexList(const CollisionObject *pObj,
                                            std::list<int> &retlist) const = 0;

  virtual ~ICollisionContainer(){

  };
};
}  // namespace collision

#endif /* COLLISION_COLLISION_CONTAINER_H_ */
