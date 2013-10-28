/* Auto-generated by genmsg_cpp for file /home/courtney/groovy_ws/projects/ros/surfer-main/lab3/hoverboard/msg/ThrusterRaw.msg */
#ifndef HOVERBOARD_MESSAGE_THRUSTERRAW_H
#define HOVERBOARD_MESSAGE_THRUSTERRAW_H
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
struct ThrusterRaw_ {
  typedef ThrusterRaw_<ContainerAllocator> Type;

  ThrusterRaw_()
  : header()
  , thruster1(0)
  , thruster2(0)
  , thruster3(0)
  , thruster4(0)
  , thruster5(0)
  , thruster6(0)
  {
  }

  ThrusterRaw_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , thruster1(0)
  , thruster2(0)
  , thruster3(0)
  , thruster4(0)
  , thruster5(0)
  , thruster6(0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef uint8_t _thruster1_type;
  uint8_t thruster1;

  typedef uint8_t _thruster2_type;
  uint8_t thruster2;

  typedef uint8_t _thruster3_type;
  uint8_t thruster3;

  typedef uint8_t _thruster4_type;
  uint8_t thruster4;

  typedef uint8_t _thruster5_type;
  uint8_t thruster5;

  typedef uint8_t _thruster6_type;
  uint8_t thruster6;


  typedef boost::shared_ptr< ::hoverboard::ThrusterRaw_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hoverboard::ThrusterRaw_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct ThrusterRaw
typedef  ::hoverboard::ThrusterRaw_<std::allocator<void> > ThrusterRaw;

typedef boost::shared_ptr< ::hoverboard::ThrusterRaw> ThrusterRawPtr;
typedef boost::shared_ptr< ::hoverboard::ThrusterRaw const> ThrusterRawConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::hoverboard::ThrusterRaw_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::hoverboard::ThrusterRaw_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace hoverboard

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hoverboard::ThrusterRaw_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hoverboard::ThrusterRaw_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hoverboard::ThrusterRaw_<ContainerAllocator> > {
  static const char* value() 
  {
    return "d5ca7d3885d46960c93d211bf90a9632";
  }

  static const char* value(const  ::hoverboard::ThrusterRaw_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xd5ca7d3885d46960ULL;
  static const uint64_t static_value2 = 0xc93d211bf90a9632ULL;
};

template<class ContainerAllocator>
struct DataType< ::hoverboard::ThrusterRaw_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hoverboard/ThrusterRaw";
  }

  static const char* value(const  ::hoverboard::ThrusterRaw_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hoverboard::ThrusterRaw_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
\n\
#Setpoints for the thrusters 0 off, 255 max\n\
uint8 thruster1\n\
uint8 thruster2\n\
uint8 thruster3\n\
uint8 thruster4\n\
uint8 thruster5\n\
uint8 thruster6\n\
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

  static const char* value(const  ::hoverboard::ThrusterRaw_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::hoverboard::ThrusterRaw_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::hoverboard::ThrusterRaw_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hoverboard::ThrusterRaw_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.thruster1);
    stream.next(m.thruster2);
    stream.next(m.thruster3);
    stream.next(m.thruster4);
    stream.next(m.thruster5);
    stream.next(m.thruster6);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct ThrusterRaw_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hoverboard::ThrusterRaw_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::hoverboard::ThrusterRaw_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "thruster1: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.thruster1);
    s << indent << "thruster2: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.thruster2);
    s << indent << "thruster3: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.thruster3);
    s << indent << "thruster4: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.thruster4);
    s << indent << "thruster5: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.thruster5);
    s << indent << "thruster6: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.thruster6);
  }
};


} // namespace message_operations
} // namespace ros

#endif // HOVERBOARD_MESSAGE_THRUSTERRAW_H

