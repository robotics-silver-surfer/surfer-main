/* Auto-generated by genmsg_cpp for file /projects/ros/surfer-main/lab3/hoverboard/msg/GyroRaw.msg */
#ifndef HOVERBOARD_MESSAGE_GYRORAW_H
#define HOVERBOARD_MESSAGE_GYRORAW_H
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

namespace hoverboard
{
template <class ContainerAllocator>
struct GyroRaw_ {
  typedef GyroRaw_<ContainerAllocator> Type;

  GyroRaw_()
  : header()
  , angle(0)
  , rate(0)
  {
  }

  GyroRaw_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , angle(0)
  , rate(0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef int16_t _angle_type;
  int16_t angle;

  typedef int16_t _rate_type;
  int16_t rate;


  typedef boost::shared_ptr< ::hoverboard::GyroRaw_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hoverboard::GyroRaw_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct GyroRaw
typedef  ::hoverboard::GyroRaw_<std::allocator<void> > GyroRaw;

typedef boost::shared_ptr< ::hoverboard::GyroRaw> GyroRawPtr;
typedef boost::shared_ptr< ::hoverboard::GyroRaw const> GyroRawConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::hoverboard::GyroRaw_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::hoverboard::GyroRaw_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace hoverboard

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hoverboard::GyroRaw_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hoverboard::GyroRaw_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hoverboard::GyroRaw_<ContainerAllocator> > {
  static const char* value() 
  {
    return "cf76f9b1b2b3e94db06d36db0a223cd3";
  }

  static const char* value(const  ::hoverboard::GyroRaw_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xcf76f9b1b2b3e94dULL;
  static const uint64_t static_value2 = 0xb06d36db0a223cd3ULL;
};

template<class ContainerAllocator>
struct DataType< ::hoverboard::GyroRaw_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hoverboard/GyroRaw";
  }

  static const char* value(const  ::hoverboard::GyroRaw_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hoverboard::GyroRaw_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
\n\
# Gyro reported angle in degrees 0 to 360 degrees\n\
int16 angle\n\
# Gyro reported rate in degrees per second\n\
int16 rate\n\
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

  static const char* value(const  ::hoverboard::GyroRaw_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::hoverboard::GyroRaw_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::hoverboard::GyroRaw_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hoverboard::GyroRaw_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.angle);
    stream.next(m.rate);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct GyroRaw_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hoverboard::GyroRaw_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::hoverboard::GyroRaw_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "angle: ";
    Printer<int16_t>::stream(s, indent + "  ", v.angle);
    s << indent << "rate: ";
    Printer<int16_t>::stream(s, indent + "  ", v.rate);
  }
};


} // namespace message_operations
} // namespace ros

#endif // HOVERBOARD_MESSAGE_GYRORAW_H

