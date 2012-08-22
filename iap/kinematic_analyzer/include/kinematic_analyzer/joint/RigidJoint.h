/* * IAP - Interactive Perception System - Segment visually observable environment
 * into rigid bodies and estimate type and properties of joints between them by
 * means of interaction.
 * Copyright (C) 2012 Technische Universitaet Berlin - RBO
 * <robotics@robotics.tu-berlin.de>
 * 
 * This file is part of IAP.
 * 
 * IAP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * IAP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with IAP.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
 * RigidJoint.h
 *
 *  Created on: Apr 19, 2012
 *      Author: roberto
 */

#ifndef RIGIDJOINT_H_
#define RIGIDJOINT_H_

#include "Joint.h"

class RigidJoint;
typedef boost::shared_ptr<RigidJoint> RigidJointPtr;

class RigidJoint : virtual public Joint
{
public:
  RigidJoint();
  RigidJoint(const RigidJoint& pj);
  virtual ~RigidJoint();

  /**
   * Get the type of Joint
   * @return - Type of joint
   */
  virtual JointType getType() const;

  /**
   * Get the type of Joint as an std::string
   * @return - String with the name of the joint type
   */
  virtual std::string getTypeStr() const;

  /**
   * Clone the whole object and return a copy
   * @return - Clone of the Joint
   */
  RigidJointPtr clone() const;

  /**
   * Transform this object into a ROS message
   */
  virtual iap_common::JointMsg toROSMsg();

  /**
   * Get the maximum deviation in radians from the orientation, based on the covariance of the measurement
   * To be redefined in some derived classes (prismatic and revolute)
   * @return - Standard deviation in radians
   */
  virtual double getJointPositionUncertainty() const
  {
    return MINIMUM_STD_DEV;
  };

  /**
   * Get the maximum deviation in radians from the orientation, based on the covariance of the measurement
   * @return - Standard deviation in radians
   */
  virtual double getJointOrientationUncertainty() const
  {
    return MINIMUM_STD_DEV;
  };

protected:
  virtual RigidJoint* doClone() const = 0;
};

#endif /* RIGIDJOINT_H_ */