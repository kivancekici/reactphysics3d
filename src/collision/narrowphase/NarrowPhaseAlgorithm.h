/********************************************************************************
* ReactPhysics3D physics library, http://code.google.com/p/reactphysics3d/      *
* Copyright (c) 2010-2012 Daniel Chappuis                                       *
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

#ifndef NARROW_PHASE_ALGORITHM_H
#define NARROW_PHASE_ALGORITHM_H

// Libraries
#include "../../body/Body.h"
#include "../ContactInfo.h"
#include "../CollisionDetection.h"

// Namespace ReactPhysics3D
namespace reactphysics3d {

/*  -------------------------------------------------------------------
    Class NarrowPhaseAlgorithm :
        This class is an abstract class that represents an algorithm
        used to perform the narrow phase of a collision detection. The
        goal of the narrow phase algorithm is to compute contact
        informations of a collision between two bodies.
    -------------------------------------------------------------------
*/
class NarrowPhaseAlgorithm {
    protected :
        CollisionDetection& collisionDetection;  // Reference to the collision detection object
        
    public :
        NarrowPhaseAlgorithm(CollisionDetection& collisionDetection);   // Constructor
        virtual ~NarrowPhaseAlgorithm();                                // Destructor

        virtual bool testCollision(const Shape* shape1, const Transform& transform1,
                                   const Shape* shape2, const Transform& transform2,
                                   ContactInfo*& contactInfo)=0;  // Return true and compute a contact info if the two bounding volume collide
};

} // End of reactphysics3d namespace

#endif


