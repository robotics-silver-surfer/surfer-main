/* Auto-generated by genmsg_cpp for file /projects/ros/surfer-main/lab3/ballDetector/msg/debugTimes.msg */
#ifndef BALLDETECTOR_MESSAGE_DEBUGTIMES_H
#define BALLDETECTOR_MESSAGE_DEBUGTIMES_H
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
struct debugTimes_ {
  typedef debugTimes_<ContainerAllocator> Type;

  debugTimes_()
  : header()
  , labels()
  , times()
  {
  }

  debugTimes_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , labels(_alloc)
  , times(_alloc)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _labels_type;
  std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  labels;

  typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _times_type;
  std::vector<double, typename ContainerAllocator::template rebind<double>::other >  times;


  typedef boost::shared_ptr< ::ballDetector::debugTimes_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ballDetector::debugTimes_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct debugTimes
typedef  ::ballDetector::debugTimes_<std::allocator<void> > debugTimes;

typedef boost::shared_ptr< ::ballDetector::debugTimes> debugTimesPtr;
typedef boost::shared_ptr< ::ballDetector::debugTimes const> debugTimesConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::ballDetector::debugTimes_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::ballDetector::debugTimes_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace ballDetector

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::ballDetector::debugTimes_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::ballDetector::debugTimes_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::ballDetector::debugTimes_<ContainerAllocator> > {
  static const char* value() 
  {
    return "24f9f017187aacc6186ce1f2d40d694e";
  }

  static const char* value(const  ::ballDetector::debugTimes_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x24f9f017187aacc6ULL;
  static const uint64_t static_value2 = 0x186ce1f2d40d694eULL;
};

template<class ContainerAllocator>
struct DataType< ::ballDetector::debugTimes_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ballDetector/debugTimes";
  }

  static const char* value(const  ::ballDetector::debugTimes_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::ballDetector::debugTimes_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
#string identifying the corresponding element time \n\
string[] labels\n\
#the execution time in seconds\n\
float64[] times\n\
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

  static const char* value(const  ::ballDetector::debugTimes_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::ballDetector::debugTimes_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::ballDetector::debugTimes_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::ballDetector::debugTimes_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.labels);
    stream.next(m.times);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct debugTimes_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ballDetector::debugTimes_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::ballDetector::debugTimes_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "labels[]" << std::endl;
    for (size_t i = 0; i < v.labels.size(); ++i)
    {
      s << indent << "  labels[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.labels[i]);
    }
    s << indent << "times[]" << std::endl;
    for (size_t i = 0; i < v.times.size(); ++i)
    {
      s << indent << "  times[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.times[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // BALLDETECTOR_MESSAGE_DEBUGTIMES_H

