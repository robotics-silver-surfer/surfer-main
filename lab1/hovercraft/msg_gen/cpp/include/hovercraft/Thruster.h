/* Auto-generated by genmsg_cpp for file /projects/ros/surfer-main/lab1/hovercraft/msg/Thruster.msg */
#ifndef HOVERCRAFT_MESSAGE_THRUSTER_H
#define HOVERCRAFT_MESSAGE_THRUSTER_H
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

namespace hovercraft
{
template <class ContainerAllocator>
struct Thruster_ {
  typedef Thruster_<ContainerAllocator> Type;

  Thruster_()
  : header()
  , lift(0.0)
  , thruster1(0.0)
  , thruster2(0.0)
  , thruster3(0.0)
  , thruster4(0.0)
  , thruster5(0.0)
  , thruster6(0.0)
  {
  }

  Thruster_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , lift(0.0)
  , thruster1(0.0)
  , thruster2(0.0)
  , thruster3(0.0)
  , thruster4(0.0)
  , thruster5(0.0)
  , thruster6(0.0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef double _lift_type;
  double lift;

  typedef double _thruster1_type;
  double thruster1;

  typedef double _thruster2_type;
  double thruster2;

  typedef double _thruster3_type;
  double thruster3;

  typedef double _thruster4_type;
  double thruster4;

  typedef double _thruster5_type;
  double thruster5;

  typedef double _thruster6_type;
  double thruster6;


  typedef boost::shared_ptr< ::hovercraft::Thruster_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hovercraft::Thruster_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Thruster
typedef  ::hovercraft::Thruster_<std::allocator<void> > Thruster;

typedef boost::shared_ptr< ::hovercraft::Thruster> ThrusterPtr;
typedef boost::shared_ptr< ::hovercraft::Thruster const> ThrusterConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::hovercraft::Thruster_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::hovercraft::Thruster_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace hovercraft

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hovercraft::Thruster_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hovercraft::Thruster_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hovercraft::Thruster_<ContainerAllocator> > {
  static const char* value() 
  {
    return "77ae7c2ac5b2374a7cf656a5602268c6";
  }

  static const char* value(const  ::hovercraft::Thruster_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x77ae7c2ac5b2374aULL;
  static const uint64_t static_value2 = 0x7cf656a5602268c6ULL;
};

template<class ContainerAllocator>
struct DataType< ::hovercraft::Thruster_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hovercraft/Thruster";
  }

  static const char* value(const  ::hovercraft::Thruster_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hovercraft::Thruster_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
\n\
#Setpoints for the thrusters 0.0 off, 1.0 max\n\
float64 lift\n\
float64 thruster1\n\
float64 thruster2\n\
float64 thruster3\n\
float64 thruster4\n\
float64 thruster5\n\
float64 thruster6\n\
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

  static const char* value(const  ::hovercraft::Thruster_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::hovercraft::Thruster_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::hovercraft::Thruster_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hovercraft::Thruster_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.lift);
    stream.next(m.thruster1);
    stream.next(m.thruster2);
    stream.next(m.thruster3);
    stream.next(m.thruster4);
    stream.next(m.thruster5);
    stream.next(m.thruster6);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Thruster_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hovercraft::Thruster_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::hovercraft::Thruster_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "lift: ";
    Printer<double>::stream(s, indent + "  ", v.lift);
    s << indent << "thruster1: ";
    Printer<double>::stream(s, indent + "  ", v.thruster1);
    s << indent << "thruster2: ";
    Printer<double>::stream(s, indent + "  ", v.thruster2);
    s << indent << "thruster3: ";
    Printer<double>::stream(s, indent + "  ", v.thruster3);
    s << indent << "thruster4: ";
    Printer<double>::stream(s, indent + "  ", v.thruster4);
    s << indent << "thruster5: ";
    Printer<double>::stream(s, indent + "  ", v.thruster5);
    s << indent << "thruster6: ";
    Printer<double>::stream(s, indent + "  ", v.thruster6);
  }
};


} // namespace message_operations
} // namespace ros

#endif // HOVERCRAFT_MESSAGE_THRUSTER_H

