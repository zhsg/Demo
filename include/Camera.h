#ifndef CAMERA_H
#define CAMERA_H
#include <Eigen/Core>
#include <Eigen/Geomety>
#include <opencv2/core/core.hpp>
#include <Sophus/se3.h>

namespace 
{
class Camera
{
    std::shred_ptr<Camera> Ptr;
    float fx_,fy_,cx_,cy_,depth_salce_;
    Camera();
    Camera(float fx,float fy,float cx,float cy,float depth_scale):fx_(fx),fy_(fy),cx_(cx),cy_(cy),depth_salce_(depth_scale)
    {}

    Eigen::Vector3d world2camera(const Eigen::Vector3d& p_w,const Sophus::SE3& T_c_w);
    Eigen::Vector3d camera2world(const Eigen::Vector3d& p_c,const Sophus::SE3& T_c_w);
    Eigen::Vector2d camera2pixel(const Eigen::Vector3d& p_c);
    Eigen::Vector3d pixel2camera(const Eigen::Vector2d& p_p,double depth=1);
    Eigen::Vector3d pixel2world(const Eigen::Vector2d& p_p,const Sophus::SE3& T_c_w,double depth=1);
    Eigen::Vector3d world2pixel(const Eigen::Vector3d& p_w,const Sophus::SE3& T_w_c);

};
}
#endif