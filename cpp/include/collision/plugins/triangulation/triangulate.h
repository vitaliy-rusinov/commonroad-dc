#pragma once

#include "collision/application_settings.h"

#if ENABLE_TRIANGULATION
#include "collision/narrowphase/triangle.h"

namespace collision {
namespace triangulation {

enum TriangulationMethod {
	TRIANGULATION_GPC = 0, // use General Polygon Clipper Library for triangulation
	TRIANGULATION_TRIANGLE, // use non-free Triangle library for triangulation
	TRIANGULATION_CGAL // use non-free CGAL library for triangulation
};

class TriangulationQuality {
 public:

  TriangulationQuality(double mesh_quality_) {
    mesh_quality = mesh_quality_;
  }

  bool bb_only = false; // triangulate only the AABB box of the Polygon (create 2 triangles)
  bool use_quality = true; // use the mesh_quality parameter for triangulation
  double mesh_quality = 20; // required quality for the triangle mesh
  	  	  	  	  	  	  	// (parameter used for the non-free CGAL and Triangle libraries)
};

int do_triangulate_aabb(
    std::vector<Eigen::Vector2d> vertices,
    std::vector<collision::TriangleConstPtr> &triangles_out);

int do_triangulate(std::vector<Eigen::Vector2d> vertices,
                   std::vector<collision::TriangleConstPtr> &triangles_out, TriangulationMethod method);

int do_triangulateQuality(
    std::vector<Eigen::Vector2d> vertices,
    std::vector<collision::TriangleConstPtr> &triangles_out, TriangulationMethod method,
    TriangulationQuality qual);
}  // namespace triangulation
}  // namespace collision
#endif
