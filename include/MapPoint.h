#ifndef MAPPOINT_H
#define MAPPOINT_H
#include "include/Camera.h"
#include "include/Frame.h"
#include <Eigen/Core>
#include <opencv2/core.hpp>
namespace
{
class Frame;
class MapPoint
{
public:
    typedef shared_ptr<MapPoint> Ptr;
    unsigned long id_;
    Vector3d pos_;
    Vector3d norm_;
    Mat descriptor;
    int observed_times;
    int correct_times;
    MapPoint();
    MapPoint(long id,Vector3d position,Vector3d norm);
    static MapPoint::Ptr createMapPoint();

};
}
#endif