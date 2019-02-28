#ifndef FRAME_H
#define FREME_H
#include <Eigen/Core>
#include <Eigen/Geomety>
#include <include/Camera.h>
namespace 
{
class Frame
{
public:
    typedef std::shared_ptr<Frame> Ptr;
    unsigned long id_;
    double time_stamp_;
    Sophus::SE3 T_c_w;
    Camera::Ptr Camera_;
    Mat color_,depth_;
public:
    Frame();
    Frame(long id,double time_stamp=0,Sophus::SE3(),Camera::Ptr camera=nullptr,Mat color=Mat(),Mat depth=Mat());
    ~Frame();
    static Frame::Ptr createFrame();
    double findDepth(const cv::KeyPoint& kp);
    Eigen::Vector3d getCamCenter() const;
    bool isInFrame(const Eigen::Vector3d& pt_world);
};
}
#endif
