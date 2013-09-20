/* Auto-generated by genmsg_cpp for file /projects/ros/surfer-main/lab1/hoverboard/msg/ServoRaw.msg */
#ifndef HOVERBOARD_MESSAGE_SERVORAW_H
#define HOVERBOARD_MESSAGE_SERVORAW_H
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
struct ServoRaw_ {
  typedef ServoRaw_<ContainerAllocator> Type;

  ServoRaw_()
  : header()
  , port(0)
  , value(0)
  {
  }

  ServoRaw_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , port(0)
  , value(0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef int8_t _port_type;
  int8_t port;

  typedef int8_t _value_type;
  int8_t value;


  typedef boost::shared_ptr< ::hoverboard::ServoRaw_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hoverboard::ServoRaw_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct ServoRaw
typedef  ::hoverboard::ServoRaw_<std::allocator<void> > ServoRaw;

typedef boost::shared_ptr< ::hoverboard::ServoRaw> ServoRawPtr;
typedef boost::shared_ptr< ::hoverboard::ServoRaw const> ServoRawConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::hoverboard::ServoRaw_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::hoverboard::ServoRaw_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace hoverboard

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hoverboard::ServoRaw_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hoverboard::ServoRaw_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hoverboard::ServoRaw_<ContainerAllocator> > {
  static const char* value() 
  {
    return "cf1c9d17f7bbedbe8dd2c29cdb7700f8";
  }

  static const char* value(const  ::hoverboard::ServoRaw_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xcf1c9d17f7bbedbeULL;
  static const uint64_t static_value2 = 0x8dd2c29cdb7700f8ULL;
};

template<class ContainerAllocator>
struct DataType< ::hoverboard::ServoRaw_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hoverboard/ServoRaw";
  }

  static const char* value(const  ::hoverboard::ServoRaw_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hoverboard::ServoRaw_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
\n\
# The servo port 0 through 5 inclusive\n\
int8 port\n\
# The value to send 0 to 100 inclusive\n\
int8 value\n\
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

  static const char* value(const  ::hoverboard::ServoRaw_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::hoverboard::ServoRaw_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::hoverboard::ServoRaw_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hoverboard::ServoRaw_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.port);
    stream.next(m.value);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct ServoRaw_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hoverboard::ServoRaw_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::hoverboard::ServoRaw_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "port: ";
    Printer<int8_t>::stream(s, indent + "  ", v.port);
    s << indent << "value: ";
    Printer<int8_t>::stream(s, indent + "  ", v.value);
  }
};


} // namespace message_operations
} // namespace ros

#endif // HOVERBOARD_MESSAGE_SERVORAW_H

