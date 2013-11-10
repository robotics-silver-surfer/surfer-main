/* Auto-generated by genmsg_cpp for file /projects/ros/surfer-main/lab3/ballDetector/msg/ballLocation.msg */
#ifndef BALLDETECTOR_MESSAGE_BALLLOCATION_H
#define BALLDETECTOR_MESSAGE_BALLLOCATION_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"

namespace ballDetector
{
template <class ContainerAllocator>
struct ballLocation_ {
  typedef ballLocation_<ContainerAllocator> Type;

  ballLocation_()
  : header()
  , imageWidth(0)
  , imageHeight(0)
  , x(0.0)
  , y(0.0)
  , radius(0.0)
  {
  }

  ballLocation_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , imageWidth(0)
  , imageHeight(0)
  , x(0.0)
  , y(0.0)
  , radius(0.0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef uint32_t _imageWidth_type;
  uint32_t imageWidth;

  typedef uint32_t _imageHeight_type;
  uint32_t imageHeight;

  typedef double _x_type;
  double x;

  typedef double _y_type;
  double y;

  typedef double _radius_type;
  double radius;


  typedef boost::shared_ptr< ::ballDetector::ballLocation_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ballDetector::ballLocation_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct ballLocation
typedef  ::ballDetector::ballLocation_<std::allocator<void> > ballLocation;

typedef boost::shared_ptr< ::ballDetector::ballLocation> ballLocationPtr;
typedef boost::shared_ptr< ::ballDetector::ballLocation const> ballLocationConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::ballDetector::ballLocation_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::ballDetector::ballLocation_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace ballDetector

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::ballDetector::ballLocation_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::ballDetector::ballLocation_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::ballDetector::ballLocation_<ContainerAllocator> > {
  static const char* value() 
  {
    return "046f798a75776068674c89e287314673";
  }

  static const char* value(const  ::ballDetector::ballLocation_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x046f798a75776068ULL;
  static const uint64_t static_value2 = 0x674c89e287314673ULL;
};

template<class ContainerAllocator>
struct DataType< ::ballDetector::ballLocation_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ballDetector/ballLocation";
  }

  static const char* value(const  ::ballDetector::ballLocation_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::ballDetector::ballLocation_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
#The iamge width and height in pixels\n\
uint32 imageWidth\n\
uint32 imageHeight\n\
\n\
#The location of the ball center in x,y (width,height)\n\
float64 x\n\
float64 y\n\
#The radius of the detected ball\n\
float64 radius\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::ballDetector::ballLocation_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::ballDetector::ballLocation_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::ballDetector::ballLocation_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::ballDetector::ballLocation_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.imageWidth);
    stream.next(m.imageHeight);
    stream.next(m.x);
    stream.next(m.y);
    stream.next(m.radius);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct ballLocation_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ballDetector::ballLocation_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::ballDetector::ballLocation_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "imageWidth: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.imageWidth);
    s << indent << "imageHeight: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.imageHeight);
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "radius: ";
    Printer<double>::stream(s, indent + "  ", v.radius);
  }
};


} // namespace message_operations
} // namespace ros

#endif // BALLDETECTOR_MESSAGE_BALLLOCATION_H

