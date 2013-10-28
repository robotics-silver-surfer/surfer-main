/* Auto-generated by genmsg_cpp for file /home/courtney/groovy_ws/projects/ros/surfer-main/lab3/reactivecontrol/msg/IRdistance.msg */
#ifndef REACTIVECONTROL_MESSAGE_IRDISTANCE_H
#define REACTIVECONTROL_MESSAGE_IRDISTANCE_H
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
struct IRdistance_ {
  typedef IRdistance_<ContainerAllocator> Type;

  IRdistance_()
  : header()
  , IR1(0.0)
  , IR2(0.0)
  {
  }

  IRdistance_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , IR1(0.0)
  , IR2(0.0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef double _IR1_type;
  double IR1;

  typedef double _IR2_type;
  double IR2;


  typedef boost::shared_ptr< ::reactivecontrol::IRdistance_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::reactivecontrol::IRdistance_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct IRdistance
typedef  ::reactivecontrol::IRdistance_<std::allocator<void> > IRdistance;

typedef boost::shared_ptr< ::reactivecontrol::IRdistance> IRdistancePtr;
typedef boost::shared_ptr< ::reactivecontrol::IRdistance const> IRdistanceConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::reactivecontrol::IRdistance_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::reactivecontrol::IRdistance_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace reactivecontrol

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::reactivecontrol::IRdistance_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::reactivecontrol::IRdistance_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::reactivecontrol::IRdistance_<ContainerAllocator> > {
  static const char* value() 
  {
    return "2fb8c917f4e8d8ed20f3f1a673aff4cf";
  }

  static const char* value(const  ::reactivecontrol::IRdistance_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x2fb8c917f4e8d8edULL;
  static const uint64_t static_value2 = 0x20f3f1a673aff4cfULL;
};

template<class ContainerAllocator>
struct DataType< ::reactivecontrol::IRdistance_<ContainerAllocator> > {
  static const char* value() 
  {
    return "reactivecontrol/IRdistance";
  }

  static const char* value(const  ::reactivecontrol::IRdistance_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::reactivecontrol::IRdistance_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
\n\
#Value in cm of IR\n\
float64 IR1\n\
float64 IR2\n\
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

  static const char* value(const  ::reactivecontrol::IRdistance_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::reactivecontrol::IRdistance_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::reactivecontrol::IRdistance_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::reactivecontrol::IRdistance_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.IR1);
    stream.next(m.IR2);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct IRdistance_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::reactivecontrol::IRdistance_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::reactivecontrol::IRdistance_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "IR1: ";
    Printer<double>::stream(s, indent + "  ", v.IR1);
    s << indent << "IR2: ";
    Printer<double>::stream(s, indent + "  ", v.IR2);
  }
};


} // namespace message_operations
} // namespace ros

#endif // REACTIVECONTROL_MESSAGE_IRDISTANCE_H

