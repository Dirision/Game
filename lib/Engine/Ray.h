#ifndef RAY_H
#define RAY_H

#pragma once
#include <Eigen/Core>

struct Ray{
    Eigen::Vector3d origin;
    Eigen::Vector3d direction;
};

#endif