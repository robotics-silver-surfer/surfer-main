/* Auto-generated by genmsg_cpp for file /projects/ros/surfer-main/lab3/reactivecontrol/msg/Control.msg */
#ifndef REACTIVECONTROL_MESSAGE_CONTROL_H
#define REACTIVECONTROL_MESSAGE_CONTROL_H
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

namespace reactivecontrol
{
template <class ContainerAllocator>
struct Control_ {
  typedef Control_<ContainerAllocator> Type;

  Control_()
  : header()
  , state(0)
  {
  }

  Control_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , state(0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef uint8_t _state_type;
  uint8_t state;


  typedef boost::shared_ptr< ::reactivecontrol::Control_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::reactivecontrol::Control_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Control
typedef  ::reactivecontrol::Control_<std::allocator<void> > Control;

typedef boost::shared_ptr< ::reactivecontrol::Control> ControlPtr;
typedef boost::shared_ptr< ::reactivecontrol::Control const> ControlConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::reactivecontrol::Control_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::reactivecontrol::Control_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace reactivecontrol

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::reactivecontrol::Control_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::reactivecontrol::Control_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::reactivecontrol::Control_<ContainerAllocator> > {
  static const char* value() 
  {
    return "da95463f5af1db345e11ec4ce9b23d3f";
  }

  static const char* value(const  ::reactivecontrol::Control_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xda95463f5af1db34ULL;
  static const uint64_t static_value2 = 0x5e11ec4ce9b23d3fULL;
};

template<class ContainerAllocator>
struct DataType< ::reactivecontrol::Control_<ContainerAllocator> > {
  static const char* value() 
  {
    return "reactivecontrol/Control";
  }

  static const char* value(const  ::reactivecontrol::Control_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::reactivecontrol::Control_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
\n\
#Control state\n\
#  0 = manual\n\
#  1 = automatic\n\
#  2 = triangle\n\
uint8 state\n\
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

  static const char* value(const  ::reactivecontrol::Control_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::reactivecontrol::Control_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::reactivecontrol::Control_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::reactivecontrol::Control_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.state);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Control_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::reactivecontrol::Control_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::reactivecontrol::Control_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
  }
};


} // namespace message_operations
} // namespace ros

#endif // REACTIVECONTROL_MESSAGE_CONTROL_H

