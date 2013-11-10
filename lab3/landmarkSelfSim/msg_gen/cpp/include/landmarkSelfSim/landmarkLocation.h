/* Auto-generated by genmsg_cpp for file /projects/ros/surfer-main/lab3/landmarkSelfSim/msg/landmarkLocation.msg */
#ifndef LANDMARKSELFSIM_MESSAGE_LANDMARKLOCATION_H
#define LANDMARKSELFSIM_MESSAGE_LANDMARKLOCATION_H
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

namespace landmarkSelfSim
{
template <class ContainerAllocator>
struct landmarkLocation_ {
  typedef landmarkLocation_<ContainerAllocator> Type;

  landmarkLocation_()
  : header()
  , xtop(0)
  , ytop(0)
  , xbottom(0)
  , ybottom(0)
  , height(0.0)
  , code(0)
  {
  }

  landmarkLocation_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , xtop(0)
  , ytop(0)
  , xbottom(0)
  , ybottom(0)
  , height(0.0)
  , code(0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef int32_t _xtop_type;
  int32_t xtop;

  typedef int32_t _ytop_type;
  int32_t ytop;

  typedef int32_t _xbottom_type;
  int32_t xbottom;

  typedef int32_t _ybottom_type;
  int32_t ybottom;

  typedef double _height_type;
  double height;

  typedef int32_t _code_type;
  int32_t code;


  typedef boost::shared_ptr< ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::landmarkSelfSim::landmarkLocation_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct landmarkLocation
typedef  ::landmarkSelfSim::landmarkLocation_<std::allocator<void> > landmarkLocation;

typedef boost::shared_ptr< ::landmarkSelfSim::landmarkLocation> landmarkLocationPtr;
typedef boost::shared_ptr< ::landmarkSelfSim::landmarkLocation const> landmarkLocationConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace landmarkSelfSim

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::landmarkSelfSim::landmarkLocation_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> > {
  static const char* value() 
  {
    return "5fff4f104cc29dd1741797346a6aa89e";
  }

  static const char* value(const  ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x5fff4f104cc29dd1ULL;
  static const uint64_t static_value2 = 0x741797346a6aa89eULL;
};

template<class ContainerAllocator>
struct DataType< ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> > {
  static const char* value() 
  {
    return "landmarkSelfSim/landmarkLocation";
  }

  static const char* value(const  ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
\n\
# The x,y location of the top and bottom point of the detected landmark.\n\
int32 xtop\n\
int32 ytop\n\
int32 xbottom\n\
int32 ybottom\n\
\n\
# Height of the landmark as computed as the distance between the top\n\
# and bottom points.\n\
float64 height\n\
\n\
# The landmark code id number which should can range from 0 to 255.  If\n\
# this is -1 then it means the code was not correctly read (and the\n\
# above points may not be accurate).\n\
int32 code\n\
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

  static const char* value(const  ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.xtop);
    stream.next(m.ytop);
    stream.next(m.xbottom);
    stream.next(m.ybottom);
    stream.next(m.height);
    stream.next(m.code);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct landmarkLocation_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::landmarkSelfSim::landmarkLocation_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "xtop: ";
    Printer<int32_t>::stream(s, indent + "  ", v.xtop);
    s << indent << "ytop: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ytop);
    s << indent << "xbottom: ";
    Printer<int32_t>::stream(s, indent + "  ", v.xbottom);
    s << indent << "ybottom: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ybottom);
    s << indent << "height: ";
    Printer<double>::stream(s, indent + "  ", v.height);
    s << indent << "code: ";
    Printer<int32_t>::stream(s, indent + "  ", v.code);
  }
};


} // namespace message_operations
} // namespace ros

#endif // LANDMARKSELFSIM_MESSAGE_LANDMARKLOCATION_H

