/* Auto-generated by genmsg_cpp for file /projects/ros/surfer-main/lab3/Ref/msg/CurrentStatus.msg */
#ifndef REF_MESSAGE_CURRENTSTATUS_H
#define REF_MESSAGE_CURRENTSTATUS_H
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
#include "Ref/Position.h"
#include "Ref/Position.h"

namespace Ref
{
template <class ContainerAllocator>
struct CurrentStatus_ {
  typedef CurrentStatus_<ContainerAllocator> Type;

  CurrentStatus_()
  : header()
  , positions()
  , checkpoints()
  {
  }

  CurrentStatus_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , positions(_alloc)
  , checkpoints(_alloc)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef std::vector< ::Ref::Position_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::Ref::Position_<ContainerAllocator> >::other >  _positions_type;
  std::vector< ::Ref::Position_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::Ref::Position_<ContainerAllocator> >::other >  positions;

  typedef std::vector< ::Ref::Position_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::Ref::Position_<ContainerAllocator> >::other >  _checkpoints_type;
  std::vector< ::Ref::Position_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::Ref::Position_<ContainerAllocator> >::other >  checkpoints;


  typedef boost::shared_ptr< ::Ref::CurrentStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::Ref::CurrentStatus_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct CurrentStatus
typedef  ::Ref::CurrentStatus_<std::allocator<void> > CurrentStatus;

typedef boost::shared_ptr< ::Ref::CurrentStatus> CurrentStatusPtr;
typedef boost::shared_ptr< ::Ref::CurrentStatus const> CurrentStatusConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::Ref::CurrentStatus_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::Ref::CurrentStatus_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace Ref

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::Ref::CurrentStatus_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::Ref::CurrentStatus_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::Ref::CurrentStatus_<ContainerAllocator> > {
  static const char* value() 
  {
    return "6e45f36f38d7d698ab2f081fcb41b647";
  }

  static const char* value(const  ::Ref::CurrentStatus_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x6e45f36f38d7d698ULL;
  static const uint64_t static_value2 = 0xab2f081fcb41b647ULL;
};

template<class ContainerAllocator>
struct DataType< ::Ref::CurrentStatus_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Ref/CurrentStatus";
  }

  static const char* value(const  ::Ref::CurrentStatus_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::Ref::CurrentStatus_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
Position[] positions\n\
Position[] checkpoints\n\
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
================================================================================\n\
MSG: Ref/Position\n\
float32 x\n\
float32 y\n\
float32 rot\n\
\n\
";
  }

  static const char* value(const  ::Ref::CurrentStatus_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::Ref::CurrentStatus_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::Ref::CurrentStatus_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::Ref::CurrentStatus_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.positions);
    stream.next(m.checkpoints);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct CurrentStatus_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::Ref::CurrentStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::Ref::CurrentStatus_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "positions[]" << std::endl;
    for (size_t i = 0; i < v.positions.size(); ++i)
    {
      s << indent << "  positions[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::Ref::Position_<ContainerAllocator> >::stream(s, indent + "    ", v.positions[i]);
    }
    s << indent << "checkpoints[]" << std::endl;
    for (size_t i = 0; i < v.checkpoints.size(); ++i)
    {
      s << indent << "  checkpoints[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::Ref::Position_<ContainerAllocator> >::stream(s, indent + "    ", v.checkpoints[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // REF_MESSAGE_CURRENTSTATUS_H

