/********************************************************************************
* ReactPhysics3D physics library, http://www.reactphysics3d.com                 *
* Copyright (c) 2010-2016 Daniel Chappuis                                       *
*********************************************************************************
*                                                                               *
* This software is provided 'as-is', without any express or implied warranty.   *
* In no event will the authors be held liable for any damages arising from the  *
* use of this software.                                                         *
*                                                                               *
* Permission is granted to anyone to use this software for any purpose,         *
* including commercial applications, and to alter it and redistribute it        *
* freely, subject to the following restrictions:                                *
*                                                                               *
* 1. The origin of this software must not be misrepresented; you must not claim *
*    that you wrote the original software. If you use this software in a        *
*    product, an acknowledgment in the product documentation would be           *
*    appreciated but is not required.                                           *
*                                                                               *
* 2. Altered source versions must be plainly marked as such, and must not be    *
*    misrepresented as being the original software.                             *
*                                                                               *
* 3. This notice may not be removed or altered from any source distribution.    *
*                                                                               *
********************************************************************************/

// Libraries
#include "DefaultCollisionDispatch.h"
#include "collision/shapes/CollisionShape.h"

using namespace reactphysics3d;

// Constructor
DefaultCollisionDispatch::DefaultCollisionDispatch() {

}

// Destructor
DefaultCollisionDispatch::~DefaultCollisionDispatch() {

}

/// Initialize the collision dispatch configuration
void DefaultCollisionDispatch::init(CollisionDetection* collisionDetection,
                                    MemoryAllocator* memoryAllocator) {

    // Initialize the collision algorithms
    mSphereVsSphereAlgorithm.init(collisionDetection, memoryAllocator);
    mGJKAlgorithm.init(collisionDetection, memoryAllocator);
    mConcaveVsConvexAlgorithm.init(collisionDetection, memoryAllocator);
}

// Select and return the narrow-phase collision detection algorithm to
// use between two types of collision shapes.
NarrowPhaseAlgorithm* DefaultCollisionDispatch::selectAlgorithm(int type1, int type2) {

    CollisionShapeType shape1Type = static_cast<CollisionShapeType>(type1);
    CollisionShapeType shape2Type = static_cast<CollisionShapeType>(type2);

    // Sphere vs Sphere algorithm
    if (shape1Type == SPHERE && shape2Type == SPHERE) {
        return &mSphereVsSphereAlgorithm;
    }
    // Concave vs Convex algorithm
    else if ((!CollisionShape::isConvex(shape1Type) && CollisionShape::isConvex(shape2Type)) ||
             (!CollisionShape::isConvex(shape2Type) && CollisionShape::isConvex(shape1Type))) {
        return &mConcaveVsConvexAlgorithm;
    }
    // Convex vs Convex algorithm (GJK algorithm)
    else if (CollisionShape::isConvex(shape1Type) && CollisionShape::isConvex(shape2Type)) {
        return &mGJKAlgorithm;
    }
    else {
        return NULL;
    }
}
