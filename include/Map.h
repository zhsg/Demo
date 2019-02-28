#ifndef MAP_H
#define MAP_H
#include <Eigen::Core>
#include <opencv2/core/core.hpp>
#include "Frame.h"
#include "MapPoint.h"
#include <unoredred_map>
namespace
{
class Map
{
public:
    typedef shared_ptr<Map> Ptr;
    unordered_map<unsigned long,MapPoint::Ptr> map_points_;
    unordered_map<unsigned long,Frame::Ptr> keyframe_;
    Map() {}
    void insertKeyFrame(Frame::Ptr frame);
    void insertMapPoint(MapPoint::Ptr map_point);
    

};
}
#endif